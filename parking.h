#ifndef PARKING_H
#define PARKING_H

#include <QObject>
#include <QStringList>
#include <QDateTime>

typedef struct {
    QString regNumber;
    QDateTime enterTime;
    QDateTime exitTime;
    bool addOneHour;
} car;

class Parking : public QObject
{
    Q_OBJECT

private:
    int m_parking_max=25;
    int m_current_size=0;
    QList<car> m_parking_list;


public:
    explicit Parking(QObject *parent = nullptr);
    int size();
    int max_size();
    int add_car(QString regNumber);
    int remove_car(QString regNumber);
    QString print_parking_list();



signals:

public slots:
};

#endif // PARKING_H
