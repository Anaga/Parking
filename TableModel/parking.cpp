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
    if (regNumber.length()!=6 ) {
        qDebug() << "regNumber "<< regNumber <<" can't be save to parking list!";
        return 0;
        }
    QRegExp rx3l3d("[A-Z][A-Z][A-Z][0-9][0-9][0-9]");

    if (rx3l3d.exactMatch(regNumber) == false){
        qDebug() << "regNumber "<< regNumber <<"not exactMatch 3LETERS 3 numbers!";
        return 0;
    }
    qDebug() << "regNumber "<< regNumber <<" exactMatch 3LETERS 3 numbers!";

    QRegExp rx_regNumber ("[A-Z][A-Z][A-Z][0-9][0-9][0-9]");
    if(!rx_regNumber.exactMatch(regNumber)){
        qDebug() << "regNumber "<< regNumber <<" can't be saved to parking list!, wrong regNumber";
        return 0;
    }

    car newCar;
    newCar.enterTime = QDateTime::currentDateTime();
    newCar.regNumber=regNumber;
    m_parking_list.append(newCar);
    m_current_size = m_parking_list.size();
    qDebug() << "regNumber "<< regNumber <<" save to parking list!";
    qDebug() << "enterTime is "<< newCar.enterTime.toString("HH:mm:ss");

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

car Parking::get_car_by_index(int index)
{
    return m_parking_list.at(index);
}

bool Parking::setParkingTime(QString regNumber, QDateTime enterTime)
{
    if (!is_car_exist(regNumber)){
        return false;
    }
    
    for (int i=0; i<m_current_size; i++){
        if (m_parking_list[i].regNumber==regNumber){
            m_parking_list[i].enterTime = enterTime;
            
            return true;
        }
    }
    return false;
    
}

