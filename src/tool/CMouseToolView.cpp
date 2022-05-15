#include "CMouseToolView.h"

CMouseToolView *mouseToolView = new CMouseToolView();

CMouseToolView::CMouseToolView()
{
    qDebug()<<"CMouseToolView has been created.";
}
CMouseToolView::~CMouseToolView()
{
    qDebug()<<"CMouseToolView has been deleted.";
}
void CMouseToolView::keyDown(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Shift)
    {
        //isForce = true;
    }
}
void CMouseToolView::keyUp(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Shift)
    {
       // isForce = false;
    }
}
void CMouseToolView::mouseLeftDown(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        prepoint = event->pos();
    }
}
void CMouseToolView::mouseLeftUp(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton){
    }
}
void CMouseToolView::mouseRightDown(QMouseEvent* event)
{
    if(event->button() == Qt::RightButton)
    {
        prepoint = event->pos();
        isForce = true;
    }
}
void CMouseToolView::mouseRightUp(QMouseEvent* event)
{
    if(event->button() == Qt::RightButton)
    {
        isForce = false;
    }
}
void CMouseToolView::mouseMove (QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton||
       event->buttons() & Qt::RightButton)
    {
        float dx=event->pos().x()-prepoint.x();
        float dy=+event->pos().y()-prepoint.y();
        prepoint = event->pos();
        camera->processMouseMovement(dx,dy,isForce);
    }
}
void CMouseToolView::mouseWheel(QWheelEvent* event)
{
     float d=event->delta();
     camera->processMouseScroll(d);
}
