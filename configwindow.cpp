#include "configwindow.h"
#include "ui_configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->CloseButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}

