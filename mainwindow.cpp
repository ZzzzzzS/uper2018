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
    QObject::connect(ui->DebugButton,SIGNAL(clicked(bool)),this,SLOT(HelperSlot()));
    this->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete this->serialporthandle_t;
    delete ui;
}

void MainWindow::AboutSlot()
{
    AboutWindow WindowBase;
    WindowBase.show();
    WindowBase.exec();
}

void MainWindow::ConfigSlot()
{
    ConfigWindow WindowBase;
    WindowBase.serialporthandle_t=this->serialporthandle_t;
    WindowBase.show();
    WindowBase.exec();
}

void MainWindow::ControlSlot()
{
    this->hide();
    ControlWindow WindowBase;
    WindowBase.serialporthandle_t=this->serialporthandle_t;
    WindowBase.SetButton();//一定不要在构造函数里面初始化蓝牙操作,蓝牙指针是个空指针,除非在构造的时候把蓝牙指针传进去了
    WindowBase.show();
    WindowBase.exec();
    this->show();
}

void MainWindow::HelperSlot()
{
    this->hide();
    SmartCarHelper WindowBase(this,this->serialporthandle_t);
    WindowBase.show();
    WindowBase.exec();
    this->show();
}
