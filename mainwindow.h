#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutwindow.h"
#include "configwindow.h"
#include "controlwindow.h"
#include <QPixmap>

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
    void AboutSlot();
    void ConfigSlot();
    void ControlSlot();

private:
    Ui::MainWindow *ui;

    QPixmap pix;
};

#endif // MAINWINDOW_H
