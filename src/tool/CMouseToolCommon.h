#ifndef CMOUSETOOLCOMMON_H
#define CMOUSETOOLCOMMON_H

#include "CMouseTool.h"
#include "window/COpenGLWindow.h"
#include "vessel/CSystem.h"

class COpenGLWindow;

class CMouseToolCommon:public CMouseTool
{
private:
    COpenGLWindow *scr = nullptr;
public:
    CMouseToolCommon();
    ~CMouseToolCommon();
    void mouseMove (QMouseEvent* event);
    void setOpenGL(COpenGLWindow *scr){this->scr = scr;};
};

#endif // CMOUSETOOLCOMMON_H
