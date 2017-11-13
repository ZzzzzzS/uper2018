#include "websupportwindow.h"
#include "ui_websupportwindow.h"

WebSupportWindow::WebSupportWindow(QWidget *parent,QUrl URL) :
    QDialog(parent),
    ui(new Ui::WebSupportWindow)
{
    ui->setupUi(this);
    linknumber=0;
    ui->webEngineView->load(URL);
    QObject::connect(ui->BackButton,SIGNAL(clicked(bool)),this,SLOT(BackSlot()));
    QObject::connect(ui->webEngineView,SIGNAL(titleChanged(QString)),this,SLOT(SetTitleSlot(QString)));
    QObject::connect(ui->webEngineView,SIGNAL(urlChanged(QUrl)),this,SLOT(LinkChangeSlot(QUrl)));
    ui->webEngineView->show();
}


WebSupportWindow::~WebSupportWindow()
{
    delete ui;
}

void WebSupportWindow::BackSlot()
{
    if(linknumber<=1)
        this->close();
    else
    {
        ui->webEngineView->back();
        this->linknumber-=2;
    }
}

void WebSupportWindow::SetTitleSlot(QString title)
{
    if(title=="about:blank")
       return;
    ui->title->setText(title);
}

void WebSupportWindow::LinkChangeSlot(QUrl link)
{
    if(link.toString()!=QString("about:blank"))
        this->linknumber++;
}
