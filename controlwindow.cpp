#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
    this->AcceSensor.start();
    this->ReadAcceTimer.start(50);
    this->testButton=new ZHandle(ui->TouchAreaWidget);
    QObject::connect(this->ui->Function1Button,SIGNAL(clicked(bool)),this,SLOT(Function1Slot()));
    QObject::connect(this->ui->Function2Button,SIGNAL(clicked(bool)),this,SLOT(Function2Slot()));
    QObject::connect(this->ui->Function3Button,SIGNAL(clicked(bool)),this,SLOT(Function3Slot()));
    QObject::connect(this->ui->Function4Button,SIGNAL(clicked(bool)),this,SLOT(Function4Slot()));
    QObject::connect(this->ui->StopCarButton,SIGNAL(clicked(bool)),this,SLOT(StopCarSlot()));
    QObject::connect(&this->ReadAcceTimer,SIGNAL(timeout()),this,SLOT(ReadAcceSlot()));
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

ControlWindow::~ControlWindow()
{
    delete ui;
}


void ControlWindow::SetButton()
{
    if(this->BlueToothHandle_t->Socket->state()==QBluetoothSocket::ConnectedState)
    {
       QObject::connect(this->BlueToothHandle_t->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
}
void ControlWindow::ReceiveSlot()
{
    ui->MessageEdit->append(this->BlueToothHandle_t->Socket->readAll());
}

void ControlWindow::Function1Slot()
{
    this->BlueToothHandle_t->SafeWrite("F1");
}

void ControlWindow::Function2Slot()
{
    this->BlueToothHandle_t->SafeWrite("F2");
}

void ControlWindow::Function3Slot()
{
    this->BlueToothHandle_t->SafeWrite("F3");
}

void ControlWindow::Function4Slot()
{
    this->BlueToothHandle_t->SafeWrite("F4");
}

void ControlWindow::StopCarSlot()
{
    this->BlueToothHandle_t->SafeWrite("FSTOP");
}

void ControlWindow::ReadAcceSlot()
{
    AccePoint.setX(this->AcceSensor.reading()->x());
    AccePoint.setY(this->AcceSensor.reading()->y());

    QPoint MessageToSend;
    if(ui->GControlBox->isChecked())
    {
        AccePoint.setX(AccePoint.x()-5);
        if(AccePoint.x()<0.3&&AccePoint.x()>-0.3)
        {
            AccePoint.setX(0);
        }
        if(AccePoint.y()<0.1&&AccePoint.y()>-0.1)
        {
            AccePoint.setY(0);
        }

        MessageToSend.setX(-AccePoint.x()*20);
        if(MessageToSend.x()>=100)
        {
            MessageToSend.setX(99);
        }
        else if(MessageToSend.x()<=-100)
        {
            MessageToSend.setX(-99);
        }

        MessageToSend.setY(AccePoint.y()*20);
        if(MessageToSend.y()>=100)
        {
            MessageToSend.setY(99);
        }
        else if(MessageToSend.y()<=-100)
        {
            MessageToSend.setY(-99);
        }

        if(this->BlueToothHandle_t->Socket->state()==QBluetoothSocket::ConnectedState)
        {
            this->BlueToothHandle_t->SafeWrite("X"+QString::number(MessageToSend.x()));
            this->BlueToothHandle_t->SafeWrite("Y"+QString::number(MessageToSend.y()));
        }
    }
    ui->LeftEdit->setText(QString::number(MessageToSend.x()));
    ui->RightEdit->setText(QString::number(MessageToSend.y()));
}

void ControlWindow::SendControlMessageSlot()
{

}
