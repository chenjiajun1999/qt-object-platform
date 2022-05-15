#ifndef CTIMER_H
#define CTIMER_H

#include <QTimer>
#include <QDebug>
#include "vessel/CSystem.h"

class CTimer:public QObject
{
    Q_OBJECT
private:
     QTimer * timer1 = nullptr;
     bool flag = false;
public:
    CTimer();
    ~CTimer();
};

#endif // CTIMER_H
