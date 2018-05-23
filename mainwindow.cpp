#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parkModel = new ParkingList();

    QStringList myTestList;
    myTestList << "ABC123" << "bcd234" << "aaa111" << "qas234"<<"sdfpdas";
    myTestList << "asdf" << "sdfgedfg";
    parkModel->setStringList(myTestList);
    ui->listView->setModel(parkModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Add_clicked()
{
    parkModel->append(ui->lineEdit->text());
}

void MainWindow::on_pushButton_Delete_clicked()
{
    parkModel->remove(ui->lineEdit->text());
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    qDebug() << "on_listView_clicked QModelIndex is" << index;

    QString qsVal = parkModel->data(index).toString();
    qDebug() << "on_listView_clicked qsVal is" << qsVal <<"Row is" << index.row();
    ui->lineEdit->setText(qsVal);
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "on_listView_doubleClicked QModelIndex is" << index;
        if (!index.isValid()) return;


    QString qsVal = parkModel->data(index).toString();
    qDebug() << "on_listView_doubleClicked qsVal is" << qsVal <<"Row is" << index.row();


    parkModel->remove(qsVal);
}
