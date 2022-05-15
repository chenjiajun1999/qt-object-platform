#ifndef CRENDERLIST_H
#define CRENDERLIST_H

#include "object/CObject.h"

class CRenderList
{
private:
    CObject *head = nullptr;
    CObject *current = nullptr;
    int size = 0;
public:
    CRenderList();
    ~CRenderList();
    void insert(CObject *obj);
    void erase(GLuint ID);
    CObject* check(GLuint ID);
    void render();
    void destory();
    int number(){return size;}
};

#endif // CRENDERLIST_H
