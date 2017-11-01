#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QDialog>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = 0);
    ~ControlWindow();


private:
    Ui::ControlWindow *ui;
};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // CONTROLWINDOW_H
