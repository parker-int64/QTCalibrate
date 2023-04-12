#include "datatrans.h"
#include "calibcoord.h"

DataTrans::DataTrans(QObject *parent)
    : QObject{parent}
{
    CalibCoord calib;
    connect(this, SIGNAL(sendToCalib2d(QList<QVariant>)), &calib, SLOT(calib2D(QList<QVariant>)));
}




void DataTrans::getDataFromQml(QList<QVariant> data) {

    for(auto &i : data){
        qDebug() << "CXX: " << i << "\n";
    }
    qDebug() << Qt::endl;

    emit sendToCalib2d(data);

}
