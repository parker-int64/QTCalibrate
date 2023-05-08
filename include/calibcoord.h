#ifndef CALIBCOORD_H
#define CALIBCOORD_H

#include "qqmlregistration.h"
#include <QObject>
#include <QVariantList>
#include "cvfunctions.h"


class CalibCoord : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit CalibCoord(QObject *parent = nullptr);
    ~CalibCoord() = default;


    Q_INVOKABLE void get2DCalibData(QVariantList data);
    Q_INVOKABLE void get3DCalibData(QVariantList data);


    Q_PROPERTY(QVariantList calibResult READ getCalibResult WRITE setCalibResult NOTIFY calibResultChanged);


    Q_INVOKABLE QVariantList getCalibResult() const;

    void setCalibResult(QVariantList result);

public slots:
    void calib2D(QVariantList data);
    void calib3D(QVariantList data);

signals:
    void send2DCalibData(QVariantList data);
    void send3DCalibData(QVariantList data);

    void calibResultChanged(QVariantList result);


    void calibSuccess();

    void calibError();


private:
    QVariantList m_result;

};

#endif // CALIBCOORD_H
