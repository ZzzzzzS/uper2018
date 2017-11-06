#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutwindow.h"
#include "configwindow.h"
#include "controlwindow.h"
#include "serialporthandle.h"
#include "smartcarhelper.h"
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    serialporthandle *serialporthandle_t;
    ~MainWindow();

private slots:
    void AboutSlot();
    void ConfigSlot();
    void ControlSlot();
    void HelperSlot();

private:
    Ui::MainWindow *ui;

    QPixmap pix;
};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // MAINWINDOW_H
