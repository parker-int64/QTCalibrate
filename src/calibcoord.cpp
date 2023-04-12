#include "calibcoord.h"
#include <iostream>

CalibCoord::CalibCoord(QObject *parent)
    : QObject{parent}
{

}


void CalibCoord::calib2D(QList<QVariant> data){


    qDebug() << "Recvieved signal!!" << Qt::endl;

    cv::Mat warpMat;

    std::vector<cv::Point2f> pointsets1;

    std::vector<cv::Point2f> pointsets2;


    for(int i = 0; i < data.size(); i+=4) {

        pointsets1.push_back(cv::Point2f(data[i].toFloat(), data[i+1].toFloat()));

        pointsets2.push_back(cv::Point2f(data[i+2].toFloat(), data[i+3].toFloat()));
    }

    warpMat = cv::estimateAffine2D(pointsets1, pointsets2);


    std::cout<<warpMat<<std::endl;


}
