#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <opencv2/opencv.hpp>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // bind buttons
    connect(ui->pushButton_4, SIGNAL(clicked()),    this,SLOT(selectDir()));
    connect(ui->radioButton,  SIGNAL(clicked(bool)),this,SLOT(selectImageFiles()));
    connect(ui->pushButton,   SIGNAL(clicked(bool)),this,SLOT(resetParameters()));
    connect(ui->pushButton_3, SIGNAL(clicked()),    this,SLOT(close()));
    connect(ui->pushButton_5, SIGNAL(clicked()),    this,SLOT(writeImageList()));
    connect(ui->pushButton_2, SIGNAL(clicked()),    this,SLOT(initCalib()));
    connect(ui->pushButton_6,SIGNAL(clicked()),     this,SLOT(switchLanguage()));
    // some default value
    ui->spinBox_5->setValue(11);

    // init parameters

}

/*
 * @ output calib status into a text browser
*/
void MainWindow::textOutput(const QString text){
    ui->textBrowser->insertPlainText(text);
    ui->textBrowser->moveCursor(QTextCursor::End);
}


/*
 * @ select a directory for xml or yaml output path
*/
void MainWindow::selectDir(){
    folderPath = QFileDialog::getExistingDirectory(this, tr("select a directory"),"/",QFileDialog::ShowDirsOnly);
}


/*
 * @ select image files from explorer
*/
void MainWindow::selectImageFiles(){
    // load qss
    QFile qss("../uiComponents/scrollbar.qss");
    qss.open(QFile::ReadOnly);
    ui->listWidget->verticalScrollBar()->setStyleSheet(qss.readAll());
    qss.close();
    QStringList imageList = QFileDialog::getOpenFileNames(this, tr("Select Image Files"),"./",tr("Images (*.png *.xpm *.jpg)")); // choose multip image files
    ui->listWidget->setViewMode(QListView::IconMode);               // set view mode IconMode
    ui->listWidget->setIconSize(QSize(100,100));                    // set a item picture size
    ui->listWidget->setSpacing(5);                                  // set spacing
    ui->listWidget->setResizeMode(QListWidget::Adjust);             // set layout adjustment(Fix or Adjust)
    ui->listWidget->setMovement(QListWidget::Static);               // set static layout,cannot move items
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->listWidget,SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowContextMenu(const QPoint&)));
    if(ui->listWidget)
    for(auto tmp : imageList){
        QListWidgetItem *imageItem = new QListWidgetItem;
        imageItem->setText(QString(tmp));                           // set filename
        imageItem->setToolTip(QString(tmp));                        // tooltip for a full path
        imageItem->setIcon(QIcon(tmp));                             // icon for item
        imageItem->setSizeHint(QSize(100,120));                     // size of hint
        ui->listWidget->addItem(imageItem);                         // add item
    }
}





/*
 * @ Show delete menu in QListWidget
 * @ And Click delete button to delete a single or multiple items
*/
void MainWindow::ShowContextMenu(const QPoint& pos){
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Delete");
    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem){
        QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
         if(list.size() == 0)
          return;
         QListWidgetItem* sel = list[0];
         if (sel){
            int row = ui->listWidget->row(sel);
            ui->listWidget->takeItem(row);              // Delete the item selected
            delete ui->listWidget->takeItem(row);       // Release the memory
         }
    }
}


void MainWindow::openHelp(){


}
/*
 * @ functions for buttonGroup
 * @ add parameters from selection
*/
void MainWindow::cvCalibParaSetttings(){

    // selcet video source
    if(ui->radioButton->isChecked()){
        enableCamera = false;
        inputFilename  = "../data/imagelist.yaml";
    } else {
        textOutput(tr("ERROR:Must choose a picture source\n"));
        return ;
    }
    // imageWidth & imageHeight
    if(ui->radioButton_2->isChecked()){imageSize.width  = 320; imageSize.height  = 240;}
    if(ui->radioButton_5->isChecked()){imageSize.width  = 640; imageSize.height  = 480;}
    if(ui->radioButton_6->isChecked()){imageSize.width  = 1280;imageSize.height  = 720;}

    // calibrate patterns
    if(ui->radioButton_3->isChecked())pattern = CHESSBOARD;
    if(ui->radioButton_4->isChecked())pattern = CIRCLES_GRID;
    if(ui->radioButton_8->isChecked())pattern = ASYMMETRIC_CIRCLES_GRID;

    // chessboard or circle grid width & height & size
    boardSize.width   = ui->spinBox_2->text().toInt();
    boardSize.height  = ui->spinBox->text().toInt();
    squareSize        = (float)ui->doubleSpinBox->text().toDouble();

    // output XML or YAML path
    winSize     =  ui->spinBox_5->text().toInt();
//    grid_width  =  (float)ui->doubleSpinBox_3->text().toDouble();
    aspectRatio =  (float)ui->doubleSpinBox_2->text().toDouble();

    // enable or disable some functions
    writePoints    = ui->checkBox_2->isChecked() ? true : false;
    writeExtrinsics= ui->checkBox_3->isChecked() ? true : false;
    writeGrid      = ui->checkBox_4->isChecked() ? true : false;
    undistortImage = ui->checkBox_5->isChecked() ? true : false;

    fixedPrincipalPoint   = ui->checkBox_7->isChecked() ? true : false;
    flipVertical          = ui->checkBox_8->isChecked() ? true : false;
    showUndistorted       = ui->checkBox_9->isChecked() ? true : false;

    folderPath.isEmpty() ? outputFilename = "../data/camera.yml" :
            outputFilename = folderPath.toLocal8Bit().toStdString() + "/camera.yml";

    ui->lineEdit->setText(QString::fromStdString(outputFilename));
}

/*
 * @ start calibrate...
*/
void MainWindow::initCalib(){
    textOutput(tr("[Starting calibration ...]\n"));
    cvCalibParaSetttings();
    calibMain();
    textOutput(tr("[End calibration...]\n"));
}


/*
 * @ write all images in QListWigets to imageList.yml
*/
void MainWindow::writeImageList(){
    int count = ui->listWidget->count();
    if(count == 0)return ;

    string outputname = "../data/imagelist.yaml";

     if (outputname.empty())
     {
         textOutput(tr("ERROR:imagelist is empty\n"));
       return ;
     }

     Mat m = imread(outputname); //check if the output is an image - prevent overwrites!
     if(!m.empty()){
       textOutput(tr("fail! Please specify an output file, don't want to overwrite you images!\n"));
       return ;
     }

     FileStorage fs(outputname, FileStorage::WRITE);
     fs << "images" << "[";
     for(int i = 0; i < count; i++){
       fs << ui->listWidget->item(i)->text().toLocal8Bit().toStdString();
     }
     fs << "]";



}


/*
 @ clear all and set to default value...
*/
void MainWindow::resetParameters(){
    ui->pushButton_2->setEnabled(true);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_5->setValue(11);
    ui->doubleSpinBox->setValue(0.);
    ui->doubleSpinBox_2->setValue(0.);
    ui->doubleSpinBox_3->setValue(0.);
    ui->lineEdit->setText("");
    ui->listWidget->clear();
    ui->textBrowser->clear();
}


MainWindow::~MainWindow(){
    delete ui;
}

double MainWindow::computeReprojectionErrors(
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


void MainWindow::calcChessboardCorners(Size boardSize, float squareSize, vector<Point3f>& corners, Pattern patternType = CHESSBOARD)
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
        textOutput(tr("ERROR:Unknown pattern type\n"));
    }
}



bool MainWindow::runCalibration( vector<vector<Point2f> > imagePoints,
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
    qDebug() << "rms = "<< rms;
    QString rmsStatus = QString(tr("RMS error reported by calibrateCamera: %1\n")).arg(QString::number(rms));
    textOutput(rmsStatus);

    bool ok = checkRange(cameraMatrix) && checkRange(distCoeffs);

    if (release_object) {
        QString releaseStatus;

        releaseStatus = QString("New board corners:\n"
                                "%1\n%2\n%3\n%4\n").arg(QString::number(newObjPoints[0].x)+","+
                QString::number(newObjPoints[0].y)+","+
                QString::number(newObjPoints[0].z)).arg(QString::number(newObjPoints[boardSize.width - 1].x)+","+
                QString::number(newObjPoints[boardSize.width - 1].y)+","+
                QString::number(newObjPoints[boardSize.width - 1].z)).arg(QString::number(newObjPoints[boardSize.width * (boardSize.height - 1)].x)+","+
                QString::number(newObjPoints[boardSize.width * (boardSize.height - 1)].y)+","+
                QString::number(newObjPoints[boardSize.width * (boardSize.height - 1)].z)).arg((QString::number(newObjPoints.back().x)+","+
                                                                                               QString::number(newObjPoints.back().y)+","+
                                                                                               QString::number(newObjPoints.back().z)));
        textOutput(releaseStatus);
    }

    objectPoints.clear();
    objectPoints.resize(imagePoints.size(), newObjPoints);
    totalAvgErr = computeReprojectionErrors(objectPoints, imagePoints,
                rvecs, tvecs, cameraMatrix, distCoeffs, reprojErrs);

    return ok;
}




void MainWindow::saveCameraParams( const string& filename,
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

bool MainWindow::readStringList( const string& filename, vector<string>& l )
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


bool MainWindow::runAndSave(const string& outputFilename,
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
    ok ? calibrateStatus = QString(tr("Calibration succeeded with rms %1.\n")).arg(QString::number(totalAvgErr)) : calibrateStatus = QString(tr("Calibration failed.\n"));
    textOutput(calibrateStatus);
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

int MainWindow::calibMain(){

    squareSize = 1.;
    aspectRatio = 1.;
    writeExtrinsics = false;
    writePoints = false;
    undistortImage = false;
    flags = 0;
    flipVertical = false;
    showUndistorted = false;
    writeGrid = false;
    prevTimestamp = 0;
    mode = DETECTION;
    cameraId = 0;
    pattern = CHESSBOARD;


    if(aspectRatio != 0.)
        flags |= CALIB_FIX_ASPECT_RATIO;
    if(assumeZeroTangentialDistortion)
        flags |= CALIB_ZERO_TANGENT_DIST;
    if(fixedPrincipalPoint)
        flags |= CALIB_FIX_PRINCIPAL_POINT;



    grid_width == 0. ? grid_width = squareSize * (boardSize.width - 1) : grid_width;

    bool release_object = false;



    // some key factors

    if ( squareSize <= 0 )
        return textOutput(tr("ERROR:Invalid board square width\n")),-1;
    if ( aspectRatio <= 0 )
        return textOutput(tr("ERROR:Invalid aspect ratio\n")),-1;
    if ( boardSize.width <= 0 )
        return textOutput(tr("ERROR:Invalid board width\n") ), -1;
    if ( boardSize.height <= 0 )
        return textOutput(tr("ERROR:Invalid boadr heigth\n")), -1;

    // handle the frame source
    if( !inputFilename.empty() ){
        if( !enableCamera && readStringList(samples::findFile(inputFilename),imageList))
            mode = CAPTURING;
    }
    else if(enableCamera)
        capture.open(cameraId);
    else return textOutput(tr("Must select a picture source...\n")),-1;
    if(imageList.empty() )
        return textOutput(tr("ERROR:imagelist.yaml is empty\n")),-1;
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
            return textOutput(tr("ERROR:Unknown pattern type\n")),-1;
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
    cameraMatrix.release();
    distCoeffs.release();
    imagePoints.clear();
    imageList.clear();
    destroyAllWindows();
    return 0;
}


void MainWindow::testoutput(){
    textOutput(tr("Hello there!\n"));
}

