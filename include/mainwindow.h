#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <opencv2/opencv.hpp>
#include "dialog.h"
#include "form.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;
using namespace cv;
enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };
class Form;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Dialog *dialog;
    Form *form;
    MainWindow(QWidget *parent = nullptr);
    void textOutput(const QString text);
    ~MainWindow();
    double computeReprojectionErrors(
            const vector<vector<Point3f> >& objectPoints,
            const vector<vector<Point2f> >& imagePoints,
            const vector<Mat>& rvecs, const vector<Mat>& tvecs,
            const Mat& cameraMatrix, const Mat& distCoeffs,
            vector<float>& perViewErrors );
    
    void calcChessboardCorners(Size boardSize, float squareSize, vector<Point3f>& corners, Pattern patternType);

    bool runCalibration( vector<vector<Point2f> > imagePoints,
                        Size imageSize, Size boardSize, Pattern patternType,
                        float squareSize, float aspectRatio,
                        float grid_width, bool release_object,
                        int flags, Mat& cameraMatrix, Mat& distCoeffs,
                        vector<Mat>& rvecs, vector<Mat>& tvecs,
                        vector<float>& reprojErrs,
                        vector<Point3f>& newObjPoints,
                        double& totalAvgErr);
    
    void saveCameraParams( const string& filename,
                           Size imageSize, Size boardSize,
                           float squareSize, float aspectRatio, int flags,
                           const Mat& cameraMatrix, const Mat& distCoeffs,
                           const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                           const vector<float>& reprojErrs,
                           const vector<vector<Point2f> >& imagePoints,
                           const vector<Point3f>& newObjPoints,
                           double totalAvgErr );

    bool readStringList( const string& filename, vector<string>& l );

    bool runAndSave(const string& outputFilename,
                    const vector<vector<Point2f> >& imagePoints,
                    Size imageSize, Size boardSize, Pattern patternType, float squareSize,
                    float grid_width, bool release_object,
                    float aspectRatio, int flags, Mat& cameraMatrix,
                    Mat& distCoeffs, bool writeExtrinsics, bool writePoints, bool writeGrid );

    void testoutput();

    int calibMain();

private:

    Ui::MainWindow *ui;
    bool enableCamera;                      // enable camera,this was set to false by default
    QString folderPath;                     // the path to stroage the camera matrix
    bool assumeZeroTangentialDistortion;
    bool fixedPrincipalPoint;

private:
    Size boardSize;                         // size of a chess board or a circle grid
    Size imageSize;                         // image size
    float squareSize;                       // size of a square of a circle grid
    float aspectRatio;
    Mat cameraMatrix;                       // camera matrix
    Mat distCoeffs;                         // distortion Matrix
    string outputFilename;                  // the output camera.yml's full path
    string inputFilename;                   // input path of a imagelist.yaml
    int i;
    int nframes;                            // how many pitcures in total
    bool writeExtrinsics;
    bool writePoints;
    bool writeGrid;
    bool undistortImage;
    int flags;
    VideoCapture capture;
    bool flipVertical;
    bool showUndistorted;
    bool videofile;
    int delay;
    clock_t prevTimestamp;
    int mode;
    int cameraId;
    vector<vector<Point2f> > imagePoints;   // a vector<vector<Point2f>> for detected image points stroage
    vector<string> imageList;               // imageList consists full path of the calibrate images,this was read from inputfilename
    Pattern pattern;                        // calibrate pattern
    int winSize;                            // corner sub pixels half of serach windows size, the default value is 11
    float grid_width;                       // actual distance between top-left and top-right corners of the calibration grid.

private:
    void cvCalibParaSetttings();
public slots:
    void selectDir();
    void selectImageFiles();

private slots:
    void resetParameters();
    void ShowContextMenu(const QPoint& pos);
    void writeImageList();
    void initCalib();
    void openHelp();
    void stereoCalib();
    void reshow();
};

#endif // MAINWINDOW_H
