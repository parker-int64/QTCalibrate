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
#include <opencv2/opencv.hpp>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;
using namespace cv;
enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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
    std::string frameSource;
    int cameraIndex;
    bool enableVideoFile;
    QString videoFilePath;
    int imageWidth;
    int imageHeight;
    int calibPattern;
    int chessBoardWidth;
    int chessBoardHeight;
    double chessBoardSize;
    QString outputPath;
    QUrl folderPath;
    int numOfFrames;
    int delayInFrames;
    int halfSearchWinSize;
    double actualDistance;
    bool writeDetectedFeaturePoints;
    bool writeExtrinsicParameters;
    bool writeRefined3DObjectPoints;
    bool assumeZeroTangentialDistortion;
    double fixAspectRatio;
    bool fixThePrincipalPoint;
    bool flipTheCapturedImages;
    bool showUndistortedImages;

private:
    void cvCalibParaSetttings();
public slots:
    void selectDir();
    void selectImageFiles();
    void selectVideo();

private slots:
    void resetParameters();
    void ShowContextMenu(const QPoint& pos);
    void writeImageList();
    void initCalib();

};

#endif // MAINWINDOW_H
