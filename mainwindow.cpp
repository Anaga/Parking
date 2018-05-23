#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parkModel = new ParkingList();

    QStringList myTestList;
    myTestList << "ABC123" << "bcd234" << "aaa111";
    parkModel->setStringList(myTestList);
    ui->listView->setModel(parkModel);

}

MainWindow::~MainWindow()
{
    delete ui;
}
