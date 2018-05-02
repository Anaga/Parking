# Parking
Application for big parking lot.

We will use QList'<car'> for holding cars on parking lot.
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


Home task:

In file parking.cpp, 
in function 
int Parking::add_car(QString regNumber)
1) add check for Registation Number format.
Format shall be 3 capital leters from A-Z, and then 3 numbrs.

2) add regNumber to parking_list only if this number NOT in list, and parking lot is not full - less than 25.


Write a new test case in file tst_testparkingtest.cpp to VERIFY fuction add_car.
