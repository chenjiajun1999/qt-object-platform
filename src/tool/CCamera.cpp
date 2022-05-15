#include "CCamera.h"

CCamera *camera = new CCamera();

CCamera::CCamera()
{
    qDebug() << "CCamera has been created";
    initCamera();
}
CCamera::~CCamera()
{
    qDebug() << "CCamera has been deleted";
}
CCamera* CCamera::getCamera()
{
    return this;
}
void CCamera::initCamera(GLdouble ex ,GLdouble ey ,GLdouble ez ,
                         GLdouble tx ,GLdouble ty ,GLdouble tz )
{
    this->ex = ex;    this->ey = ey;    this->ez = ez;
    this->tx = tx;    this->ty = ty;    this->tz = tz;
    this->dex = 0;    this->dey = 0;    this->dez = 0;

    radius = sqrt(pow(this->ex,2)+pow(this->ey,2)+pow(this->ez,2));
    pitch = asin(this->ey/radius);
    yaw = atan(this->ez/this->ex);
}
void CCamera::getCameraView()
{
    gluLookAt(ex+dex,ey,ez+dez,tx,ty,tz,0,1,0);
}

Vector3 CCamera::getWorldEye()
{
    Vector3 v = {(float)(ez+dez),(float)(ex+dex),(float)(ey)};
    return v;
}
Vector3  CCamera::getWorldAim()
{
    Vector3 v = {(float)(tz),(float)tx,(float)(ty)};
    return v;
}
void CCamera::modifyCamera(GLdouble mex ,GLdouble mey ,GLdouble mez ,
                           GLdouble mtx ,GLdouble mty ,GLdouble mtz )
{
    this->ex += mex;    this->ey += mey;    this->ez += mez;
    this->tx += mtx;    this->ty += mty;    this->tz += mtz;
}
void CCamera::modifyCameraDirection(GLdouble mex, GLdouble mey, GLdouble mez)
{
    this->ex += mex;    this->ey += mey;    this->ez += mez;
}
void CCamera::modifyCameraDirection(GLdouble mer)
{
    this->ex += mer;    this->ey += mer;    this->ez += mer;
}
void CCamera::modifyCameraFocus(GLdouble mtx, GLdouble mty, GLdouble mtz)
{
    this->tx += mtx;    this->ty += mty;    this->tz += mtz;
}
void CCamera::processMouseMovement(float xoffset, float yoffset,GLboolean isForce)
{
    if(!isForce)
    {
        xoffset *= sensiticity;
        yoffset *= sensiticity;

        yaw += xoffset;
        pitch += yoffset;

        if (pitch > 89.9*3.1415/180.0f)
           pitch = 89.9*3.1415/180.0f;
        if (pitch < -89.9*3.1415/180.0f)
           pitch = -89.9*3.1415/180.0f;

        //坐标是z轴向外
        ex = radius*cos(yaw)*cos(pitch);
        ey = radius*sin(pitch);
        ez = radius*sin(yaw)*cos(pitch);
    }else
    {
        xoffset *= -sensiticity;
        yoffset *= -sensiticity;

        dex += xoffset*sin(yaw)+yoffset*cos(yaw);
        tx += xoffset*sin(yaw)+yoffset*cos(yaw);
        dez += yoffset*sin(yaw)-xoffset*cos(yaw);
        tz += yoffset*sin(yaw)-xoffset*cos(yaw);
    }
}
void CCamera::processMouseScroll(float offset)
{
    if (radius >= 1.0f && radius <= 45.0f)
        radius -= offset*sensiticity;
    if (radius <= 1.0f)
        radius = 1.0f;
    if (radius >= 45.0f)
        radius = 45.0f;
    ex = radius*cos(yaw)*cos(pitch);
    ey = radius*sin(pitch)+dey;
    ez = radius*sin(yaw)*cos(pitch);
}
