#include "CMouseToolPick.h"

CMouseToolPick *mouseToolPick = new CMouseToolPick();
CMouseToolPick::CMouseToolPick()
{
    qDebug() << "CMouseToolPick has been created";
}
CMouseToolPick::~CMouseToolPick()
{
    qDebug() << "CMouseToolPick has been deleted";
}
void CMouseToolPick::mouseLeftDown(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        prepoint = event->pos();
        isPickUp = true;

    }
}
void CMouseToolPick::mouseMove(QMouseEvent* event)
{
    double x = event->pos().x();
    double y = event->pos().y();
    pick(event);
    str = "(" + QString::number(x) + "," + QString::number(y) + ")";
}
void CMouseToolPick::pick(QMouseEvent *event)
{
    std::fill(selectBuffer.begin(), selectBuffer.end(), 0);
    glSelectBuffer(selectBufferSize, &selectBuffer[0]);

    // Draw for selection buffer
    glRenderMode(GL_SELECT);

    // Matrix setting
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    gluPickMatrix(event->x()+150, scr->getHeight() - event->y()+150, 5, 5, viewport);
    const float aspect = static_cast<float>(viewport[2]) / viewport[3];
    glOrtho(-1,1,-1,1,1,-1);
    gluPerspective(45.0,aspect,1.0,800);

    // Draw
    scr->paintGL();

    // Reset matrix setting
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    // Revert render mode
    int hits = glRenderMode(GL_RENDER);

    // Show selection
    //qDebug()<<"hits "<<hits;
    if (hits > 0)
    {
        int id = 0;
        for (int i = 0; i < hits; i++)
        {
            processSelect(selectBuffer[id + 3]);
            id += 4;
        }
    }
    else
    {
         processNothing();
    }
}
void CMouseToolPick::processSelect(int ID)
{
    forcedID = ID;
    if(forcedID >= 3) //之前的显示列表用于准备背景
    {
        touchObject = renderHelper->check(forcedID);
        if(isPickUp == true)
        {
            isChange = true;
            forcedObject = renderHelper->check(forcedID);
            message = localTime+forcedObject->getType()+" has been selected.";
            outMessage->append(message);
            isPickUp = false;
        }
    }
}
void CMouseToolPick::processNothing()
{
    forcedID = 0;
    //点击捕捉
    if(isPickUp == true)
    {
        forcedObject = nullptr;
        redPickSphere->disappear();
        isPickUp = false;
        isClean = true;
    }
    //仅触碰
    touchObject = nullptr;
    bluePickSphere->disappear();
    //当前已经捕捉
    currentObject = nullptr;
}
void CMouseToolPick::update()
{
    if(forcedObject != nullptr && forcedObject != currentObject)
    {
        currentObject = forcedObject;
        vessel->setPose(currentObject->getPose());
        vessel->setSize(currentObject->getSize());
        vessel->setColor(currentObject->getColor());
        redPickSphere->modifyPose(vessel->getPose());
        redPickSphere->modifySize(vessel->getSize());
    }
    if(touchObject != nullptr)
    {
        bluePickSphere->modifyPose(touchObject->getPose());
        bluePickSphere->modifySize(touchObject->getSize());
    }
}
QString CMouseToolPick::getCurrentType()
{
    if(currentObject!=nullptr)
        return currentObject->getType();
    else return "";
}
