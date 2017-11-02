#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
    this->AcceSensor.start();
    this->ReadAcceTimer.start(100);
    /*if(this->BlueToothHandle_t->Socket->state()==QBluetoothSocket::ConnectedState)
    {
       QObject::connect(this->BlueToothHandle_t->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }*/
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
    ui->LeftEdit->setText(QString::number(AccePoint.x()));
    ui->RightEdit->setText(QString::number(AccePoint.y()));
}

void ControlWindow::SendControlMessageSlot()
{

}
