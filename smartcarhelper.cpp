#include "smartcarhelper.h"
#include "ui_smartcarhelper.h"

SmartCarHelper::SmartCarHelper(QWidget *parent,serialporthandle *handle) :
    QDialog(parent),
    ui(new Ui::SmartCarHelper)
{
    ui->setupUi(this);
    this->serialporthandle_t=handle;
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

SmartCarHelper::~SmartCarHelper()
{
    delete ui;
}
