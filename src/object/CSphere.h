#ifndef CSPHERE_H
#define CSPHERE_H

#include "CObject.h"

#define pi 3.1415926
#define SOLID 3000
#define WIRE  3001

typedef int SPHERE_MODE;

typedef struct Point3f
{
 GLfloat x;
 GLfloat y;
 GLfloat z;
}point;

class CSphere:public CObject
{
private:
    int mode = SOLID;
public:
    CSphere();
    CSphere(Matrix4 pose = {1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            0,0,0,1},
            Vector3 size = {1,1,1},
            Vector3 color = {0.75,0.75,0.75});
    CSphere(Matrix4 pose = {1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            0,0,0,1},
            Vector3 size = {1,1,1},
            Vector3 color = {0.75,0.75,0.75},
            SPHERE_MODE mode = SOLID);
    ~CSphere();
    void generateList() override;
    int getPoint(GLfloat radius,GLfloat a,GLfloat b,point &p);
    void drawSlice(point &p1,point &p2,point &p3,point &p4,SPHERE_MODE mode);
    point* getPointMatrix(GLfloat radius,GLint slices);
    int drawSphere(GLfloat radius,GLint slices,SPHERE_MODE mode);
};

#endif // CSPHERE_H
