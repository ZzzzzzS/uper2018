#ifndef ZHANDLE_H
#define ZHANDLE_H

#include <QWidget>
#include <QPushButton>

class ZHandle : public QPushButton
{
public:
    ZHandle();
    ZHandle(QWidget *parent=nullptr):QPushButton(parent)
    {

    }
};

#endif // ZHANDLE_H
