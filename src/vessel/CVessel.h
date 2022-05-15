#ifndef CVESSEL_H
#define CVESSEL_H

#include <QDebug>
#include "CMatrix.h"

class CVessel
{
public:
    Matrix4 pose = {1,0,0,0,
                    0,1,0,0,
                    0,0,1,0,
                    0,0,0,1};
    Vector3 size = {1,1,1};
    Vector3 color = {0.75,0.75,0.75};
public:
    CVessel();
    ~CVessel();
    Matrix4 getPose(){return pose;}
    Vector3 getSize(){return size;}
    Vector3 getColor(){return color;}
    void clearPose(){pose = {1,0,0,0,
                             0,1,0,0,
                             0,0,1,0,
                             0,0,0,1};}
    void setPose(Matrix4 pose) {this->pose = pose;}
    void setSize(Vector3 size) {this->size = size;}
    void setColor(Vector3 color) {this->color = color;}
};

#endif // CVESSEL_H
