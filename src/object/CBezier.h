#ifndef CBEZIER_H
#define CBEZIER_H

#include "CObject.h"

class CBezier:public CObject
{
private:
    Vector3 point[4];
public:
    CBezier(Vector3 *point,Vector3 c  = {0.75,0.75,0.75});
    ~CBezier();
    void drawCurve();
    void generateList() override;
    void glDisplacement() override;
};

#endif // CBEZIER_H
