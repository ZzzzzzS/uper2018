#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->pix.load("logo.jpg");
    ui->LogoLabel->setPixmap(this->pix.scaled(ui->LogoLabel->size()));
    QObject::connect(ui->AboutButton,SIGNAL(clicked(bool)),this,SLOT(AboutSlot()));
    QObject::connect(ui->BluetoothButton,SIGNAL(clicked(bool)),this,SLOT(ConfigSlot()));
    QObject::connect(ui->RemoteButton,SIGNAL(clicked(bool)),this,SLOT(ControlSlot()));
}

MainWindow::~MainWindow()
{
    delete this->BlueToothHandle_t;
    delete ui;
}

void MainWindow::AboutSlot()
{
    AboutWindow WindowBase;
    WindowBase.showFullScreen();
    WindowBase.exec();
}

void MainWindow::ConfigSlot()
{
    ConfigWindow WindowBase;
    WindowBase.BlueToothHandle_t=this->BlueToothHandle_t;
    WindowBase.showFullScreen();
    WindowBase.exec();
}

void MainWindow::ControlSlot()
{
    ControlWindow WindowBase;
    WindowBase.BlueToothHandle_t=this->BlueToothHandle_t;
    WindowBase.SetButton();
    WindowBase.showFullScreen();
    WindowBase.exec();
}
