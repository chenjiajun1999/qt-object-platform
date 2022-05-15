#ifndef CCAMERA_H
#define CCAMERA_H

#include <QOpenGLFunctions>
#include <GL/glut.h>
#include <QtMath>
#include <QDebug>
#include <vessel/CVector.h>

class CCamera
{
private:
    const double sensiticity = 0.01f;
    GLdouble ex,ey,ez;
    GLdouble tx,ty,tz;
    GLdouble dex,dey,dez;
    GLdouble radius,yaw,pitch;

public:
    CCamera();
    ~CCamera();
    CCamera* getCamera();
    void initCamera (GLdouble ex = 5.0,GLdouble ey = 3.0,GLdouble ez = 5.0,
                          GLdouble tx = 0.0,GLdouble ty = 0.0,GLdouble tz = 0.0);
    void setCamera();
    void getCameraView();

    Vector3 getWorldEye();
    Vector3 getWorldAim();

    void modifyCamera(GLdouble mex = 0.0,GLdouble mey = 0.0,GLdouble mez = 0.0,
                          GLdouble mtx = 0.0,GLdouble mty = 0.0,GLdouble mtz = 0.0);
    void modifyCameraDirection(GLdouble mex = 0.0,GLdouble mey = 0.0,GLdouble mez = 0.0);
    void modifyCameraDirection(GLdouble mer = 0.0);
    void modifyCameraFocus(GLdouble mtx = 0.0,GLdouble mty = 0.0,GLdouble mtz = 0.0);

    void processMouseMovement(float xoffset, float yoffset,GLboolean isForce);
    void processMouseScroll(float offset);
};

#endif // CCAMERA_H
