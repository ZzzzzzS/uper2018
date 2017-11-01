#ifndef BLUETOOTHHANDLE_H
#define BLUETOOTHHANDLE_H

#include <QObject>
#include <QtBluetooth>
#include <QBluetoothAddress>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QString>
#include <QBluetoothSocket>
#include <QLatin1String>
#include <QtDebug>
#include <QMessageBox>

class BlueToothHandle : public QObject
{
    Q_OBJECT
public:
    explicit BlueToothHandle(QObject *parent = nullptr);
    void scan();
    void Power(bool Power);
    void SafeWrite(QString data);
    void BlueToothConnect(QBluetoothDeviceInfo Base);
    void BlueToothDisConnect();
    QList<QBluetoothDeviceInfo> DeviceInfo;
    QBluetoothSocket *Socket;
    QBluetoothDeviceInfo CurrentDeviceInfo;
    QBluetoothLocalDevice *LocalDevice;
public slots:


private:
    QLatin1String ServiceUuid;
    QBluetoothDeviceDiscoveryAgent *DiscoverAgent;


private slots:
    void Connected();
    void Disconnected();
    void ConnectError();
    void Discoverd(const QBluetoothDeviceInfo &info);

signals:
    void DisCoverdSignal(const QBluetoothDeviceInfo &info);
    void ConnectOK(bool);
    void ConnectNotOK(bool);
    void DisConnetOK(bool);
};

#endif // BLUETOOTHHANDLE_H
