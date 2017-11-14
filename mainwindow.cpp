﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "websupportwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->pix.load("logo.jpg");
    this->setMaximumSize(300,600);
    this->setMinimumSize(300,600);
    QObject::connect(ui->AboutButton,SIGNAL(clicked(bool)),this,SLOT(AboutSlot()));
    QObject::connect(ui->BluetoothButton,SIGNAL(clicked(bool)),this,SLOT(ConfigSlot()));
    QObject::connect(ui->RemoteButton,SIGNAL(clicked(bool)),this,SLOT(ControlSlot()));
    QObject::connect(ui->DebugButton,SIGNAL(clicked(bool)),this,SLOT(HelperSlot()));
    QObject::connect(ui->SettingButton,SIGNAL(clicked(bool)),this,SLOT(SuppotSlot()));
    ui->webEngineView->setUrl(QString("http://code.zzs.gitee.io/uperlogo.png"));
    ui->webEngineView->show();
    this->setMouseTracking(true);
    ui->DebugButton->hide();
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
    WindowBase.show();
    WindowBase.SetButton();//一定不要在构造函数里面初始化蓝牙操作,蓝牙指针是个空指针,除非在构造的时候把蓝牙指针传进去了
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

void MainWindow::SuppotSlot()
{
    WebSupportWindow WindowBase(this,QUrl(QLatin1String("http://code.zzs.gitee.io/2017/11/13/uper2018use/")));
    WindowBase.show();
    WindowBase.exec();
}
