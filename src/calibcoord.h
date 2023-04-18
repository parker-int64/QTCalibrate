#ifndef CALIBCOORD_H
#define CALIBCOORD_H

#include "qqmlregistration.h"
#include <QObject>
#include <QVariantList>
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>


class CalibCoord : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit CalibCoord(QObject *parent = nullptr);


    Q_INVOKABLE void get2DData(QVariantList data);

    Q_PROPERTY(QVariantList calibResult READ getCalibResult WRITE setCalibResult NOTIFY calibResultChanged);


    Q_INVOKABLE QVariantList getCalibResult() const;

    void setCalibResult(QVariantList result);

public slots:
    void calib2D(QVariantList data);

signals:
    void sendToCalib2d(QVariantList data);

    void calibResultChanged(QVariantList result);


    void calibSuccess();

    void calibError();


private:
    QVariantList m_result;

};

#endif // CALIBCOORD_H
