#ifndef CMOUSETOOLVIEW_H
#define CMOUSETOOLVIEW_H

#include "CMouseTool.h"
#include "vessel/CSystem.h"

class CMouseToolView:public CMouseTool
{
public:
    bool isForce = false;
    bool isPickUp = false;
    int currentID = 0;
    int forcedID = 0;
//    BaseObject* forcedObject = nullptr;
//    BaseObject* currentObject = nullptr;
//    BaseObject* touchObject = nullptr;
public:
    CMouseToolView();
    ~CMouseToolView();
    void keyDown(QKeyEvent* event);
    void keyUp(QKeyEvent* event);
    void mouseLeftDown(QMouseEvent* event);
    void mouseLeftUp(QMouseEvent* event);
    void mouseRightDown(QMouseEvent* event);
    void mouseRightUp(QMouseEvent* event);
    void mouseMove (QMouseEvent* event);
    void mouseWheel (QWheelEvent* event);
};

#endif // CMOUSETOOLVIEW_H
