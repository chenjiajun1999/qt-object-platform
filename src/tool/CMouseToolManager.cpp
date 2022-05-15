#include "CMouseToolManager.h"

CMouseToolManager *mouseToolManager = new CMouseToolManager();

CMouseToolManager::CMouseToolManager()
{
    qDebug() << "CMouseToolManager has been created";
}
CMouseToolManager::~CMouseToolManager()
{
    qDebug()  << "CMouseToolManager has been deleted" ;
}
void CMouseToolManager::setMouse(CMouseTool* mouse)
{
    currentMouseTool = mouse;
}
void CMouseToolManager::insertMouse(CMouseTool *mouse)
{
    if(size == POOL_NUM)
    {
        qDebug()<<"Mouse is out of the max number.";
        return;
    }
    if(head == nullptr)
        head = mouse;
    else
    {
        CMouseTool * current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = mouse;
    }
    size ++;
}
void CMouseToolManager::eraseMouse(CMouseTool *mouse)
{
    if(size == 0)
    {
        qDebug()<<"Mouse is out of the min number.";
        return;
    }
    if(head == mouse)
    {
        head = head->next;
        mouse->next = nullptr;
        size --;
    }
    else
    {
        CMouseTool * current = head;
        while (current->next != mouse && current != nullptr)
        {
            current = current->next;
        }
        if(current->next != nullptr)
        {
            current->next = current->next->next;
            mouse->next = nullptr;
            size --;
        }
    }

}
void CMouseToolManager::keyDown(QKeyEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->keyDown(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::keyUp(QKeyEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->keyUp(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseLeftDblClk(QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseLeftDblClk(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseLeftDown(QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseLeftDown(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseLeftUp(QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseLeftUp(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseRightDblClk(QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseRightDblClk(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseRightDown(QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseRightDown(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseRightUp(QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseRightUp(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseMove (QMouseEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseMove(event);
        currentMouseTool = currentMouseTool->next;
    }
}
void CMouseToolManager::mouseWheel (QWheelEvent* event)
{
    currentMouseTool = head;
    while(currentMouseTool != nullptr)
    {
        currentMouseTool->mouseWheel(event);
        currentMouseTool = currentMouseTool->next;
    }

}
