#include "CFactory.h"

CFactory *factory = new CFactory();

CFactory::CFactory()
{
    qDebug() << "CFactory has been created";
}
CFactory::~CFactory()
{
    qDebug() << "CFactory has been deleted";
}
CObject* CFactory::create(QString str,Matrix4 p,Vector3 s,Vector3 c)
{
    CObject* obj = nullptr;

    if(str == "CCuboid")
    {
        obj = new CCuboid(p,s,c);
    }
    else if(str == "CSphere")
    {
        obj = new CSphere(p,s,c,3000);
    }
    else if(str == "Red Pick Sphere")
    {
        Vector3 size = {0,0,0};
        Vector3 color = {1.0,0.27,0};
        obj = new CSphere(p,size,color,3001);
    }
    else if(str == "Blue Pick Sphere")
    {
        Vector3 size = {0,0,0};
        Vector3 color = {0.0,0.75,1.0};
        obj = new CSphere(p,size,color,3001);
    }
    else if(str == "CCylinder")
    {
        obj = new CCylinder(p,s,c);
    }
    renderHelper->insert(obj);
    return obj;
}
CObject* CFactory::create(QString str,Vector3 f,Vector3 s,Vector3 c)
{
    CObject* obj = nullptr;

    if(str == "CLine")
    {
        obj = new CLine(f,s,c);
    }
    renderHelper->insert(obj);
    return obj;
}
CObject* CFactory::create(QString str,Vector3 f,Vector3 s,Vector3 t,Vector3 fo,Vector3 c)
{
    CObject* obj = nullptr;
    Vector3 v[4] = {f,s,t,fo};
    if(str == "CBezier")
    {
        obj = new CBezier(v,c);
    }
    renderHelper->insert(obj);
    return obj;
}
