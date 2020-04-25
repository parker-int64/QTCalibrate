#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QFileDialog>
#include <QListWidget>
#include <QScrollBar>
#include <QDebug>
#include <QFile>
#include <QTranslator>
#include <QMenu>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dialog.h"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "mainwindow.h"

using namespace std;
using namespace cv;
class Dialog;           // forward declaration of Dialog because we'are going to use it in this class(form)
class MainWindow;       // forward declaration of MainWindow
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    void stereoOutput(const QString text);
    void StereoCalib(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners, bool useCalibrated, bool showRectified);
    bool readStringList( const string& filename, vector<string>& l );
    int stereoMain();
    ~Form();

private:
    Ui::Form *ui;
    Dialog *dialog;             // class pointer of Dialog,implement in cpp
    MainWindow *w;              // class pointer of Dialog
    QString stereoFolderPath;   // the stroage path of both intrinsic.yml and extrinsic.yml
    QString warning;            // a warning message
    Size boardSize;             // chess board size
    string imagelistfn;         // the path of stereolist.yaml,you should not change it
    bool showRectified;         // show the rectified images
    float squareSize;           // square size
    vector<string> imagelist;   // the list of paths that your images are located
    string stereoIntrinsic;     // intrinsic stroage path,it consists the intrinsic matrices of two cameras
    string stereoExtrinsic;     // extrinsic stroage path,it consists the extrinsic matrices of two cameras

private:
    void StereoCalibParaSetttings();
public slots:
    void selectDir();
    void selectImageFilesL();
    void selectImageFilesR();

signals:
    void endSignal();           // the signal does anything but send to the MainWindow

private slots:
    void resetParameters();
    void ShowContextMenuL(const QPoint& pos);
    void ShowContextMenuR(const QPoint& pos);
    void writeImageList();
    void initStereoCalib();
    void openHelp();
    void returnCalib();
};

#endif // FORM_H
