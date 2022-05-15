#include "CTimer.h"

CTimer::CTimer()
{
    qDebug() << "CTimer has been created";
    timer1 = new QTimer(this);
    connect(timer1,&QTimer::timeout,[=]()
    {
        //qDebug()<<"interupt!!!";
//        if(mouseToolView->check()&&mouseToolPick->check())
//        {
//            if(flag)
//            {
//                mouseToolManager->setMouse(mouseToolView);
//                flag = !flag;
//            }
//            else
//            {
//                mouseToolManager->setMouse(mouseToolPick);
//                flag = !flag;
//            }
//        }
    });
    timer1->start(15);
}
CTimer::~CTimer()
{
    qDebug() << "CTimer has been deleted";
    delete timer1;
}
