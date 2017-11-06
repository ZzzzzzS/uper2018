#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include "serialporthandle.h"

namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = 0);
    serialporthandle *serialporthandle_t;
    ~ConfigWindow();

private slots:
    void ConnectSlot();
    void ScanSlot();
    void SendSlot();
    void ReceiveSlot();

private:
    Ui::ConfigWindow *ui;
};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // CONFIGWINDOW_H
