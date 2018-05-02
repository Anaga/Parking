# Parking
Application for big parking lot.

We will use QList<car> for holding cars on parking lot.
Cars it is a struct:
```
typedef struct {
    QString regNumber;
    QDateTime enterTime;
    QDateTime exitTime;
    bool addOneHour;
} car;
```

Class parking_lot will have this internal varaibles
```
int m_parking_max=25;
int m_current_size=0;
QList<car> m_parking_list;
```
and public functions
```
int size();
int max_size();
int add_car(QString regNumber);
int remove_car(QString regNumber);
QString print_parking_list();
```
