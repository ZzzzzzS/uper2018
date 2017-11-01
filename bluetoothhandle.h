#ifndef BLUETOOTHHANDLE_H
#define BLUETOOTHHANDLE_H

#include <QObject>

class BlueToothHandle : public QObject
{
    Q_OBJECT
public:
    explicit BlueToothHandle(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BLUETOOTHHANDLE_H