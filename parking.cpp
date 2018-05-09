#include "parking.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QDebug>
using namespace std;

Parking::Parking(QObject *parent) : QObject(parent)
{


}

int Parking::size()
{
    return m_current_size;
}

int Parking::max_size()
{
    return m_parking_max;
}

int Parking::add_car(QString regNumber)
{
    if (regNumber.length()!=6 ) {
        qDebug() << "regNumber "<< regNumber <<" can't be save to parking list!";
        return 0;
        }

    car newCar;
    newCar.regNumber=regNumber;
    m_parking_list.append(newCar);
    m_current_size = m_parking_list.size();
    qDebug() << "regNumber "<< regNumber <<" save to parking list!";
    return 1;
}

int Parking::remove_car(QString regNumber)
{
    car curCar;
    int deletIndex=-1;
    for (int i=0; i<m_current_size; i++){
        curCar = m_parking_list.at(i);
        if (curCar.regNumber==regNumber){
            deletIndex=i;
        }
    }
    if (deletIndex>=0) {
        m_parking_list.removeAt(deletIndex);
    }

    m_current_size = m_parking_list.size();
    return 1;
}

QString Parking::print_parking_list()
{
    QString qsTemp;
    car curCar;
    for (int i=0; i<m_current_size; i++){
        curCar = m_parking_list.at(i);
        //qDebug() << "curCar at " << i << " have reg NR "<< curCar.regNumber.toLocal8Bit();
        qsTemp += curCar.regNumber;
    }
    return qsTemp;
}
