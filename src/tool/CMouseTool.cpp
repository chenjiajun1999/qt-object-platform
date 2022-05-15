#include "CMouseTool.h"

CMouseTool::CMouseTool()
{
    //qDebug()<<"CMouseTool has been created.";
}
CMouseTool::~CMouseTool()
{
    //qDebug()<<"CMouseTool has been deleted.";
}
void CMouseTool::setOpenGL(COpenGLWindow *scr)
{
    this->scr = scr;
    isReady = true;
}
