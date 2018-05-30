#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parkTab = new ParkingTable();

    parkTab->appendCar("ABC123");
    parkTab->appendCar("ABC111");
    parkTab->appendCar("ABC222");
    parkTab->appendCar("BBB123");
    ui->tableView->setModel(parkTab);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Add_clicked()
{
    qDebug() << "on_pushButton_Add_clicked";
    qDebug() << "ui->lineEdit->text() is" << ui->lineEdit->text();
    parkTab->appendCar(ui->lineEdit->text());
}
