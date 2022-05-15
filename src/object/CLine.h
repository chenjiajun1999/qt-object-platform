#ifndef CLINE_H
#define CLINE_H


#include "CObject.h"

class CLine:public CObject
{
    //pose是第一个点 第二个点
private:
    Vector3 firstPiont = {0,0,0};
    Vector3 secondPiont = {0,0,0};
public:
    CLine(Vector3 f = {0,0,0},Vector3 s = {0,0,0},Vector3 c  = {0.75,0.75,0.75});
    ~CLine();
    void generateList() override;
    void glDisplacement() override;
    void modifyLine(Vector3 firstPiont,Vector3 secondPiont);
};

#endif // CLINE_H
