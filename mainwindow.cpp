#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap a;
    QUrl b("qrc:logo.jpg");
    a.load(b.toLocalFile());
    ui->Logolabel->setPixmap(a);
    QObject::connect(ui->AboutButton,SIGNAL(clicked(bool)),this,SLOT(AboutSlot()));
    QObject::connect(ui->BluetoothButton,SIGNAL(clicked(bool)),this,SLOT(ConfigSlot()));
    QObject::connect(ui->RemoteButton,SIGNAL(clicked(bool)),this,SLOT(ControlSlot()));
    QObject::connect(ui->DebugButton,SIGNAL(clicked(bool)),this,SLOT(HelperSlot()));
    QObject::connect(ui->SettingButton,SIGNAL(clicked(bool)),this,SLOT(SupportSlot()));
    this->setMouseTracking(true);
    ui->DebugButton->hide();
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
    WindowBase.SetButton();//一定不要在构造函数里面初始化蓝牙操作,蓝牙指针是个空指针,除非在构造的时候把蓝牙指针传进去了
    WindowBase.showFullScreen();
    WindowBase.exec();
    this->show();
}

void MainWindow::HelperSlot()
{
    this->hide();
    SmartCarHelper WindowBase(this,this->BlueToothHandle_t);
    WindowBase.showFullScreen();
    WindowBase.exec();
    this->show();
}

void MainWindow::SupportSlot()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://code.zzs.gitee.io/2017/11/13/uper2018use/")));
}
