#include "parkinglist.h"

ParkingList::ParkingList(QObject *parent)
    : QAbstractListModel(parent)
{
}

void ParkingList::setStringList(QStringList qslParksingList)
{
    qslParking = qslParksingList;
}

QStringList ParkingList::stringList()
{
    return qslParking;
}

int ParkingList::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return qslParking.size();
}

QVariant ParkingList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        return  qslParking.at(index.row());
    }
    return QVariant();
}

bool ParkingList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if (role == Qt::EditRole){
            QString qsVal = value.toString();
            qslParking.replace(index.row(), qsVal);

            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }

    }
    return false;
}

Qt::ItemFlags ParkingList::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable ;


}

bool ParkingList::append(QString regNumber, QString time)
{
    if (isGoodNumber(regNumber)) {
        qslParking.prepend(regNumber+" "+time);
        return insertRow(0);
    }

}



bool ParkingList::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    endInsertRows();
    return true;
}


bool ParkingList::remove(QString regNumber)
{
    qDebug() << "ParkingList::remove QString regNumber is" << regNumber;
    int index = qslParking.indexOf(regNumber);
    qDebug() << "ParkingList::remove indexOf is" << index;
    if (index == -1 ) return false;

    qDebug() << "ParkingList::remove qslParking size " << qslParking.size();

    qslParking.removeAt(index);

    qDebug() << "ParkingList::remove qslParking size " << qslParking.size();

    return removeRow(0);

}
bool ParkingList::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    endRemoveRows();
    return true;
}

bool ParkingList::isGoodNumber(QString regNumber)
{
    if (regNumber.length()== 6) return true;
    return false;
}

