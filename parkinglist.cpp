#include "parkinglist.h"

parkingList::parkingList(QObject *parent)
    : QStringListModel(parent)
{

}

void parkingList::setStringList(const QStringList &strings)
{
    _list = strings;
}

QStringList parkingList::stringList() const
{
    return _list;
}

int parkingList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _list.size();
}

QVariant parkingList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case Qt::DisplayRole:
        return _list.at(index.row());
        break;
    default:
        return QVariant();
        break;
    }
    return QVariant();
}

bool parkingList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if (role == Qt::EditRole){

            QString qsVal = value.toString();
            if (!isGoodValue(qsVal)) return false;


            _list.replace(index.row(), value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        }
        return true;
    }
    return false;
}

Qt::ItemFlags parkingList::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable ; // FIXME: Implement me!
}

bool parkingList::insertRows(int row, int count, const QModelIndex &parent)
{
    qDebug() << "insertRows, row is "<< row << " couunt is " << count;
    beginInsertRows(parent, row, row + count - 1);
    endInsertRows();
    return true;
}

bool parkingList::removeRows(int row, int count, const QModelIndex &parent)
{
    qDebug() << "removeRows, row is "<< row << " couunt is " << count;
    beginRemoveRows(parent, row, row + count - 1);
    endRemoveRows();
    return true;
}

bool parkingList::append(QString qsValue)
{
    qDebug() << "append value "<<qsValue;
    if (!isGoodValue(qsValue))  return false;
    insertRows(rowCount(),1);
    _list.append(qsValue);
    return true;
}

bool parkingList::remove(QString qsValue)
{
    qDebug() << "remove value "<<qsValue;
    int index = _list.indexOf(qsValue);
    if (index == -1) return false;
    removeRows(index,1);
    _list.removeOne(qsValue);
    return true;
}

bool parkingList::isGoodValue(QString qsValue)
{
    if (qsValue.length()==6 ){
        qDebug() << "this isGoodValue "<<qsValue;
        return true;
    }

    qDebug() << "this is NOT GoodValue "<<qsValue;
    return false;
}
