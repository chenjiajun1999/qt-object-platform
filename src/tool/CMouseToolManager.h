#ifndef CMOUSETOOLMANAGER_H
#define CMOUSETOOLMANAGER_H

#include "CMouseTool.h"
#include "QTimer"

#define POOL_NUM 20

class CMouseTool;
class CMouseToolManager
{
private:
    CMouseTool* currentMouseTool = nullptr;
    CMouseTool* pool[POOL_NUM] = {nullptr}; //鼠标池
    CMouseTool* head = nullptr;
    int size = 0;
public:
    CMouseToolManager();
    ~CMouseToolManager();
    void setMouse(CMouseTool* mouse);
    void insertMouse(CMouseTool* mouse);
    void eraseMouse(CMouseTool* mouse);
    CMouseTool* getMouseTool(){return currentMouseTool;}
    void keyDown(QKeyEvent* event);
    void keyUp(QKeyEvent* event);
    void mouseLeftDblClk(QMouseEvent* event);
    void mouseLeftDown(QMouseEvent* event);
    void mouseLeftUp(QMouseEvent* event);
    void mouseRightDblClk(QMouseEvent* event);
    void mouseRightDown(QMouseEvent* event);
    void mouseRightUp(QMouseEvent* event);
    void mouseMove (QMouseEvent* event);
    void mouseWheel (QWheelEvent* event);

};

#endif // CMOUSETOOLMANAGER_H
