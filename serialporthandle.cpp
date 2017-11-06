#include "serialporthandle.h"
#include <QMessageBox>

serialporthandle::serialporthandle()
{
    this->DeviceInfo.clear();
    this->DeviceInfo=QSerialPortInfo::availablePorts();
}


void serialporthandle::scan()
{
    this->DeviceInfo.clear();                                  //先清除列表
    this->DeviceInfo=QSerialPortInfo::availablePorts();        //读取串口信息
}

void serialporthandle::Connect()
{

       this->setPortName(this->settings.portname);
       this->open(QIODevice::ReadWrite);

    this->settings.stopbit=QSerialPort::OneStop;
    this->settings.Data=QSerialPort::Data8;
    this->settings.parity=QSerialPort::NoParity;

       switch(this->settings.baud)
       {
       case 0:
           this->setBaudRate(QSerialPort::Baud9600);
           break;
       case 1:
           this->setBaudRate(QSerialPort::Baud19200);
           break;
       case 2:
           this->setBaudRate(QSerialPort::Baud38400);
           break;
       case 3:
           this->setBaudRate(QSerialPort::Baud57600);
           break;
       case 4:
           this->setBaudRate(QSerialPort::Baud115200);
           break;
       }

       switch(this->settings.Data)
       {
       case 0:
           this->setDataBits(QSerialPort::Data8);
           break;
       case 1:
           this->setDataBits(QSerialPort::Data7);
           break;
       case 2:
           this->setDataBits(QSerialPort::Data6);
           break;
       case 3:
           this->setDataBits(QSerialPort::Data5);
           break;
       }

       switch(this->settings.stopbit)
       {
       case 0:
           this->setStopBits(QSerialPort::OneStop);
           break;
       case 1:
           this->setStopBits(QSerialPort::TwoStop);
           break;
       }

       switch(this->settings.parity)
       {
       case 0:
           this->setParity(QSerialPort::NoParity);
           break;
       case 1:
           this->setParity(QSerialPort::OddParity);
           break;
       case 2:
           this->setParity(QSerialPort::EvenParity);
           break;
       }
}


void serialporthandle::SafeWrite(QString data)
{
    if(!this->isOpen())
    {
        QMessageBox a;
        a.setIcon(QMessageBox::Information);
        a.setWindowTitle("请打开串口");
        a.setText("串口可能未打开");
        a.show();
        a.exec();
        return;
    }
    this->write(data.toLocal8Bit());
}
