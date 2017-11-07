﻿#include "aboutwindow.h"
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
    QDesktopServices::openUrl(QUrl(QLatin1String("http://zzshub.cn/")));
}
