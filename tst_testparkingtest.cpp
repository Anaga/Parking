#include <QString>
#include <QtTest>
#include "parking.h"

class TestParkingTest : public QObject
{
    Q_OBJECT

public:
    TestParkingTest();

private Q_SLOTS:
    void testCaseEmptyParking();
    void testCaseAddAndDeleteOneCar();
    void testCaseAddAndDeleteTwoCars();
    void testCaseAddWrongCarsNumbers();
    void testCaseIsCarOnEmptyParking();
    void testCaseGetCars();
    void testCaseTryToAddMoreThan25Cars();
    void testCaseAddSameCars();
};

TestParkingTest::TestParkingTest()
{
}

void TestParkingTest::testCaseEmptyParking()
{
    Parking parking;
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");
    QVERIFY2( parking.max_size() == 25, "Empty parking Max size is not 25!");
    QVERIFY2( parking.print_parking_list()=="", "Empty parking parking list is not empty");
}

void TestParkingTest::testCaseAddAndDeleteOneCar()
{
    QString regNumb = "ABC589";
    Parking parking;

    QVERIFY2( parking.add_car(regNumb), "Adding car unseccesfully");
    qDebug() <<  parking.print_parking_list();
    QVERIFY2( parking.print_parking_list().contains(regNumb), "Parking list is not ABC123");
    QVERIFY2( parking.size()==1, "parking size is not 1!");

    QVERIFY2( parking.remove_car("ABC589"), "Deliting car unseccesfully");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");
    qDebug() <<  parking.print_parking_list();
    QVERIFY2( parking.print_parking_list()=="", "Parking list after remove is not empty");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");
}

void TestParkingTest::testCaseAddAndDeleteTwoCars()
{
    QString QsExpectedResults = "";
    QString regNumb = "ABC123";

    Parking parking;

    QsExpectedResults +=regNumb;
    QVERIFY2( parking.add_car(regNumb), "Adding first car unseccesfully");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

    regNumb = "DEF456";
    QsExpectedResults +=regNumb;
    QVERIFY2( parking.add_car(regNumb), "Adding second car unseccesfully");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();
    QVERIFY2( parking.print_parking_list()==QsExpectedResults, "parking list is not ABC123DEF456");

    QVERIFY2( parking.remove_car(regNumb), "Deliting first car unseccesfully");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

    QVERIFY2( parking.remove_car("ABC123"), "Deliting second car unseccesfully");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

    QVERIFY2( parking.print_parking_list()=="", "Parking list after remove all 2 cars is not empty");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

}

void TestParkingTest::testCaseIsCarOnEmptyParking(){
    Parking parking;
    QString regNumb = "ABC123";
    QVERIFY2(parking.is_car_exist(regNumb)== false, "car exist in empty paring");
    parking.add_car(regNumb);
    QVERIFY2(parking.is_car_exist(regNumb)== true, "Now car ABC124 exist in paring");

}

void TestParkingTest::testCaseAddWrongCarsNumbers()
{
    QString regNumb = "ABC1234";
    Parking parking;

    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with long reg number");
    regNumb = "DE45";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with short reg number");


    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();
    QVERIFY2( parking.print_parking_list()=="", "Parking list after 2 wrong  cars rec numbers is not empty");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");

    regNumb = "ABC-124----";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with minus sign reg number");

    regNumb = "ABC+124";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with minus sign reg number");

    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

    regNumb = "+-+-+-";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with +-+-+- reg number");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

    regNumb = "abcdef";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with small letters reg number");

    regNumb = "aAcd2f";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with small letters reg number");

}

void TestParkingTest::testCaseGetCars()
{
    QString regNumb = "ABC123";
    Parking parking;

    parking.add_car(regNumb);
    regNumb = "ABC124";
    parking.add_car(regNumb);
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();

    QVERIFY2( parking.print_parking_list()=="ABC123ABC124","Now car ABC124 exist in paring");

    car testCar;
    testCar = parking.get_car_by_number("ABC123");
    qDebug() << " testCar.regNumber " << testCar.regNumber;

    QVERIFY2("ABC123" ==testCar.regNumber, "test car not ABC123");
    qDebug() << testCar.enterTime.toString("dd.MM.yyyy hh:mm:ss ");

    testCar = parking.get_car_by_number("BBC123");
    qDebug() << " testCar.regNumber " << testCar.regNumber;

    QVERIFY2("No car" ==testCar.regNumber, "test car not *No car*, shall be uknow");
}

void TestParkingTest::testCaseTryToAddMoreThan25Cars()
{
    Parking parking;
    QString regNumb = "ABC001";
    parking.add_car(regNumb);
    regNumb = "ABC002";
    parking.add_car(regNumb);
    regNumb = "ABC003";
    parking.add_car(regNumb);
    regNumb = "ABC004";
    parking.add_car(regNumb);
    regNumb = "ABC005";
    parking.add_car(regNumb);
    regNumb = "ABC006";
    parking.add_car(regNumb);
    regNumb = "ABC007";
    parking.add_car(regNumb);
    regNumb = "ABC008";
    parking.add_car(regNumb);
    regNumb = "ABC009";
    parking.add_car(regNumb);
    regNumb = "ABC010";
    parking.add_car(regNumb);
    regNumb = "ABC011";
    parking.add_car(regNumb);
    regNumb = "ABC012";
    parking.add_car(regNumb);
    regNumb = "ABC013";
    parking.add_car(regNumb);
    regNumb = "ABC014";
    parking.add_car(regNumb);
    regNumb = "ABC015";
    parking.add_car(regNumb);
    regNumb = "ABC016";
    parking.add_car(regNumb);
    regNumb = "ABC017";
    parking.add_car(regNumb);
    regNumb = "ABC018";
    parking.add_car(regNumb);
    regNumb = "ABC019";
    parking.add_car(regNumb);
    regNumb = "ABC020";
    parking.add_car(regNumb);
    regNumb = "ABC021";
    parking.add_car(regNumb);
    regNumb = "ABC022";
    parking.add_car(regNumb);
    regNumb = "ABC023";
    parking.add_car(regNumb);
    regNumb = "ABC024";
    parking.add_car(regNumb);
    regNumb = "ABC025";
    parking.add_car(regNumb);
    regNumb = "ABC026";
    QVERIFY2( parking.add_car(regNumb)==0, "Impossible to add more cars than places in parking!");
}

void TestParkingTest::testCaseAddSameCars(){
    Parking parking;
    QString regNumb = "ABC123";
    QVERIFY2(parking.add_car(regNumb)== true, "Car should be added to parking");
    QVERIFY2(parking.add_car(regNumb)== false, "Impossible to add the same car");
}


QTEST_APPLESS_MAIN(TestParkingTest)

#include "tst_testparkingtest.moc"
