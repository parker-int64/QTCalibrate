#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    // bind button options
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(selectImageFilesL()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(selectImageFilesR()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(writeImageList()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(selectDir()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(initStereoCalib()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(resetParameters()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(openHelp()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(returnCalib()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(close()));

    // And of course ,load qss of our scrollbar
    QFile qss("../uiComponents/scrollbar.qss");
    qss.open(QFile::ReadOnly);
    QString styleSheet = qss.readAll(); // must stroage it to a QString variable before you set the style sheet
    ui->listWidget->verticalScrollBar()->setStyleSheet(styleSheet);
    ui->listWidget_2->verticalScrollBar()->setStyleSheet(styleSheet);
    ui->textBrowser->verticalScrollBar()->setStyleSheet(styleSheet);
    qss.close();

    warning = "!!!WARNING:Stereo calibration involves a lot of matrix computing,"
                      "the program may freeze during the computation.\n"
                      "It is a normal phenomenon.Please wait for a few seconds or "
                      " a few minutes\n\n";
    ui->textBrowser->setText(warning);

    // Listwigets settings
    ui->listWidget->setViewMode(QListView::IconMode);               // set view mode IconMode
    ui->listWidget->setIconSize(QSize(100,100));                    // set a item picture size
    ui->listWidget->setSpacing(5);                                  // set spacing
    ui->listWidget->setResizeMode(QListWidget::Adjust);             // set layout adjustment(Fix or Adjust)
    ui->listWidget->setMovement(QListWidget::Static);               // set static layout,cannot move items
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->listWidget_2->setViewMode(QListView::IconMode);               // set view mode IconMode
    ui->listWidget_2->setIconSize(QSize(100,100));                    // set a item picture size
    ui->listWidget_2->setSpacing(5);                                  // set spacing
    ui->listWidget_2->setResizeMode(QListWidget::Adjust);             // set layout adjustment(Fix or Adjust)
    ui->listWidget_2->setMovement(QListWidget::Static);               // set static layout,cannot move items
    ui->listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
}

/*
* @ select a directory for camera matrices stroage
*/
void Form::selectDir(){
    stereoFolderPath = QFileDialog::getExistingDirectory(this, tr("select a directory"),"/",QFileDialog::ShowDirsOnly);
}


/*
 * @ select image files from left camera
*/
void Form::selectImageFilesL(){
    QStringList imageList = QFileDialog::getOpenFileNames(this, tr("Select Image Files"),"./",tr("Images (*.png *.xpm *.jpg)")); // choose multip image files
    connect(ui->listWidget,SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowContextMenuL(const QPoint&)));
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
 * @ select image files from right camera
*/
void Form::selectImageFilesR(){
    QStringList imageList = QFileDialog::getOpenFileNames(this, tr("Select Image Files"),"./",tr("Images (*.png *.xpm *.jpg)")); // choose multip image files
    connect(ui->listWidget_2,SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowContextMenuR(const QPoint&)));
    if(ui->listWidget_2)
    for(auto tmp : imageList){
        QListWidgetItem *imageItem = new QListWidgetItem;
        imageItem->setText(QString(tmp));                           // set filename
        imageItem->setToolTip(QString(tmp));                        // tooltip for a full path
        imageItem->setIcon(QIcon(tmp));                             // icon for item
        imageItem->setSizeHint(QSize(100,120));                     // size of hint
        ui->listWidget_2->addItem(imageItem);                         // add item
    }
}


/*
 * @ display the image items in listwigets left
*/
void Form::ShowContextMenuL(QPoint const& pos){
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



/*
 * @ display the image items in listwigets right
*/
void Form::ShowContextMenuR(QPoint const& pos){
    QPoint globalPos = ui->listWidget_2->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Delete");
    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem){
        QList<QListWidgetItem*> list = ui->listWidget_2->selectedItems();
         if(list.size() == 0)
          return;
         QListWidgetItem* sel = list[0];
         if (sel){
            int row = ui->listWidget_2->row(sel);
            ui->listWidget_2->takeItem(row);              // Delete the item selected
            delete ui->listWidget_2->takeItem(row);       // Release the memory
         }
    }
}

/*
*  @ write images to stereolist.yaml,so that calibration function can read it and calibrate.
*/
void Form::writeImageList(){
    int count = ui->listWidget->count();
    int count_2 = ui->listWidget_2->count();
    if(count == 0 || count_2 == 0){
        stereoOutput("ERROR:Write to stereolist.yaml failed!\n");
        return ;
    }
    else if(count != count_2){
        stereoOutput("ERROR:the number of left images doesn't equal to the right!\n");
        return ;
    }

    string outputname = "../data/stereolist.yaml";

     if (outputname.empty())
     {
         stereoOutput(tr("ERROR:imagelist is empty\n"));
       return ;
     }

     Mat m = imread(outputname); //check if the output is an image - prevent overwrites!
     if(!m.empty()){
       stereoOutput(tr("fail! Please specify an output file, don't want to overwrite you images!\n"));
       return ;
     }

     FileStorage fs(outputname, FileStorage::WRITE);
     fs << "images" << "[";
     for(int i = 0; i < count; i++){
       fs << ui->listWidget->item(i)->text().toLocal8Bit().toStdString();
       fs << ui->listWidget_2->item(i)->text().toLocal8Bit().toStdString();
     }
     fs << "]";

}


/*
 * @ get settings from the UI components
*/
void Form::StereoCalibParaSetttings(){
    boardSize.width  = ui->spinBox->text().toUInt();
    boardSize.height = ui->spinBox_2->text().toInt();
    squareSize       = (float)ui->doubleSpinBox->text().toDouble();
    showRectified    = ui->checkBox->isChecked() ? true : false;
    if(stereoFolderPath.isEmpty()){
        stereoIntrinsic = "../data/intrinsic.yml";
        stereoExtrinsic = "../data/extrinsic.yml";
        ui->lineEdit_3->setText(QString::fromStdString(stereoIntrinsic));
    } else {
        ui->lineEdit_3->setText(stereoFolderPath);
        stereoIntrinsic = stereoFolderPath.toLocal8Bit().toStdString() + "/intrinsic.yml";
        stereoExtrinsic = stereoFolderPath.toLocal8Bit().toStdString() + "/extrinsic.yml";
    }

}


/*
 * @ start the calibration
*/
void Form::initStereoCalib(){
    stereoOutput("[Starting stereo calibration...]\n\n");
    stereoMain();
    stereoOutput("[End stereo calibration]\n");
}

/*
 * @ open Chinses help document
*/
void Form::openHelp(){
    dialog = new Dialog(this);
    dialog->setWindowTitle("中文帮助说明");
    dialog->stereoHelp();
    dialog->setFixedSize(640,480);
    dialog->show();
}


/*
 * @ write output information to the textBrowser
*/
void Form::stereoOutput(const QString text){
    ui->textBrowser->insertPlainText(text);
    ui->textBrowser->moveCursor(QTextCursor::End);
}


/*
* @ reset all UI parameters
*/
void Form::resetParameters(){
    ui->textBrowser->setText(warning);
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->doubleSpinBox->setValue(0.);
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->textBrowser->clear();

}

/*
 * @ return to the MainWinow for single camera calibration
 *   this function basiclly emit a single to the MainWindow
 *   and hide the this Form window,then reshow the MainWindow
*/
void Form::returnCalib(){
    emit endSignal();
    this->hide();
}

/*
 * @ opencv stereo calibration
*/
void Form::StereoCalib(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners, bool useCalibrated=true, bool showRectified=true)
{
    displayCorners = true;
    if( imagelist.size() % 2 != 0 )
    {
        stereoOutput("Error: the image list contains odd (non-even) number of elements\n");
        return;
    }

    if(boardSize.width == 0 || boardSize.height == 0 || squareSize == 0.){
        stereoOutput("ERROR:board width, board height and square size cannot be 0\n");
        return ;
    }

    const int maxScale = 2;
    // ARRAY AND VECTOR STORAGE:

    vector<vector<Point2f> > imagePoints[2];
    vector<vector<Point3f> > objectPoints;
    Size imageSize;

    int i, j, k, nimages = (int)imagelist.size()/2;

    imagePoints[0].resize(nimages);
    imagePoints[1].resize(nimages);
    vector<string> goodImageList;

    for( i = j = 0; i < nimages; i++ )
    {
        for( k = 0; k < 2; k++ )
        {
            const string& filename = imagelist[i*2+k];
            Mat img = imread(filename, 0);
            if(img.empty())
                break;
            if( imageSize == Size() )
                imageSize = img.size();
            else if( img.size() != imageSize )
            {
                QString imageStatus = QString("WARNING:The image %1 has the size different from the first image size. Skipping the pair\n").arg(QString::fromStdString(filename));
                stereoOutput(imageStatus);
                break;
            }
            bool found = false;
            vector<Point2f>& corners = imagePoints[k][j];
            for( int scale = 1; scale <= maxScale; scale++ )
            {
                Mat timg;
                if( scale == 1 )
                    timg = img;
                else
                    cv::resize(img, timg, Size(), scale, scale, INTER_LINEAR_EXACT);
                found = findChessboardCorners(timg, boardSize, corners,
                    CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);
                if( found )
                {
                    if( scale > 1 )
                    {
                        Mat cornersMat(corners);
                        cornersMat *= 1./scale;
                    }
                    break;
                }
            }
            if( displayCorners )
            {
                stereoOutput(QString::fromStdString(filename));
                Mat cimg, cimg1;
                cvtColor(img, cimg, COLOR_GRAY2BGR);
                drawChessboardCorners(cimg, boardSize, corners, found);
                double sf = 640./MAX(img.rows, img.cols);
                cv::resize(cimg, cimg1, Size(), sf, sf, INTER_LINEAR_EXACT);
                imshow("corners", cimg1);
                char c = (char)waitKey(500);
                if( c == 27 || c == 'q' || c == 'Q' ) //Allow ESC to quit
                    exit(-1);
            }

            else
                stereoOutput(".");
            if( !found )
                break;
            destroyAllWindows();
            cornerSubPix(img, corners, Size(11,11), Size(-1,-1),
                         TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                                      30, 0.01));
        }
        if( k == 2 )
        {
            goodImageList.push_back(imagelist[i*2]);
            goodImageList.push_back(imagelist[i*2+1]);
            j++;
        }
    }
    QString matchStatus = QString("%1 pairs have been successfully detected.\n").arg(QString::number(j));
    stereoOutput(matchStatus);
    nimages = j;
    if( nimages < 2 )
    {
        stereoOutput("ERROR:too little pairs to run the calibration\n");
        return;
    }

    imagePoints[0].resize(nimages);
    imagePoints[1].resize(nimages);
    objectPoints.resize(nimages);

    for( i = 0; i < nimages; i++ )
    {
        for( j = 0; j < boardSize.height; j++ )
            for( k = 0; k < boardSize.width; k++ )
                objectPoints[i].push_back(Point3f(k*squareSize, j*squareSize, 0));
    }

    Mat cameraMatrix[2], distCoeffs[2];
    cameraMatrix[0] = initCameraMatrix2D(objectPoints,imagePoints[0],imageSize,0);
    cameraMatrix[1] = initCameraMatrix2D(objectPoints,imagePoints[1],imageSize,0);
    Mat R, T, E, F;

    double rms = stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
                    cameraMatrix[0], distCoeffs[0],
                    cameraMatrix[1], distCoeffs[1],
                    imageSize, R, T, E, F,
                    CALIB_FIX_ASPECT_RATIO +
                    CALIB_ZERO_TANGENT_DIST +
                    CALIB_USE_INTRINSIC_GUESS +
                    CALIB_SAME_FOCAL_LENGTH +
                    CALIB_RATIONAL_MODEL +
                    CALIB_FIX_K3 + CALIB_FIX_K4 + CALIB_FIX_K5,
                    TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 100, 1e-5) );
    QString status = QString("Done with RMS error = %1\n").arg(QString::number(rms));
    stereoOutput(status);

    // CALIBRATION QUALITY CHECK
    // because the output fundamental matrix implicitly
    // includes all the output information,
    // we can check the quality of calibration using the
    // epipolar geometry constraint: m2^t*F*m1=0
    double err = 0;
    int npoints = 0;
    vector<Vec3f> lines[2];
    for( i = 0; i < nimages; i++ )
    {
        int npt = (int)imagePoints[0][i].size();
        Mat imgpt[2];
        for( k = 0; k < 2; k++ )
        {
            imgpt[k] = Mat(imagePoints[k][i]);
            undistortPoints(imgpt[k], imgpt[k], cameraMatrix[k], distCoeffs[k], Mat(), cameraMatrix[k]);
            computeCorrespondEpilines(imgpt[k], k+1, F, lines[k]);
        }
        for( j = 0; j < npt; j++ )
        {
            double errij = fabs(imagePoints[0][i][j].x*lines[1][j][0] +
                                imagePoints[0][i][j].y*lines[1][j][1] + lines[1][j][2]) +
                           fabs(imagePoints[1][i][j].x*lines[0][j][0] +
                                imagePoints[1][i][j].y*lines[0][j][1] + lines[0][j][2]);
            err += errij;
        }
        npoints += npt;
    }
    stereoOutput("Average Epipolar error = "+QString::number(err/npoints)+"\n");

    // save intrinsic parameters
    FileStorage fs(stereoIntrinsic, FileStorage::WRITE);
    if( fs.isOpened() )
    {
        fs << "M1" << cameraMatrix[0] << "D1" << distCoeffs[0] <<
            "M2" << cameraMatrix[1] << "D2" << distCoeffs[1];
        fs.release();
    }
    else
        stereoOutput("Error: can not save the intrinsic parameters\n");

    Mat R1, R2, P1, P2, Q;
    Rect validRoi[2];

    stereoRectify(cameraMatrix[0], distCoeffs[0],
                  cameraMatrix[1], distCoeffs[1],
                  imageSize, R, T, R1, R2, P1, P2, Q,
                  CALIB_ZERO_DISPARITY, 1, imageSize, &validRoi[0], &validRoi[1]);

    fs.open(stereoExtrinsic, FileStorage::WRITE);
    if( fs.isOpened() )
    {
        fs << "R" << R << "T" << T << "R1" << R1 << "R2" << R2 << "P1" << P1 << "P2" << P2 << "Q" << Q;
        fs.release();
    }
    else
        stereoOutput("Error: can not save the extrinsic parameters\n");

    // OpenCV can handle left-right
    // or up-down camera arrangements
    bool isVerticalStereo = fabs(P2.at<double>(1, 3)) > fabs(P2.at<double>(0, 3));

    // COMPUTE AND DISPLAY RECTIFICATION
    if( !showRectified )
        return;

    Mat rmap[2][2];
    // IF BY CALIBRATED (BOUGUET'S METHOD)
    if( useCalibrated )
    {
        // we already computed everything
    }
    // OR ELSE HARTLEY'S METHOD
    else
    // use intrinsic parameters of each camera, but
    // compute the rectification transformation directly
    // from the fundamental matrix
    {
        vector<Point2f> allimgpt[2];
        for( k = 0; k < 2; k++ )
        {
            for( i = 0; i < nimages; i++ )
                std::copy(imagePoints[k][i].begin(), imagePoints[k][i].end(), back_inserter(allimgpt[k]));
        }
        F = findFundamentalMat(Mat(allimgpt[0]), Mat(allimgpt[1]), FM_8POINT, 0, 0);
        Mat H1, H2;
        stereoRectifyUncalibrated(Mat(allimgpt[0]), Mat(allimgpt[1]), F, imageSize, H1, H2, 3);

        R1 = cameraMatrix[0].inv()*H1*cameraMatrix[0];
        R2 = cameraMatrix[1].inv()*H2*cameraMatrix[1];
        P1 = cameraMatrix[0];
        P2 = cameraMatrix[1];
    }

    //Precompute maps for cv::remap()
    initUndistortRectifyMap(cameraMatrix[0], distCoeffs[0], R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);
    initUndistortRectifyMap(cameraMatrix[1], distCoeffs[1], R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);

    Mat canvas;
    double sf;
    int w, h;
    if( !isVerticalStereo )
    {
        sf = 600./MAX(imageSize.width, imageSize.height);
        w = cvRound(imageSize.width*sf);
        h = cvRound(imageSize.height*sf);
        canvas.create(h, w*2, CV_8UC3);
    }
    else
    {
        sf = 300./MAX(imageSize.width, imageSize.height);
        w = cvRound(imageSize.width*sf);
        h = cvRound(imageSize.height*sf);
        canvas.create(h*2, w, CV_8UC3);
    }

    for( i = 0; i < nimages; i++ )
    {
        for( k = 0; k < 2; k++ )
        {
            Mat img = imread(goodImageList[i*2+k], 0), rimg, cimg;
            remap(img, rimg, rmap[k][0], rmap[k][1], INTER_LINEAR);
            cvtColor(rimg, cimg, COLOR_GRAY2BGR);
            Mat canvasPart = !isVerticalStereo ? canvas(Rect(w*k, 0, w, h)) : canvas(Rect(0, h*k, w, h));
            cv::resize(cimg, canvasPart, canvasPart.size(), 0, 0, INTER_AREA);
            if( useCalibrated )
            {
                Rect vroi(cvRound(validRoi[k].x*sf), cvRound(validRoi[k].y*sf),
                          cvRound(validRoi[k].width*sf), cvRound(validRoi[k].height*sf));
                rectangle(canvasPart, vroi, Scalar(0,0,255), 3, 8);
            }
        }

        if( !isVerticalStereo )
            for( j = 0; j < canvas.rows; j += 16 )
                line(canvas, Point(0, j), Point(canvas.cols, j), Scalar(0, 255, 0), 1, 8);
        else
            for( j = 0; j < canvas.cols; j += 16 )
                line(canvas, Point(j, 0), Point(j, canvas.rows), Scalar(0, 255, 0), 1, 8);
        imshow("rectified", canvas);
        char c = (char)waitKey();
        if( c == 27 || c == 'q' || c == 'Q' )
            break;
    }
    destroyAllWindows();
}


/*
 * @ read image files from stereolist.yaml,then stroage them to imageList(vector<string>)
*/
bool Form::readStringList( const string& filename, vector<string>& l )
{
    l.resize(0);
    FileStorage fs(filename, FileStorage::READ);
    if( !fs.isOpened() )
        return false;
    FileNode n = fs.getFirstTopLevelNode();
    if( n.type() != FileNode::SEQ )
        return false;
    FileNodeIterator it = n.begin(), it_end = n.end();
    for( ; it != it_end; ++it )
        l.push_back((string)*it);
    return true;
}


/*
 * @ this function consists setting parameters,reading image files and running stereo calibration
*/
int Form::stereoMain(){
    StereoCalibParaSetttings();
    imagelistfn = "../data/stereolist.yaml";
    bool ok = readStringList(imagelistfn, imagelist);
    if(!ok || imagelist.empty())
    {
        QString status = QString("Cannot open %1 or the string list is empty\n").arg(QString::fromStdString(imagelistfn));
        stereoOutput(status);
        return -1;
    }
    StereoCalib(imagelist, boardSize, squareSize, false, true, showRectified);
}


Form::~Form()
{
    delete ui;
}
