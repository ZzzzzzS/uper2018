#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
    //this->AcceSensor.start();
    this->ReadAcceTimer.start(50);
    this->testButton=new ZHandle(ui->TouchAreaWidget);
    testButton->resize(50,50);
    QPixmap icon("wall.png");
    this->testButton->setIcon(icon.scaled(testButton->size()));
    QObject::connect(this->ui->Function1Button,SIGNAL(clicked(bool)),this,SLOT(Function1Slot()));
    QObject::connect(this->ui->Function2Button,SIGNAL(clicked(bool)),this,SLOT(Function2Slot()));
    QObject::connect(this->ui->Function3Button,SIGNAL(clicked(bool)),this,SLOT(Function3Slot()));
    QObject::connect(this->ui->Function4Button,SIGNAL(clicked(bool)),this,SLOT(Function4Slot()));
    QObject::connect(this->ui->StopCarButton,SIGNAL(clicked(bool)),this,SLOT(StopCarSlot()));
    QObject::connect(&this->ReadAcceTimer,SIGNAL(timeout()),this,SLOT(ReadAcceSlot()));
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(ui->AutoFollow,SIGNAL(clicked(bool)),this,SLOT(AutoFollowSlot()));
    this->setMouseTracking(true);
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

void ControlWindow::SetButton()
{
    testButton->SetWindowSize(ui->TouchAreaWidget->width(),ui->TouchAreaWidget->height());
    if(this->serialporthandle_t->isOpen())
    {
       QObject::connect(this->serialporthandle_t,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
}
void ControlWindow::ReceiveSlot()
{
    ui->MessageEdit->append(this->serialporthandle_t->readAll());
}

void ControlWindow::Function1Slot()
{
    this->serialporthandle_t->SafeWrite("F1");
}

void ControlWindow::Function2Slot()
{
    this->serialporthandle_t->SafeWrite("F2");
}

void ControlWindow::Function3Slot()
{
    this->serialporthandle_t->SafeWrite("F3");
}

void ControlWindow::Function4Slot()
{
    this->serialporthandle_t->SafeWrite("F4");
}

void ControlWindow::StopCarSlot()
{

    ui->AutoFollow->setChecked(false);
    this->SendControlMessageSlot(0,0);
    this->serialporthandle_t->SafeWrite("FSTOP");
}

void ControlWindow::ReadAcceSlot()
{

        QPoint MessageToSend;
        MessageToSend.setY(this->testButton->CurrentSpeed.x());
        MessageToSend.setX(-this->testButton->CurrentSpeed.y());

        if(MessageToSend.y()>=100)
        {
            MessageToSend.setY(99);
        }
        else if(MessageToSend.y()<=-100)
        {
            MessageToSend.setY(-99);
        }
        if(MessageToSend.x()>=100)
        {
            MessageToSend.setX(99);
        }
        else if(MessageToSend.x()<=-100)
        {
            MessageToSend.setX(-99);
        }
        SendControlMessageSlot(MessageToSend);

}

void ControlWindow::SendControlMessageSlot(QPoint MessageToSend)
{
    if(this->serialporthandle_t->isOpen())
    {
        this->serialporthandle_t->SafeWrite("X"+QString::number(MessageToSend.x()));
        this->serialporthandle_t->SafeWrite("Y"+QString::number(MessageToSend.y()));
    }
    ui->LeftEdit->setText(QString::number(MessageToSend.x()));
    ui->RightEdit->setText(QString::number(MessageToSend.y()));
}

void ControlWindow::SendControlMessageSlot(int X, int Y)
{
    QPoint Point;
    Point.setX(X);
    Point.setY(Y);
    this->SendControlMessageSlot(Point);
}

void ControlWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Q)
    {
        Function1Slot();
    }
    if(event->key()==Qt::Key_W)
    {
        Function2Slot();
    }
    if(event->key()==Qt::Key_E)
    {
        Function3Slot();
    }
    if(event->key()==Qt::Key_R)
    {
        Function4Slot();
    }
}

void ControlWindow::AutoFollowSlot()
{
    if(ui->AutoFollow->isChecked())
    {
        this->testButton->setMouseTracking(true);
    }
    else
    {
        this->testButton->setMouseTracking(false);
    }

}

void ControlWindow::resizeEvent(QResizeEvent *e)
{
    this->testButton->SetWindowSize(ui->TouchAreaWidget->width(),ui->TouchAreaWidget->height());
}

