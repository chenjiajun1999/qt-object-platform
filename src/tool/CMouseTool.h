#ifndef CMOUSETOOL_H
#define CMOUSETOOL_H

#include <QKeyEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDebug>
#include "CMouseToolManager.h"


class COpenGLWindow;
class CMouseTool;
class CMouseToolManager;

class CMouseTool
{
friend CMouseToolManager;
protected:
    QPoint prepoint;
    bool isReady = false;
    int id = -1;
    COpenGLWindow *scr = nullptr;
    CMouseTool *next = nullptr;
public:
    CMouseTool();
    bool check(){return isReady;}
    virtual ~CMouseTool();
    CMouseTool* getMouse(){return this;}
    int getID(){return id;}
    void setOpenGL(COpenGLWindow *scr);
    virtual void keyDown(QKeyEvent* event){ qDebug() << event;};
    virtual void keyUp(QKeyEvent* event){ qDebug() << event;};
    virtual void mouseLeftDblClk(QMouseEvent* event){ qDebug() << event;};
    virtual void mouseLeftDown(QMouseEvent* event){ qDebug() << event;};
    virtual void mouseLeftUp(QMouseEvent* event){ qDebug() << event;};
    virtual void mouseRightDblClk(QMouseEvent* event){ qDebug() << event;};
    virtual void mouseRightDown(QMouseEvent* event){ qDebug() << event;};
    virtual void mouseRightUp(QMouseEvent* event){ qDebug() << event;};
    virtual void mouseMove (QMouseEvent* event){ qDebug() << event;};
    virtual void mouseWheel (QWheelEvent* event){ qDebug() << event;};
};

#endif // CMOUSETOOL_H
