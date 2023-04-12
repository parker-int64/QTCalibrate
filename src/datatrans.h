#ifndef DATATRANS_H
#define DATATRANS_H

#include <QObject>
#include "qqmlregistration.h"

#include <QVariant>
#include <QList>


#ifdef _DEBUG
    #include <QDebug>
#endif
class DataTrans : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit DataTrans(QObject *parent = nullptr);



    Q_INVOKABLE void getDataFromQml(QList<QVariant> data);

signals:
    void sendToCalib2d(QList<QVariant> data);

};

#endif // DATATRANS_H
