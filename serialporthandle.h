#ifndef SERIALPORTHANDLE_H
#define SERIALPORTHANDLE_H

#include <QObject>

class serialporthandle : public QSerialPort
{
public:
    serialporthandle();
};

#endif // SERIALPORTHANDLE_H