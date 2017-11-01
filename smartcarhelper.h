#ifndef SMARTCARHELPER_H
#define SMARTCARHELPER_H

#include <QDialog>

namespace Ui {
class SmartCarHelper;
}

class SmartCarHelper : public QDialog
{
    Q_OBJECT

public:
    explicit SmartCarHelper(QWidget *parent = 0);
    ~SmartCarHelper();

private:
    Ui::SmartCarHelper *ui;
};


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // SMARTCARHELPER_H
