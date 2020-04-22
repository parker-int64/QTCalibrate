#include "calibration.h"

double calibrate::computeReprojectionErrors(
        const vector<vector<Point3f> >& objectPoints,
        const vector<vector<Point2f> >& imagePoints,
        const vector<Mat>& rvecs, const vector<Mat>& tvecs,
        const Mat& cameraMatrix, const Mat& distCoeffs,
        vector<float>& perViewErrors )
{
    vector<Point2f> imagePoints2;
    int i, totalPoints = 0;
    double totalErr = 0, err;
    perViewErrors.resize(objectPoints.size());

    for( i = 0; i < (int)objectPoints.size(); i++ )
    {
        projectPoints(Mat(objectPoints[i]), rvecs[i], tvecs[i],
                      cameraMatrix, distCoeffs, imagePoints2);
        err = norm(Mat(imagePoints[i]), Mat(imagePoints2), NORM_L2);
        int n = (int)objectPoints[i].size();
        perViewErrors[i] = (float)std::sqrt(err*err/n);
        totalErr += err*err;
        totalPoints += n;
    }

    return std::sqrt(totalErr/totalPoints);
}

void calibrate::calcChessboardCorners(Size boardSize, float squareSize, vector<Point3f>& corners, Pattern patternType = CHESSBOARD)
{
    corners.resize(0);

    switch(patternType)
    {
      case CHESSBOARD:
      case CIRCLES_GRID:
        for( int i = 0; i < boardSize.height; i++ )
            for( int j = 0; j < boardSize.width; j++ )
                corners.push_back(Point3f(float(j*squareSize),
                                          float(i*squareSize), 0));
        break;

      case ASYMMETRIC_CIRCLES_GRID:
        for( int i = 0; i < boardSize.height; i++ )
            for( int j = 0; j < boardSize.width; j++ )
                corners.push_back(Point3f(float((2*j + i % 2)*squareSize),
                                          float(i*squareSize), 0));
        break;

      default:
        CV_Error(Error::StsBadArg, "Unknown pattern type\n");
    }
}

bool calibrate::runCalibration( vector<vector<Point2f> > imagePoints,
                    Size imageSize, Size boardSize, Pattern patternType,
                    float squareSize, float aspectRatio,
                    float grid_width, bool release_object,
                    int flags, Mat& cameraMatrix, Mat& distCoeffs,
                    vector<Mat>& rvecs, vector<Mat>& tvecs,
                    vector<float>& reprojErrs,
                    vector<Point3f>& newObjPoints,
                    double& totalAvgErr)
{
    cameraMatrix = Mat::eye(3, 3, CV_64F);
    if( flags & CALIB_FIX_ASPECT_RATIO )
        cameraMatrix.at<double>(0,0) = aspectRatio;

    distCoeffs = Mat::zeros(8, 1, CV_64F);

    vector<vector<Point3f> > objectPoints(1);
    calcChessboardCorners(boardSize, squareSize, objectPoints[0], patternType);
    objectPoints[0][boardSize.width - 1].x = objectPoints[0][0].x + grid_width;
    newObjPoints = objectPoints[0];

    objectPoints.resize(imagePoints.size(),objectPoints[0]);

    double rms;
    int iFixedPoint = -1;
    if (release_object)
        iFixedPoint = boardSize.width - 1;
    rms = calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint,
                            cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints,
                            flags | CALIB_FIX_K3 | CALIB_USE_LU);
    QString rmsStatus;
    rmsStatus.asprintf("RMS error reported by calibrateCamera: %g\n",rms);
    window->textOutput(rmsStatus);

    bool ok = checkRange(cameraMatrix) && checkRange(distCoeffs);

    if (release_object) {
        QString releaseStatus;
        releaseStatus.asprintf("New board corners:\n"
                               "[ %.2f, %.2f, %.2f]\n"
                               "[ %.2f, %.2f, %.2f]\n"
                               "[ %.2f, %.2f, %.2f]\n"
                               "[ %.2f, %.2f, %.2f]\n"
                               ,newObjPoints[0].x,newObjPoints[0].y,newObjPoints[0].z,
                                newObjPoints[boardSize.width - 1].x,
                                newObjPoints[boardSize.width - 1].y,
                                newObjPoints[boardSize.width - 1].z,
                                newObjPoints[boardSize.width * (boardSize.height - 1)].x,
                                newObjPoints[boardSize.width * (boardSize.height - 1)].y,
                                newObjPoints[boardSize.width * (boardSize.height - 1)].z,
                                newObjPoints.back().x,
                                newObjPoints.back().y,
                                newObjPoints.back().z);
        window->textOutput(releaseStatus);
    }

    objectPoints.clear();
    objectPoints.resize(imagePoints.size(), newObjPoints);
    totalAvgErr = computeReprojectionErrors(objectPoints, imagePoints,
                rvecs, tvecs, cameraMatrix, distCoeffs, reprojErrs);

    return ok;
}


void calibrate::saveCameraParams( const string& filename,
                       Size imageSize, Size boardSize,
                       float squareSize, float aspectRatio, int flags,
                       const Mat& cameraMatrix, const Mat& distCoeffs,
                       const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                       const vector<float>& reprojErrs,
                       const vector<vector<Point2f> >& imagePoints,
                       const vector<Point3f>& newObjPoints,
                       double totalAvgErr )
{
    FileStorage fs( filename, FileStorage::WRITE );

    time_t tt;
    time( &tt );
    struct tm *t2 = localtime( &tt );
    char buf[1024];
    strftime( buf, sizeof(buf)-1, "%c", t2 );

    fs << "calibration_time" << buf;

    if( !rvecs.empty() || !reprojErrs.empty() )
        fs << "nframes" << (int)std::max(rvecs.size(), reprojErrs.size());
    fs << "image_width" << imageSize.width;
    fs << "image_height" << imageSize.height;
    fs << "board_width" << boardSize.width;
    fs << "board_height" << boardSize.height;
    fs << "square_size" << squareSize;

    if( flags & CALIB_FIX_ASPECT_RATIO )
        fs << "aspectRatio" << aspectRatio;

    if( flags != 0 )
    {
        sprintf( buf, "flags: %s%s%s%s",
            flags & CALIB_USE_INTRINSIC_GUESS ? "+use_intrinsic_guess" : "",
            flags & CALIB_FIX_ASPECT_RATIO ? "+fix_aspectRatio" : "",
            flags & CALIB_FIX_PRINCIPAL_POINT ? "+fix_principal_point" : "",
            flags & CALIB_ZERO_TANGENT_DIST ? "+zero_tangent_dist" : "" );
    }

    fs << "flags" << flags;

    fs << "camera_matrix" << cameraMatrix;
    fs << "distortion_coefficients" << distCoeffs;

    fs << "avg_reprojection_error" << totalAvgErr;
    if( !reprojErrs.empty() )
        fs << "per_view_reprojection_errors" << Mat(reprojErrs);

    if( !rvecs.empty() && !tvecs.empty() )
    {
        CV_Assert(rvecs[0].type() == tvecs[0].type());
        Mat bigmat((int)rvecs.size(), 6, rvecs[0].type());
        for( int i = 0; i < (int)rvecs.size(); i++ )
        {
            Mat r = bigmat(Range(i, i+1), Range(0,3));
            Mat t = bigmat(Range(i, i+1), Range(3,6));

            CV_Assert(rvecs[i].rows == 3 && rvecs[i].cols == 1);
            CV_Assert(tvecs[i].rows == 3 && tvecs[i].cols == 1);
            //*.t() is MatExpr (not Mat) so we can use assignment operator
            r = rvecs[i].t();
            t = tvecs[i].t();
        }
        //cvWriteComment( *fs, "a set of 6-tuples (rotation vector + translation vector) for each view", 0 );
        fs << "extrinsic_parameters" << bigmat;
    }

    if( !imagePoints.empty() )
    {
        Mat imagePtMat((int)imagePoints.size(), (int)imagePoints[0].size(), CV_32FC2);
        for( int i = 0; i < (int)imagePoints.size(); i++ )
        {
            Mat r = imagePtMat.row(i).reshape(2, imagePtMat.cols);
            Mat imgpti(imagePoints[i]);
            imgpti.copyTo(r);
        }
        fs << "image_points" << imagePtMat;
    }

    if( !newObjPoints.empty() )
    {
        fs << "grid_points" << newObjPoints;
    }
}

bool calibrate::readStringList( const string& filename, vector<string>& l )
{
    l.resize(0);
    FileStorage fs(filename, FileStorage::READ);
    if( !fs.isOpened() )
        return false;
    size_t dir_pos = filename.rfind('/');
    if (dir_pos == string::npos)
        dir_pos = filename.rfind('\\');
    FileNode n = fs.getFirstTopLevelNode();
    if( n.type() != FileNode::SEQ )
        return false;
    FileNodeIterator it = n.begin(), it_end = n.end();
    for( ; it != it_end; ++it )
    {
        string fname = (string)*it;
        if (dir_pos != string::npos)
        {
            string fpath = samples::findFile(filename.substr(0, dir_pos + 1) + fname, false);
            if (fpath.empty())
            {
                fpath = samples::findFile(fname);
            }
            fname = fpath;
        }
        else
        {
            fname = samples::findFile(fname);
        }
        l.push_back(fname);
    }
    return true;
}


bool calibrate::runAndSave(const string& outputFilename,
                const vector<vector<Point2f> >& imagePoints,
                Size imageSize, Size boardSize, Pattern patternType, float squareSize,
                float grid_width, bool release_object,
                float aspectRatio, int flags, Mat& cameraMatrix,
                Mat& distCoeffs, bool writeExtrinsics, bool writePoints, bool writeGrid )
{
    vector<Mat> rvecs, tvecs;
    vector<float> reprojErrs;
    double totalAvgErr = 0;
    vector<Point3f> newObjPoints;

    bool ok = runCalibration(imagePoints, imageSize, boardSize, patternType, squareSize,
                   aspectRatio, grid_width, release_object, flags, cameraMatrix, distCoeffs,
                   rvecs, tvecs, reprojErrs, newObjPoints, totalAvgErr);
    QString calibrateStatus;
    calibrateStatus.asprintf("%s. avg reprojection error = %.7f\n",
                             ok ? "Calibration succeeded" : "Calibration failed",
                             totalAvgErr);
    window->textOutput(calibrateStatus);
    if( ok )
        saveCameraParams( outputFilename, imageSize,
                         boardSize, squareSize, aspectRatio,
                         flags, cameraMatrix, distCoeffs,
                         writeExtrinsics ? rvecs : vector<Mat>(),
                         writeExtrinsics ? tvecs : vector<Mat>(),
                         writeExtrinsics ? reprojErrs : vector<float>(),
                         writePoints ? imagePoints : vector<vector<Point2f> >(),
                         writeGrid ? newObjPoints : vector<Point3f>(),
                         totalAvgErr );
    return ok;
}


int calibrate::calibMain(int chessBoardWidth,int chessBoardHeight,
                         int calibPattern,double chessBoardSize,
                         int numOfFrames,int delayInFrames,bool writeDetectedFeaturePoints,
                         bool writeExtrinsicParameters,bool writeRefined3DObjectPoints,
                         double fixAspectRatio,bool assumeZeroTangentialDistortion,
                         bool fixThePrincipalPoint,
                         bool flipTheCapturedImages,QString outputPath,
                         bool showUndistortedImages,
                         bool enableVideoFile, int cameraIndex,
                         int halfSearchWinSize,double actualDistance){
//    window = new MainWindow;    // Implemention
    Size boardSize, imageSize;
    float squareSize, aspectRatio = 1;
    Mat cameraMatrix, distCoeffs;
    string outputFilename;
    string inputFilename;
    int i, nframes;
    bool writeExtrinsics, writePoints = false;
    bool undistortImage = false;
    int flags = 0;
    VideoCapture capture;
    bool flipVertical = false;
    bool showUndistorted = false;
    bool videofile;
    int delay;
    clock_t prevTimestamp = 0;
    int mode = DETECTION;
    int cameraId = 0;
    vector<vector<Point2f> > imagePoints;
    vector<string> imageList;
    Pattern pattern = CHESSBOARD;
    int winSize;

    boardSize.width  = chessBoardWidth;
    boardSize.height = chessBoardHeight;

    if(calibPattern == 0)     pattern = CHESSBOARD;
    else if(calibPattern == 1)pattern = CIRCLES_GRID;
    else if(calibPattern == 2)pattern = ASYMMETRIC_CIRCLES_GRID;

    if(chessBoardSize != 0.)squareSize = chessBoardSize;

    nframes = numOfFrames;

    delay = delayInFrames;

    writePoints = writeDetectedFeaturePoints;

    writeExtrinsics = writeExtrinsicParameters;

    bool writeGrid = writeRefined3DObjectPoints;

    if(fixAspectRatio != 0.){
        flags |= CALIB_FIX_ASPECT_RATIO;
        aspectRatio = fixAspectRatio;
    }

    if(assumeZeroTangentialDistortion)flags |= CALIB_ZERO_TANGENT_DIST;
    if(fixThePrincipalPoint)flags |= CALIB_FIX_PRINCIPAL_POINT;

    flipVertical = flipTheCapturedImages;

    if(outputPath != "")outputFilename = outputPath.toLocal8Bit().toStdString();
    else outputFilename = "../data/camera.yml";

    showUndistortedImages = showUndistorted;

    inputFilename = "../data/imageList.yml";

    videofile = enableVideoFile;

    cameraId = cameraIndex;

    if(halfSearchWinSize != 0)winSize = halfSearchWinSize;

    float grid_width = squareSize * (boardSize.width - 1);

    bool release_object = false;

    if(actualDistance != 0.){
        grid_width = actualDistance;
        release_object = true;
    }



    // some key factors

    if ( squareSize <= 0 )
        return window->textOutput("ERROR:Invalid board square width\n"),-1;
    if ( nframes <= 3 )
        return window->textOutput("ERROR:Invalid number of images\n"),-1;
    if ( aspectRatio <= 0 )
        return window->textOutput("ERROR:Invalid aspect ratio\n"),-1;
    if ( delay <= 0 )
        return window->textOutput("ERROR:Invalid delay,suggested:50ms\n"), -1;
    if ( boardSize.width <= 0 )
        return window->textOutput("ERROR:Invalid board width\n" ), -1;
    if ( boardSize.height <= 0 )
        return window->textOutput("ERROR:Invalid boadr heigth\n"), -1;

    // handle the frame source
    if( !inputFilename.empty() ){
        if( !videofile && readStringList(inputFilename,imageList)){
            mode = CAPTURING;
        }
        else capture.open(cameraId);
    }
    if( !capture.isOpened() && imageList.empty())
        return window->textOutput("ERROR:Could not initialize webcam capture\n"),-1;
    if( !imageList.empty())
        nframes = (int)imageList.size();


    namedWindow("Image View",1);
    for(i = 0;;i++){
        Mat view, viewGray;
        bool blink = false;
        if( capture.isOpened() ){
            Mat frame;
            capture >> frame;
            frame.copyTo(view);
        } else if( i < (int)imageList.size() ){
            view = imread(imageList[i], 1);
        }
        if(view.empty()){
            if( imagePoints.size() > 0)
                runAndSave(outputFilename, imagePoints, imageSize,
                           boardSize, pattern, squareSize, grid_width, release_object, aspectRatio,
                           flags, cameraMatrix, distCoeffs,
                           writeExtrinsics, writePoints, writeGrid);
            break;
        }
        imageSize = view.size();

        if(flipVertical)flip(view,view,0);

        vector<Point2f> pointbuf;
        cvtColor(view, viewGray, COLOR_BGR2GRAY);

        bool found;
        switch( pattern ){
        case CHESSBOARD:
                found = findChessboardCorners(view,boardSize,pointbuf,
                                              CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FAST_CHECK | CALIB_CB_NORMALIZE_IMAGE);
            break;
        case CIRCLES_GRID:
            found = findCirclesGrid( view, boardSize, pointbuf );
            break;
        case ASYMMETRIC_CIRCLES_GRID:
            found = findCirclesGrid( view, boardSize, pointbuf, CALIB_CB_ASYMMETRIC_GRID );
            break;
        default:
            return window->textOutput("ERROR:Unknown pattern type\n"),-1;
        }

        // improve the found corners' coordinate accuracy
        if( pattern == CHESSBOARD && found) cornerSubPix( viewGray, pointbuf, Size(winSize,winSize),
                   Size(-1,-1), TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 30, 0.0001 ));

        if( mode == CAPTURING && found &&
                  (!capture.isOpened() || clock() - prevTimestamp > delay*1e-3*CLOCKS_PER_SEC) )
        {
            imagePoints.push_back(pointbuf);
            prevTimestamp = clock();
            blink = capture.isOpened();
        }

        if(found) drawChessboardCorners( view, boardSize, Mat(pointbuf), found );

        string msg = mode == CAPTURING ? "100/100" : mode == CALIBRATED ? "Calibrated" : "Press 'G' to start";

        int baseLine = 0;

        Size textSize = getTextSize(msg, 1, 1, 1,&baseLine);
        Point textOrigin(view.cols - 2 * textSize.width - 10, view.rows - 2 * baseLine - 10);
        if ( mode == CAPTURING ){
            if(undistortImage) msg = format("%d/%d Undist",(int)imagePoints.size(), nframes);
            else msg = format( "%d/%d", (int)imagePoints.size(), nframes );
        }

        putText(view,msg,textOrigin, 1, 1,
                mode != CALIBRATED ? Scalar(0,0,255):Scalar(0,255,0));

        if(blink)bitwise_not(view,view);

        if(mode == CALIBRATED && undistortImage){
            Mat temp = view.clone();
            undistort(temp,view,cameraMatrix,distCoeffs);
        }

        imshow("Image View",view);
        char key = (char)waitKey(capture.isOpened() ? 50 : 500);

        if( key == 27 )break;

        if( key == 'u' && mode == CALIBRATED ) undistortImage = !undistortImage;

        if( capture.isOpened() && key == 'g' )
        {
            mode = CAPTURING;
            imagePoints.clear();
        }

        if( mode == CAPTURING && imagePoints.size() >= (unsigned)nframes )
        {

             if( runAndSave(outputFilename, imagePoints, imageSize,
                              boardSize, pattern, squareSize, grid_width, release_object, aspectRatio,
                              flags, cameraMatrix, distCoeffs,
                              writeExtrinsics, writePoints, writeGrid))

                 mode = CALIBRATED;
             else
                 mode = DETECTION;
             if( !capture.isOpened() )
                       break;
       }




    }
    if(!capture.isOpened() && showUndistorted){
        Mat view, rview, map1, map2;
        initUndistortRectifyMap(cameraMatrix,distCoeffs,Mat(),
                                getOptimalNewCameraMatrix(cameraMatrix,distCoeffs,imageSize,1,imageSize,0),
                                imageSize, CV_16SC2, map1, map2);
        for (i = 0;i < (int)imageList.size();i++) {
            view = imread(imageList[i],1);
            if(view.empty())continue;
            remap(view,rview,map1,map2, INTER_LINEAR);
            imshow("Image View",rview);
            char c = (char)waitKey();
            if( c == 27 || c == 'q' || c == 'Q' )break;
        }
    }
    return 0;
}


void calibrate::testoutput(){
//    window = new MainWindow;
    window->textOutput("Hello there!\n");
    return ;
}
