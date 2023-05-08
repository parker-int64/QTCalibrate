#include "calibcoord.h"
#include <iostream>

CalibCoord::CalibCoord(QObject *parent)
    : QObject{parent}
{

    connect(this, SIGNAL(send2DCalibData(QVariantList)), this, SLOT(calib2D(QVariantList)));
    connect(this, SIGNAL(send3DCalibData(QVariantList)), this, SLOT(calib3D(QVariantList)));
}


void CalibCoord::calib2D(QVariantList data){

    cv::Mat warpMat;


    std::vector<cv::Point2f> pointsets1;

    std::vector<cv::Point2f> pointsets2;

//    pointsets1 = {
//        cv::Point2f(0, 10),
//        cv::Point2f(0, 4),
//        cv::Point2f(0, 9),
//        cv::Point2f(6 ,0),
//        cv::Point2f(6, 4),
//        cv::Point2f(6, 9),
//        cv::Point2f(11, 0),
//        cv::Point2f(11, 4),
//        cv::Point2f(11, 9)
//    };
//    pointsets2 = {
//        cv::Point2f(603.6,85.8),
//        cv::Point2f(603.6, 4.1),
//        cv::Point2f(603.6, -98.5),
//        cv::Point2f(483.7, 84.8),
//        cv::Point2f(483.7 ,4.6),
//        cv::Point2f(483.7 ,-96.1),
//        cv::Point2f(383.8, 85.1),
//        cv::Point2f(383.8, 4.7),
//        cv::Point2f(383.8 ,-95.3)
//    };

    for(int i = 0; i < data.size(); i+=4) {

        pointsets1.push_back(cv::Point2f(data[i].toFloat(), data[i+1].toFloat()));

        pointsets2.push_back(cv::Point2f(data[i+2].toFloat(), data[i+3].toFloat()));
    }

    try {
        warpMat = cv::estimateAffine2D(pointsets1, pointsets2);  // this estimate function is easy so won't put it into cvfunctions.


        std::vector<double> res = warpMat.reshape(0,1);

        QVariantList tmp;

        for(auto &i : res){

            tmp.push_back(QString::number(i, 10, 16));
        }

        setCalibResult(tmp); // This will trigger value change

        emit calibSuccess();
    } catch (...) {
        emit calibError();
    }

}


// TODO: add 3D calib method
void CalibCoord::calib3D(QVariantList data){
    Q_UNUSED(data);
}



void CalibCoord::get2DCalibData(QVariantList data) {
    emit send2DCalibData(data);
}





// Following methods are used to render data in qml
void CalibCoord::get3DCalibData(QVariantList data){
    emit send3DCalibData(data);
}


QVariantList CalibCoord::getCalibResult() const {
    return m_result;
}


void CalibCoord::setCalibResult(QVariantList result) {
    m_result = result;
    emit calibResultChanged(result);
}





