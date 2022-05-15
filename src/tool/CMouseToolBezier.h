#ifndef CMOUSETOOLBEZIER_H
#define CMOUSETOOLBEZIER_H

#include <QDateTime>
#include "CMouseTool.h"
#include "window/CMainWindow.h"
#include "tool/CFactory.h"

extern class CFactory *factory;

class CMouseTool;
class CMouseToolBezier:public CMouseTool
{
private:
    QString message = "";
    QString state = "";
    Vector3 point[4];
    bool click[4] = {false};
    bool line[3] = {false};
    CLine *currentLine = nullptr;

    int current = -1;
    int next = 0;
public:
    CMouseToolBezier();
    ~CMouseToolBezier();
    void init();
    void finish();
    void clean();
    QString getMessage(){return message;}
    QString getState(){return state;}
    Vector3 getWorldViewPort(QMouseEvent* event);
    Vector3 getPoint(Vector3 vec1,Vector3 vec2);

    void mouseLeftDown(QMouseEvent* event);
    void mouseLeftUp(QMouseEvent* event);
    void mouseMove (QMouseEvent* event);
};

#endif // CMOUSETOOLBEZIER_H
