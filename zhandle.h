#ifndef ZHANDLE_H
#define ZHANDLE_H

#include <QWidget>
#include <QPushButton>
#include <QTouchEvent>
#include <QPoint>

class ZHandle : public QPushButton
{
public:
    ZHandle();
    ZHandle(QWidget *parent=nullptr):QPushButton(parent)
    {

    }
private:
    QPoint WindowPoint;
protected:
    void mouseMoveEvent(QMouseEvent*e);
    void mousePressEvent(QMouseEvent*e);
};

#endif // ZHANDLE_H
