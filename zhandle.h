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
        this->centerPoint.setY(parent->height());
        this->centerPoint.setX(parent->width());
        centerPoint.setX(this->centerPoint.x()/2);   //设置圆心X坐标
        centerPoint.setY(this->centerPoint.x()/2);   //设置圆心Y坐标
        this->move(centerPoint);
        r = 100;      //设置圆的半径
        rate=1;
    }
    void SetWindowSize(int X, int Y);
    QPoint CurrentSpeed;

private:
    QPoint centerPoint;
    QPoint WindowPoint;

    double r;
    double rate;
protected:
    void mouseMoveEvent(QMouseEvent*e);
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent *e);
};
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#endif // ZHANDLE_H
