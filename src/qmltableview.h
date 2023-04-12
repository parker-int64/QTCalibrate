#ifndef QMLTABLEVIEW_H
#define QMLTABLEVIEW_H
#include "qqmlregistration.h"
#include <QAbstractTableModel>
#include <qqml.h>


enum Role {
    OneRole,
    TwoRole,
    ThreeRole
};

class QmlTableViewModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
public:

    explicit QmlTableViewModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex & index = QModelIndex()) const override;

    int columnCount(const QModelIndex &index = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void Add(double one, double two);

    Q_INVOKABLE void Set(int row, int column, double num);

    Q_INVOKABLE void Del();

    Q_INVOKABLE void Refresh();


private:
    QVector<QVector<double>> m_dataArray;
};

#endif // QMLTABLEVIEW_H
