#ifndef COBJECT_H
#define COBJECT_H

#include <QString>
#include <QTextEdit>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "vessel/CVessel.h"

extern QString localTime;
extern QTextEdit *outMessage;

#define LENGTH size.x/2
#define HEIGHT size.y/2
#define WIDTH  size.z/2
#define RADIUS sqrt(pow(size.x,2)+pow(size.y,2)+pow(size.z,2))/2
#define RED color.x
#define GRE color.y
#define BLU color.z

class CObject
{
protected:
    Matrix4 pose = {1,0,0,0,
                    0,1,0,0,
                    0,0,1,0,
                    0,0,0,1};
    Vector3 size = {1,1,1};
    Vector3 color = {0.75,0.75,0.75};
    GLuint disp_id = 0;
    QString type = "";
    QString message = "";
public:
    CObject *next = nullptr;
    CObject *prev = nullptr;
public:
    CObject();
    virtual ~CObject() {};
    virtual void generateList() = 0;
    virtual void glDisplacement();
    GLuint getID(){return disp_id;}
    QString getType(){return type;}
    Matrix4 getPose(){return pose;}
    Vector3 getSize(){return size;}
    Vector3 getColor(){return color;}
    void setPose(Matrix4 pose) {this->pose = pose;}
    void setSize(Vector3 size) {this->size = size;}
    void setColor(Vector3 color) {this->color = color;}
    void render();
    void modifyPose(Matrix4 pose);
    void modifySize(Vector3 size);
    void modifyColor(Vector3 color);
    void disappear();
};

#endif // COBJECT_H
