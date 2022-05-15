#ifndef CCUBOID_H
#define CCUBOID_H

#include "CObject.h"

class CCuboid:public CObject
{
public:
    CCuboid();
    CCuboid(Matrix4 pose = {1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            0,0,0,1},
            Vector3 size = {1,1,1},
            Vector3 color = {0.75,0.75,0.75});
    ~CCuboid();
    void generateList() override;
};

#endif // CCUBOID_H
