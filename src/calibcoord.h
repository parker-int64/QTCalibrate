#ifndef CALIBCOORD_H
#define CALIBCOORD_H

#include <QObject>
#include <QList>
#include <QVariant>
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>


class CalibCoord : public QObject
{
    Q_OBJECT
public:
    explicit CalibCoord(QObject *parent = nullptr);



public slots:
    void calib2D(QList<QVariant> data);

signals:

};

#endif // CALIBCOORD_H
