#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "parkinglist.h"
#include <QMainWindow>

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Delete_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    ParkingList *parkModel;
};

#endif // MAINWINDOW_H
