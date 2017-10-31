#include "smartcarhelper.h"
#include "ui_smartcarhelper.h"

SmartCarHelper::SmartCarHelper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmartCarHelper)
{
    ui->setupUi(this);
}

SmartCarHelper::~SmartCarHelper()
{
    delete ui;
}
