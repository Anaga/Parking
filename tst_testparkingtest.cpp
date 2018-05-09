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
    QVERIFY2( parking.print_parking_list()==regNumb, "Parking list is not ABC123");

    QVERIFY2( parking.remove_car("ABC123"), "Deliting car unseccesfully");
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

    regNumb = "DEF456";
    QsExpectedResults +=regNumb;
    QVERIFY2( parking.add_car(regNumb), "Adding second car unseccesfully");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();
    QVERIFY2( parking.print_parking_list()==QsExpectedResults, "parking list is not ABC123DEF456");

    QVERIFY2( parking.remove_car(regNumb), "Deliting first car unseccesfully");
    QVERIFY2( parking.remove_car("ABC123"), "Deliting second car unseccesfully");

    QVERIFY2( parking.print_parking_list()=="", "Parking list after remove all 2 cars is not empty");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");
}


void TestParkingTest::testCaseAddWrongCarsNumbers()
{
    QString regNumb = "ABC123456";

    Parking parking;

    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with long reg number");

    regNumb = "DE45894448";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with short reg number");


    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();
    QVERIFY2( parking.print_parking_list()=="", "Parking list after 2 wrong  cars rec numbers is not empty");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");

    QEXPECT_FAIL("", "Will fix in the next release", Continue);
    regNumb = "ABC-124";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with minus sign reg number");
    regNumb = "abcdef";
    QVERIFY2( parking.add_car(regNumb)==0, "Adding car seccesfully with small letters reg number");


}

QTEST_APPLESS_MAIN(TestParkingTest)

#include "tst_testparkingtest.moc"
