#include "zhandle.h"

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
    this->move(bpoint);
}
