#include "parking.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QDebug>
#include <QRegExp>
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
    if (m_current_size>=m_parking_max){
        qDebug() << "regNumber "<< regNumber <<" can't be save to parking list! Parking lot is full";
        return 0;
    }

    if (regNumber.length()!=6 ) {
        qDebug() << "regNumber "<< regNumber <<" can't be save to parking list! Reg number too long";
        return 0;
    }

    QRegExp rx_RegNumber ("[A-Z][A-Z][A-Z][0-9][0-9][0-9]");

    if (! rx_RegNumber.exactMatch(regNumber)){
        qDebug() << "regNumber "<< regNumber <<" can't be save to parking list!, wrong format";
        return 0;
    }

    if (is_car_exist(regNumber)){
        qDebug() << "regNumber "<< regNumber <<" can't be save to parking list!, regNumber exist in parking list";
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
        m_current_size = m_parking_list.size();
        return 1;
    }    
    return 0;
}

QString Parking::print_parking_list()
{
    QString qsTemp;
    car curCar;
    for (int i=0; i<m_current_size; i++){
        curCar = m_parking_list.at(i);
        //qDebug() << "curCar at " << i << " have reg NR "<< curCar.regNumber.toLocal8Bit();
        qsTemp += curCar.regNumber;
       // qsTemp += " time:";
       // qsTemp += curCar.enterTime.toString("dd.MM.yyyy hh:mm:ss ");
    }
    return qsTemp;
}

bool Parking::is_car_exist(QString regNumber)
{
    if (m_current_size==0) return false;
    car curCar;
    for (int i=0; i<m_current_size; i++){
        curCar = m_parking_list.at(i);
        if (curCar.regNumber == regNumber) return true;
    }
    return false;
}

car Parking::get_car_by_number(QString regNumber)
{
    car curCar;

    for (int i=0; i<m_current_size; i++){
        curCar = m_parking_list.at(i);
        if (curCar.regNumber==regNumber){
            return curCar;
        }
    }
    curCar.regNumber= "No car";
    return curCar;
}
