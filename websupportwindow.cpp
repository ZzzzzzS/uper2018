#include "websupportwindow.h"
#include "ui_websupportwindow.h"


WebSupportWindow::WebSupportWindow(QWidget *parent,QUrl URL) :
    QDialog(parent),
    ui(new Ui::WebSupportWindow)
{
    ui->setupUi(this);

    QUrl source("qrc:logo.qml");
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->quickWidget->setSource(source);
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(BackSlot()));
}


WebSupportWindow::~WebSupportWindow()
{
    delete ui;
}

void WebSupportWindow::BackSlot()
{
    this->close();
}

void WebSupportWindow::load()
{

}
