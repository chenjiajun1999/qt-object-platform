#include "CCuboid.h"

CCuboid::CCuboid()
{
    qDebug() << "CCuboid has been created";
}
CCuboid::CCuboid(Matrix4 pose,Vector3 size,Vector3 color)
{
    qDebug() << "CCuboid has been created";
    this->pose = pose;
    this->size = size;
    this->color = color;
    this->type = "Cube";
    message = localTime+"Create a cube object successfully.";
    outMessage->append(message);
    generateList();
}
CCuboid::~CCuboid()
{
    qDebug() << "CCuboid has been deleted";
}
void CCuboid::generateList()
{
    if(disp_id == 0)
        disp_id = glGenLists(1);
    glNewList(disp_id, GL_COMPILE);

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(+LENGTH, +HEIGHT, -WIDTH);
    glVertex3f(-LENGTH, +HEIGHT, -WIDTH);
    glVertex3f(+LENGTH, -HEIGHT, -WIDTH);
    glVertex3f(-LENGTH, -HEIGHT, -WIDTH);
    glVertex3f(+LENGTH, -HEIGHT, +WIDTH);
    glVertex3f(-LENGTH, -HEIGHT, +WIDTH);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(+LENGTH, +HEIGHT, +WIDTH);
    glVertex3f(+LENGTH, +HEIGHT, -WIDTH);
    glVertex3f(+LENGTH, -HEIGHT, -WIDTH);
    glVertex3f(+LENGTH, -HEIGHT, +WIDTH);
    glVertex3f(+LENGTH, +HEIGHT, +WIDTH);
    glVertex3f(-LENGTH, +HEIGHT, +WIDTH);
    glVertex3f(-LENGTH, +HEIGHT, -WIDTH);
    glVertex3f(-LENGTH, -HEIGHT, -WIDTH);
    glVertex3f(-LENGTH, -HEIGHT, +WIDTH);
    glVertex3f(-LENGTH, +HEIGHT, +WIDTH);
    glEnd();

    glBegin(GL_POLYGON);//FRONT
    glColor3f(RED,GRE,BLU);
    glVertex3f(LENGTH,-HEIGHT,-WIDTH);glVertex3f(LENGTH,HEIGHT,-WIDTH);
    glVertex3f(-LENGTH,HEIGHT,-WIDTH);glVertex3f(-LENGTH,-HEIGHT,-WIDTH);
    glEnd();
    glBegin(GL_POLYGON);//BACK
    glColor3f(RED,GRE,BLU);
    glVertex3f(LENGTH,-HEIGHT,WIDTH); glVertex3f(LENGTH,HEIGHT,WIDTH);
    glVertex3f(-LENGTH,HEIGHT,WIDTH); glVertex3f(-LENGTH,-HEIGHT,WIDTH);
    glEnd();
    glBegin(GL_POLYGON);//RIGHT
    glColor3f(RED,GRE,BLU);
    glVertex3f(LENGTH,-HEIGHT,-WIDTH); glVertex3f(LENGTH,HEIGHT,-WIDTH);
    glVertex3f(LENGTH,HEIGHT,WIDTH); glVertex3f(LENGTH,-HEIGHT,WIDTH);
    glEnd();
    glBegin(GL_POLYGON);//LEFT
    glColor3f(RED,GRE,BLU);
    glVertex3f(-LENGTH,-HEIGHT,WIDTH); glVertex3f(-LENGTH,HEIGHT,WIDTH);
    glVertex3f(-LENGTH,HEIGHT,-WIDTH); glVertex3f(-LENGTH,-HEIGHT,-WIDTH);
    glEnd();
    glBegin(GL_POLYGON);//TOP
    glColor3f(RED,GRE,BLU);
    glVertex3f(LENGTH,HEIGHT,WIDTH); glVertex3f(LENGTH,HEIGHT,-WIDTH);
    glVertex3f(-LENGTH,HEIGHT,-WIDTH); glVertex3f(-LENGTH,HEIGHT,WIDTH);
    glEnd();
    glBegin(GL_POLYGON);//BOTTOM
    glColor3f(RED,GRE,BLU);
    glVertex3f(LENGTH,-HEIGHT,-WIDTH); glVertex3f(LENGTH,-HEIGHT,WIDTH);
    glVertex3f(-LENGTH,-HEIGHT,WIDTH); glVertex3f(-LENGTH,-HEIGHT,-WIDTH);
    glEnd();

    glEndList();
}
