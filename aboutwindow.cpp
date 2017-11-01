#include "aboutwindow.h"
#include "ui_aboutwindow.h"
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
  QDesktopServices::openUrl(QUrl(QLatin1String("http://zzshub.cn/")));
}

void AboutWindow::FeedBackSlot()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://zzshub.cn/")));
}
