#ifndef CALIBRATION_H
#define CALIBRATION_H
#include "opencv2/core.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <QString>
#include "mainwindow.h"


using namespace cv;
using namespace std;

enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };
class MainWindow;
class calibrate{
    public:
    MainWindow *window;
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

    int calibMain(int chessBoardWidth,int chessBoardHeight,
                             int calibPattern,double chessBoardSize,
                             int numOfFrames,int delayInFrames,bool writeDetectedFeaturePoints,
                             bool writeExtrinsicParameters,bool writeRefined3DObjectPoints,
                             double fixAspectRatio,bool assumeZeroTangentialDistortion,
                             bool fixThePrincipalPoint,
                             bool flipTheCapturedImages,QString outputPath,
                             bool showUndistortedImages,
                             bool enableVideoFile, int cameraIndex,
                             int halfSearchWinSize,double actualDistance);

};
#endif // !CALIBRATION_H
