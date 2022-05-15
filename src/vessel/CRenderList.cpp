#include "CRenderList.h"

CRenderList *renderHelper = new CRenderList();

CRenderList::CRenderList()
{
    qDebug() << "CRenderList has been created";
}
CRenderList::~CRenderList()
{
    qDebug() << "CRenderList has been deleted";
    destory();
}
void CRenderList::render()
{
    if(head == NULL)
        return;
    else
    {
        CObject *current = head;
        while(current != nullptr)
        {
            current->render();
            current = current->next;
        }
    }
}
void CRenderList::insert(CObject *obj)
{
    if(head == NULL)
    {
        head = obj;
        size++;
    }
    else
    {
        CObject* current = head;
        while(current->next != nullptr)
            current = current->next;
        current->next = obj;
        obj->prev = current;
        size++;
    }
}
void CRenderList::erase(GLuint ID)
{
    if(head == NULL)
        return;
    if(head->getID() == ID)
    {
        head = head->next;
        size--;
    }
    else
    {
        CObject* current = head->next;
        while(current != nullptr)
        {
            if(current->getID() == ID)
            {
                if(current->prev != nullptr)
                    current->prev->next = current->next;
                if(current->next != nullptr)
                    current->next->prev = current->prev;
                size--;
                //delete current;
                return;
            }
            else
            {
                current = current->next;
            }
        }
        qDebug()<<"delete fall";
    }
}
CObject* CRenderList::check(GLuint ID)
{
    if(ID == 0 || head == NULL)
        return nullptr;

    CObject* find = head;
    while(find != nullptr)
    {
        if(find->getID() == ID)
        {
            return find;
        }
        else
        {
            find = find->next;
        }
    }
    return nullptr;
}
void CRenderList::destory()
{
    CObject * current = head;
    CObject * node = nullptr;
    head = nullptr;
    while (current != nullptr)
    {
        node = current;
        current = current->next;
        delete node;
    }
    qDebug() << "Delete all thing.";
}
