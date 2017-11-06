#include "mainwindow.h"
#include <QApplication>
#include "serialporthandle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serialporthandle *serialporthandle_t=new serialporthandle;
    MainWindow w;
    w.serialporthandle_t=serialporthandle_t;
    w.show();

    return a.exec();
}
