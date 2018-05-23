#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "parkinglist.h"
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

private:
    Ui::MainWindow *ui;
    ParkingList *parkModel;
};

#endif // MAINWINDOW_H
