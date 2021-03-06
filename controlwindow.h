﻿#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QDialog>
#include "bluetoothhandle.h"
#include <QString>
#include <QTimer>
#include <QtSensors/QAccelerometer>
#include <QPointF>
#include <zhandle.h>


namespace Ui {
class ControlWindow;
}

class ControlWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = 0);
    BlueToothHandle *BlueToothHandle_t;
    void SetButton();
    ~ControlWindow();


private slots:
    void ReceiveSlot();
    void Function1Slot();
    void Function2Slot();
    void Function3Slot();
    void Function4Slot();
    void SendControlMessageSlot();
    void ReadAcceSlot();
    void StopCarSlot();
private:
    Ui::ControlWindow *ui;
    QString Function1Name;
    QString Function2Name;
    QString Function3Name;
    QString Function4Name;
    QTimer ReadAcceTimer;
    QAccelerometer AcceSensor;
    QPointF AccePoint;

    ZHandle *testButton;
protected:
    void resizeEvent(QResizeEvent *e);

};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // CONTROLWINDOW_H
