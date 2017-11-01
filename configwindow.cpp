#include "configwindow.h"
#include "ui_configwindow.h"
#include <QDesktopServices>
#include <QUrl>

ConfigWindow::ConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->CloseButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(ui->ConnectButton,SIGNAL(clicked(bool)),this,SLOT(ConnectSlot()));
    QObject::connect(ui->ScanButton,SIGNAL(clicked(bool)),this,SLOT(ScanSlot()));
    QObject::connect(ui->SendButton,SIGNAL(clicked(bool)),this,SLOT(SendSlot()));
}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}

//连接函数
void ConfigWindow::ConnectSlot()
{
    if(ui->ConnectBox->currentText().isEmpty())//判断蓝牙
        {
            QMessageBox::information(this,"蓝牙未连接","请重新扫描蓝牙后重试",QMessageBox::Ok);
            return;
        }

    QObject::disconnect(this->BlueToothHandle_t,SIGNAL(ConnectOK(bool)),this,SLOT(ConnetOKSlot(bool)));
    QObject::disconnect(this->BlueToothHandle_t,SIGNAL(DisConnetOK(bool)),this,SLOT(DisconnetOKSlot(bool)));
    QObject::disconnect(this->BlueToothHandle_t,SIGNAL(ConnectNotOK(bool)),this,SLOT(ConnectErrorSlot()));
    QObject::connect(this->BlueToothHandle_t,SIGNAL(ConnectOK(bool)),this,SLOT(ConnetOKSlot(bool)));
    QObject::connect(this->BlueToothHandle_t,SIGNAL(DisConnetOK(bool)),this,SLOT(DisconnetOKSlot(bool)));
    QObject::connect(this->BlueToothHandle_t,SIGNAL(ConnectNotOK(bool)),this,SLOT(ConnectErrorSlot()));

    if(ui->ConnectButton->text()=="连接")
    {
        this->BlueToothHandle_t->BlueToothConnect(this->BlueToothHandle_t->DeviceInfo.at(ui->ConnectBox->currentIndex()));
        ui->ConnectButton->setText("正在连接");
        QObject::connect(this->BlueToothHandle_t->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
    else if(ui->ConnectButton->text()=="断开")
    {
        this->BlueToothHandle_t->BlueToothDisConnect();
        ui->ConnectButton->setText("正在断开");
        QObject::disconnect(this->BlueToothHandle_t->Socket,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
    }
}


//蓝牙扫描函数
void ConfigWindow::ScanSlot()
{
    if(ui->ConnectButton->text()=="断开")
       {
           if(QMessageBox::warning(this,"蓝牙已连接","蓝牙已连接,此时搜索可能会导致连接断开,确定要继续吗?",QMessageBox::Yes,QMessageBox::No)==QMessageBox::No)
               return;
       }
    qDebug()<<"ok1";
       ui->ConnectBox->clear();
       qDebug()<<"ok2";
       QObject::disconnect(this->BlueToothHandle_t,SIGNAL(DisCoverdSignal(QBluetoothDeviceInfo)),this,SLOT(DisCoveredSlot(QBluetoothDeviceInfo)));
       qDebug()<<"ok10 ";
       this->BlueToothHandle_t->scan();
       qDebug()<<"ok3";
       QObject::connect(this->BlueToothHandle_t,SIGNAL(DisCoverdSignal(QBluetoothDeviceInfo)),this,SLOT(DisCoveredSlot(QBluetoothDeviceInfo)));
}

//蓝牙发送函数
void ConfigWindow::SendSlot()
{
    if(ui->SendArea->text().isEmpty())
    {
        if(QMessageBox::question(this,tr("当前发送区无内容"),"您确定要发送空内容吗?",QMessageBox::Cancel|QMessageBox::Ok)==QMessageBox::Cancel)
        {
            return;
        }
    }

    //以下有几个小彩蛋
    QString test=ui->SendArea->text();
    if(test=="Author")//作者彩蛋
    {
        QMessageBox::information(this,"软件作者:","Powered By ZZS",QMessageBox::Ok);
        return;
    }
    else if(test=="About Qt")
    {
        qApp->aboutQt();
        return;
    }
    else if(test=="About")
    {
        QMessageBox::information(this,"718联合创新创业基地","此软件由哈工大718创新实验室开发",QMessageBox::Ok);
        QDesktopServices::openUrl(QUrl("https://github.com/ZzzzzzS/uper2018"));
        return;
    }

    this->BlueToothHandle_t->SafeWrite(ui->SendArea->text().toLatin1());
    ui->ReceiveArea->append("上位机:"+ui->SendArea->text());
    if(ui->AutoCleanBox->isChecked())
    {
        ui->SendArea->clear();
    }
}

void ConfigWindow::ReceiveSlot()
{
    if(ui->HEXBox->isChecked())
        {
            QByteArray buf=this->BlueToothHandle_t->Socket->read(1);
            QString str=" "+buf.toHex();
            ui->ReceiveArea->insertPlainText(str);
            buf.clear();
        }
        else if(!ui->HEXBox->isChecked())
        {
            ui->ReceiveArea->append(this->BlueToothHandle_t->Socket->readAll());
        }
}

void ConfigWindow::DisCoveredSlot(const QBluetoothDeviceInfo &info)
{
    ui->ConnectBox->addItem(info.name().toUtf8());
}


void ConfigWindow::DisconnetOKSlot(bool ok)
{
    if(ok)
    ui->ConnectButton->setText("连接");
}

void ConfigWindow::ConnetOKSlot(bool ok)
{
    if(ok)
    ui->ConnectButton->setText("断开");
}

void ConfigWindow::ConnectErrorSlot()
{
    ui->ConnectButton->setText("断开");
    this->ConnectSlot();
}
