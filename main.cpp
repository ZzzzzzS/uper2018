#include "mainwindow.h"
#include <QApplication>
#include "bluetoothhandle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlueToothHandle *BlueToothHandle_t=new BlueToothHandle;
    MainWindow w;
    w.BlueToothHandle_t=BlueToothHandle_t;
    w.show();

    return a.exec();
}
