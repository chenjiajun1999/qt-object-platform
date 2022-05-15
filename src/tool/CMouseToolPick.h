#ifndef CMOUSETOOLPICK_H
#define CMOUSETOOLPICK_H

#include "CMouseTool.h"
#include "object/CObject.h"
#include "object/CSphere.h"
#include "vessel/CRenderList.h"
#include "window/COpenGLWindow.h"
#include "window/CObjectManagerWindow.h"

class CObjectManagerWindow;

extern CSphere *redPickSphere;
extern CSphere *bluePickSphere;
extern CRenderList *renderHelper;
extern CVessel *vessel;
extern CObjectManagerWindow *objectManagerWindow;

class CMouseToolPick:public CMouseTool
{
private:
    QString str = "";
    QString message = "";
    static const int selectBufferSize = 100;
    std::vector<uint> selectBuffer = std::vector<uint>(selectBufferSize);
    bool isPickUp = false;
    bool isChange = false;
    bool isClean = false;
    int currentID = 0;
    int forcedID = 0;
    CObject* forcedObject = nullptr;
    CObject* currentObject = nullptr;
    CObject* touchObject = nullptr;
public:
    CMouseToolPick();
    ~CMouseToolPick();
    QString getMessage(){return str;}
    QString getCurrentType();
    CObject *getCurrentObject(){return currentObject;}
    void mouseLeftDown(QMouseEvent* event);
    void mouseMove (QMouseEvent* event);
    void pick(QMouseEvent* event);
    void processSelect(int ID);
    void processNothing();
    void update();
    bool getState(){return isChange;}
    bool getClean(){return isClean;}
    void closeState(){isChange = false;}
    void closeClean(){isClean = false;}
};

#endif // CMOUSETOOLPICK_H
