#include "parkingtable.h"
#include "parking.h"

#include <QDebug>

ParkingTable::ParkingTable(QObject *parent)
    : QAbstractTableModel(parent)
{

    parking= new Parking();
}

QVariant ParkingTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        if (section == 0) return "Reg Number";
        if (section == 1) return "Time ";
    return QVariant();
}


int ParkingTable::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    int rows = parking->size();
    return rows;
}

int ParkingTable::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;
}

QVariant ParkingTable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case Qt::DisplayRole:
        int row = index.row();
        car c = parking->get_car_by_index(row);

        if (index.column()==0) return c.regNumber;
        if (index.column()==1) return c.enterTime.toString("hh:mm:ss");
        break;
    }
    return QVariant();
}

bool ParkingTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ParkingTable::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable ;
}

bool ParkingTable::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    endInsertRows();
    return true;
}


bool ParkingTable::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    endRemoveRows();
    return true;
}

bool ParkingTable::appendCar(QString regNumber)
{
    if (parking->add_car(regNumber) == 1 ){
        qDebug() << "appendCar secsessful" ;
        return insertRow(0);
    }
    qDebug() << "can´t appendCar with number " << regNumber ;
    return false;
}

