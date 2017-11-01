#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

ControlWindow::~ControlWindow()
{
    delete ui;
}
