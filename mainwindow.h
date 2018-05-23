#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <parkinglist.h>

#include <QMainWindow>

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
    void on_pushButton_Insert_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::MainWindow *ui;

    parkingList *parList;

};

#endif // MAINWINDOW_H
