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

#endif // SMARTCARHELPER_H
