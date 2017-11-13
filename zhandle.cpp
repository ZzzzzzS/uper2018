#include "zhandle.h"
#include <QtMath>

ZHandle::ZHandle()
{

}

void ZHandle::mousePressEvent(QMouseEvent *e)
{
    this->WindowPoint= e->globalPos() - this->pos();
}

void ZHandle::mouseMoveEvent(QMouseEvent *e)
{
    QPoint bpoint=e->globalPos()-this->WindowPoint;


    if(sqrt(pow(abs(bpoint.rx()-centerPoint.rx()),2) + pow(abs(bpoint.ry()-centerPoint.ry()),2)) < r)
    {
      move(bpoint);
    }

    else if(bpoint.rx()>centerPoint.rx() && bpoint.ry()<centerPoint.ry())
    {
        double k = (double)(bpoint.rx()-centerPoint.rx())/(centerPoint.ry()-bpoint.ry());
        double angle= qAtan(k)/3.1415*180;
        bpoint.setX(centerPoint.rx() + r*qCos((angle-90.0)*3.1415/180));
        bpoint.setY(centerPoint.ry() + r*qSin((angle-90.0)*3.1415/180));
        move(bpoint);
    }
    else if(bpoint.rx()>centerPoint.rx() && bpoint.ry()>centerPoint.ry())
    {
        double k = (double)(bpoint.rx()-centerPoint.rx())/(bpoint.ry()-centerPoint.ry());
        double angle= 180-qAtan(k)/3.1415*180;
        bpoint.setX(centerPoint.rx() + r*qCos((angle-90.0)*3.1415/180));
        bpoint.setY(centerPoint.ry() + r*qSin((angle-90.0)*3.1415/180));
        move(bpoint);
    }
    else if(bpoint.rx()<centerPoint.rx() && bpoint.ry()<centerPoint.ry())
    {
        double k = (double)(centerPoint.rx()-bpoint.rx())/(centerPoint.ry()-bpoint.ry());
        double angle= qAtan(k)/3.1415*180;
        bpoint.setX(centerPoint.rx() - r*qCos((angle-90.0)*3.1415/180));
        bpoint.setY(centerPoint.ry() + r*qSin((angle-90.0)*3.1415/180));
        move(bpoint);
    }
    else if(bpoint.rx()<centerPoint.rx() && bpoint.ry()>centerPoint.ry())
    {
        double k = (double)(centerPoint.rx()-bpoint.rx())/(bpoint.ry()-centerPoint.ry());
        double angle= qAtan(k)/3.1415*180;
        bpoint.setX(centerPoint.rx() - r*qCos((angle-90.0)*3.1415/180));
        bpoint.setY(centerPoint.ry() - r*qSin((angle-90.0)*3.1415/180));
        move(bpoint);
    }

    this->CurrentSpeed.setX((bpoint.x()-200));
    this->CurrentSpeed.setY((bpoint.y()-100));
}

void ZHandle::mouseReleaseEvent(QMouseEvent *e)
{
    move(centerPoint);
    this->CurrentSpeed.setX(0);
    this->CurrentSpeed.setY(0);
}
