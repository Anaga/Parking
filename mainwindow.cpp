#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parList = new parkingList();
    QStringList list;
    list << "abc123" << "bcd234" << "ABCD23";
    parList->setStringList(list);

    ui->listView->setModel(parList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Insert_clicked()
{
    parList->append(ui->lineEdit->text());
}

void MainWindow::on_pushButton_delete_clicked()
{
    parList->remove(ui->lineEdit->text());
}
