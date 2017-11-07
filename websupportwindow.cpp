#include "websupportwindow.h"
#include "ui_websupportwindow.h"


WebSupportWindow::WebSupportWindow(QWidget *parent,QUrl URL) :
    QDialog(parent),
    ui(new Ui::WebSupportWindow)
{
    ui->setupUi(this);
    QUrl source("qrc:webEngineView.qml");
    ui->webEngineView->setSource(QUrl::fromLocalFile("webEngineView.qml"));
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

