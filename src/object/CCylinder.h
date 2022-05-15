#ifndef CCYLINDER_H
#define CCYLINDER_H

#include "CObject.h"

class CCylinder:public CObject
{
public:
    CCylinder();
    CCylinder(Matrix4 pose = {1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            0,0,0,1},
            Vector3 size = {1,1,1},
            Vector3 color = {0.75,0.75,0.75});
    ~CCylinder();
    void generateList() override;
    void drawCircle(float R,float r,float g,float b);
    void drawCylinder(float R,float H,float r,float g,float b);
};
#endif // CCYLINDER_H
