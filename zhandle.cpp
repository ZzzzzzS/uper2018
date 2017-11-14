#include "zhandle.h"

#include <QtMath>



ZHandle::ZHandle()

{



}



void ZHandle::mousePressEvent(QMouseEvent *e)

{

    this->WindowPoint= e->globalPos() - this->pos();
    this->setText("移动");

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



    this->CurrentSpeed.setX((bpoint.x()-centerPoint.x())*rate);

    this->CurrentSpeed.setY((bpoint.y()-centerPoint.y())*rate);

}



void ZHandle::mouseReleaseEvent(QMouseEvent *e)

{

    move(centerPoint);

    this->CurrentSpeed.setX(0);

    this->CurrentSpeed.setY(0);

}



void ZHandle::SetWindowSize(int X, int Y)

{

    centerPoint.setX(X/2);

    centerPoint.setY(Y/2);

    this->move(centerPoint);

    if(X>Y)

        r=Y/2;

    else

        r=X/2;

    r-=this->height();

    rate=100/r;

}
