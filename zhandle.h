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
        centerPoint.setX(400);   //设置圆心X坐标
        centerPoint.setY(250);   //设置圆心Y坐标
        this->move(centerPoint);
        r = 150;      //设置圆的半径
    }

    QPoint CurrentSpeed;
private:
    QPoint WindowPoint;
    QPoint centerPoint;
    double r;
protected:
    void mouseMoveEvent(QMouseEvent*e);
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // ZHANDLE_H
