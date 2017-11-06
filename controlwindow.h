#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QDialog>
#include "serialporthandle.h"
#include <QString>
#include <QTimer>
#include <QPointF>
#include <zhandle.h>
#include <QKeyEvent>


namespace Ui {
class ControlWindow;
}

class ControlWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = 0);
    serialporthandle *serialporthandle_t;
    void SetButton();
    ~ControlWindow();


private slots:
    void ReceiveSlot();
    void Function1Slot();
    void Function2Slot();
    void Function3Slot();
    void Function4Slot();
    void SendControlMessageSlot(QPoint MessageToSend);
    void SendControlMessageSlot(int X,int Y);
    void ReadAcceSlot();
    void StopCarSlot();
    void AutoFollowSlot();
private:
    Ui::ControlWindow *ui;
    QString Function1Name;
    QString Function2Name;
    QString Function3Name;
    QString Function4Name;
    QTimer ReadAcceTimer;
    QPointF AccePoint;

    ZHandle *testButton;
protected:
    void keyPressEvent(QKeyEvent *event);

};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // CONTROLWINDOW_H
