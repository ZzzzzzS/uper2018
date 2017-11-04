#ifndef SERIALPORTHANDLE_H
#define SERIALPORTHANDLE_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>


class serialporthandle : public QSerialPort
{
public:
    serialporthandle();

    void scan();
    void Connect();
    void SafeWrite(QString data);
    QList<QSerialPortInfo> DeviceInfo;

    struct
        {
            QString portname;
            char baud;
            char Data;
            char stopbit;
            char parity;
        }settings;
private:


};

#endif // SERIALPORTHANDLE_H
