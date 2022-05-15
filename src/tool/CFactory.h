#ifndef CFACTORY_H
#define CFACTORY_H

//#include "vessel/CSystem.h"
#include "vessel/CVessel.h"
#include "object/CObject.h"
#include "object/CCuboid.h"
#include "object/CSphere.h"
#include "object/CCylinder.h"
#include "object/CLine.h"
#include "object/CBezier.h"
#include "vessel/CRenderList.h"

extern class CRenderList* renderHelper;

class CObject;
class CCuboid;
class CLine;
class CFactory
{
public:
    CFactory();
    ~CFactory();
    //CObject* create(QString str);
    CObject* create(QString str,Matrix4 p,Vector3 s,Vector3 c);
    CObject* create(QString str,Vector3 f,Vector3 s,Vector3 c);
    CObject* create(QString str,Vector3 f,Vector3 s,Vector3 t,Vector3 fo,Vector3 c);
};

#endif // CFACTORY_H
