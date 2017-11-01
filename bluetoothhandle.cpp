#include "bluetoothhandle.h"

BlueToothHandle::BlueToothHandle(QObject *parent) : QObject(parent)
{
    this->ServiceUuid=QLatin1String("00001101-0000-1000-8000-00805F9B34FB");//保存蓝牙UUID
    this->LocalDevice=new QBluetoothLocalDevice();
    this->DiscoverAgent=new QBluetoothDeviceDiscoveryAgent();
    this->Socket=new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);//配置蓝牙传输模式为串口模式
}

//打开关闭蓝牙函数
void BlueToothHandle::Power(bool Power)
{
    if(Power==true)
    {
        this->LocalDevice->powerOn();//开机
    }
    else if(Power==false)
        this->LocalDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);//关机
}

//蓝牙连接函数
void BlueToothHandle::BlueToothConnect(QBluetoothDeviceInfo Base)
{
    QObject::disconnect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
    this->Socket->connectToService(Base.address(),QBluetoothUuid(this->ServiceUuid));
    QObject::connect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
}

//蓝牙连接成功提示函数
void BlueToothHandle::Connected()
{
    QMessageBox::information(NULL,"连接","已连接成功!",QMessageBox::Ok);
    QObject::disconnect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
    emit this->ConnectOK(true);
}

//蓝牙连接错误提示函数
void BlueToothHandle::ConnectError()
{
    QMessageBox::information(NULL,"连接","连接失败,请检查设备",QMessageBox::Ok);
    QObject::disconnect(this->Socket,SIGNAL(connected()),this,SLOT(Connected()));
    emit this->ConnectNotOK(true);
}


//蓝牙断开函数
void BlueToothHandle::BlueToothDisConnect()
{
    QObject::disconnect(this->Socket,SIGNAL(disconnected()),this,SLOT(Disconnected()));
    this->Socket->disconnectFromService();
    QObject::connect(this->Socket,SIGNAL(disconnected()),this,SLOT(Disconnected()));
}

//蓝牙断开成功提示函数
void BlueToothHandle::Disconnected()
{
    QMessageBox::information(NULL,"断开","已断开成功!",QMessageBox::Ok);
    emit this->DisConnetOK(true);
}

//安全读写函数,不打开蓝牙就会提示
void BlueToothHandle::SafeWrite(QString data)
{
    if(this->Socket->state()==QBluetoothSocket::ConnectedState)
    {
        Socket->write(data.toUtf8());
    }
    else if(this->Socket->state()==QBluetoothSocket::UnconnectedState)
    {
        QMessageBox::information(NULL,"蓝牙未连接","请连接蓝牙或检查是否被其他程序占用",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(NULL,"错误","请检查蓝牙是否打开",QMessageBox::Ok);
    }
}

//查找蓝牙设备函数
void BlueToothHandle::scan()
{
    if(this->LocalDevice->hostMode()==QBluetoothLocalDevice::HostPoweredOff)
    {
        QMessageBox::information(NULL,"蓝牙未打开","请打开蓝牙后重试",QMessageBox::Ok);
    }
    QObject::disconnect(this->DiscoverAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(Discoverd(QBluetoothDeviceInfo)));
    this->DeviceInfo.clear();
    this->DiscoverAgent->stop();
    this->DiscoverAgent->start();
    QObject::connect(this->DiscoverAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(Discoverd(QBluetoothDeviceInfo)));
}

//找到蓝牙函数
void BlueToothHandle::Discoverd(const QBluetoothDeviceInfo &info)
{

    this->DeviceInfo.append(info);
    emit DisCoverdSignal(info);
}

