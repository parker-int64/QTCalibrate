#include "qmltableview.h"

#include <QDebug>

QmlTableViewModel::QmlTableViewModel(QObject *parent) : QAbstractTableModel()
{
    m_dataArray = {{44.332,55.667},
                   {108.688,66.771}};
}


int QmlTableViewModel::rowCount(const QModelIndex &index) const
{
    return m_dataArray.size();
}

int QmlTableViewModel::columnCount(const QModelIndex &index) const
{
    return m_dataArray.at(0).size();
}

QVariant QmlTableViewModel::data(const QModelIndex &index, int role) const
{
    return m_dataArray[index.row()][role];
}

QHash<int, QByteArray> QmlTableViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[0] = "X";
    roles[1] = "Y";
    return roles;
}

void QmlTableViewModel::Add(double one, double two)
{
    beginInsertRows(QModelIndex(), m_dataArray.size(), m_dataArray.size());
    QVector<double> list;
    list.push_back(one);
    list.push_back(two);
    m_dataArray.push_back(list);
    endInsertRows();
}

void QmlTableViewModel::Set(int row, int column, double num)
{
    if (row == -1){return;}
    if (column == -1){return;}
    beginResetModel();
    m_dataArray[row][column] = num;
    endResetModel();
}

void QmlTableViewModel::Del()
{
    if (m_dataArray.size() <= 0) return;
    beginRemoveRows(QModelIndex(), m_dataArray.size() - 1, m_dataArray.size() - 1);
    m_dataArray.removeLast();
    endRemoveRows();
}

void QmlTableViewModel::Refresh()
{
    beginResetModel();
    endResetModel();
}
