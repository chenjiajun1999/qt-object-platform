#include "CMouseToolCommon.h"

CMouseToolCommon *mouseToolCom = new CMouseToolCommon();

CMouseToolCommon::CMouseToolCommon()
{
    qDebug() << "CMouseToolCommon has been created";
}
CMouseToolCommon::~CMouseToolCommon()
{
    qDebug() << "CMouseToolCommon has been created";
}
void CMouseToolCommon::mouseMove(QMouseEvent* event)
{
    double x = event->pos().x();
    double y = event->pos().y();
    QString str = "(" + QString::number(x) + "," + QString::number(y) + ")";
    //label->setText(str);
}
