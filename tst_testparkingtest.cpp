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
    void testCaseAddOneCar();
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
void TestParkingTest::testCaseAddOneCar()
{
    QString QsExpectedResults = "";
    QString regNumb = "ABC123";

    Parking parking;

    QsExpectedResults +=regNumb;
    QVERIFY2( parking.add_car(regNumb), "Adding car unseccesfully");
    QVERIFY2( parking.print_parking_list()==QsExpectedResults, "parking list is not ABC123");

    regNumb = "As3";
    QsExpectedResults +=regNumb;
    QVERIFY2( parking.add_car(regNumb), "Adding car unseccesfully");
    qDebug() << " print_parking_list have this value: "<< parking.print_parking_list();
    QVERIFY2( parking.print_parking_list()==QsExpectedResults, "parking list is not ABC123");

    QVERIFY2( parking.remove_car("ABC123"), "Deliting car unseccesfully");
    QVERIFY2( parking.print_parking_list()=="", "parking list is not empty");
    QVERIFY2( parking.size()==0, "Empty parking is not empty!");
}


QTEST_APPLESS_MAIN(TestParkingTest)

#include "tst_testparkingtest.moc"
