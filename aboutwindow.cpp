#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include "websupportwindow.h"
#include "QUrl"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->BlogButton,SIGNAL(clicked(bool)),this,SLOT(BlogSlot()));
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(ui->QtButton,SIGNAL(clicked(bool)),qApp,SLOT(aboutQt()));
    QObject::connect(ui->FeedBackButton,SIGNAL(clicked(bool)),this,SLOT(FeedBackSlot()));
    this->logo.load("718logo.jpg");
    this->zzs.load("zzslogo.jpg");

    ui->logo718->setPixmap(this->logo.scaled(ui->logo718->size()));
    ui->logozzs->setPixmap(this->zzs.scaled(ui->logozzs->size()));

    ui->logo718->show();
    ui->logozzs->show();
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::BlogSlot()
{
  WebSupportWindow WindowBase(this,QUrl(QLatin1String("http://zzshub.cn/")));
  WindowBase.show();
  WindowBase.exec();
}

void AboutWindow::FeedBackSlot()
{
    WebSupportWindow WindowBase(this,QUrl(QLatin1String("http://zzshub.cn/2017/11/13/uper2018开发和反馈/")));
    WindowBase.show();
    WindowBase.exec();
}
