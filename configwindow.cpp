#include "configwindow.h"
#include "ui_configwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

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
    if(ui->ConnectButton->text()=="打开串口")
        {
            QMessageBox a;
            a.setIcon(QMessageBox::Information);
            a.setWindowTitle("正在打开串口");
            a.show();

            this->serialporthandle_t->settings.baud=ui->SpeedBox->currentIndex();
            this->serialporthandle_t->settings.portname=ui->ConnectBox->currentText();
            this->serialporthandle_t->Connect();
            a.close();
            if(this->serialporthandle_t->isOpen())
            {
                ui->ConnectButton->setText("关闭串口");
                QObject::connect(this->serialporthandle_t,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
            }
            else
            {
                QMessageBox::information(this,"串口可能未打开","请检查设备是否未连接或被其他程序占用",QMessageBox::Yes);
                ui->ConnectButton->setText("打开串口");
                QObject::disconnect(this->serialporthandle_t,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
            }
        }
        else if(ui->ConnectButton->text()=="关闭串口")
        {
            QObject::disconnect(this->serialporthandle_t,SIGNAL(readyRead()),this,SLOT(ReceiveSlot()));
            QMessageBox a;
            a.setIcon(QMessageBox::Information);
            a.setWindowTitle("正在关闭串口");
            a.show();

            this->serialporthandle_t->clear();
            this->serialporthandle_t->close();
        }
}


//蓝牙扫描函数
void ConfigWindow::ScanSlot()
{
    this->ui->ConnectBox->clear();
    this->serialporthandle_t->scan();
    foreach (QSerialPortInfo info, this->serialporthandle_t->DeviceInfo)
    {
        ui->ConnectBox->addItem(info.portName());
    }

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

    this->serialporthandle_t->SafeWrite(ui->SendArea->text().toLatin1());
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
            QByteArray buf=this->serialporthandle_t->read(1);
            QString str=" "+buf.toHex();
            ui->ReceiveArea->insertPlainText(str);
            buf.clear();
        }
        else if(!ui->HEXBox->isChecked())
        {
            ui->ReceiveArea->append(this->serialporthandle_t->readAll());
        }
}

