#include "CCylinder.h"

CCylinder::CCylinder()
{
    qDebug() << "CCylinder has been created";
}
CCylinder::CCylinder(Matrix4 pose,Vector3 size,Vector3 color)
{
    qDebug() << "CCylinder has been created";
    this->pose = pose;
    this->size = size;
    this->color = color;
    this->type = "Cylinder";
    message = localTime+"Create a cylinder object successfully.";
    outMessage->append(message);
    generateList();
}
CCylinder::~CCylinder()
{
    qDebug() << "CCylinder has been deleted";
}
void CCylinder::generateList()
{
    float r = ((size.x > size.y) ? size.x : size.y)/2;
    if(disp_id == 0)
        disp_id = glGenLists(1);
    glNewList(disp_id, GL_COMPILE);
    drawCylinder(r,size.z,RED,GRE,BLU);
    glEndList();
}
void CCylinder::drawCircle(float R,float r,float g,float b)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f( 0.0f,  0.0f,  0.0f);
    for(int i = 0 ; i <=  360 ; i += 15)
    {
        float p = i * 3.14 / 180 ;
        glColor3f(r,g,b);
        glVertex3f(R*sin(p), R*cos(p),  0.0f);
    }
    glEnd();
    float x = R,y = 0, p = 3.14 / 180, t = 0;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; i++)
    {
        glColor3f(0,0,0);
        glVertex2f(x, y);
        t = x;
        x = cos(p) * x - sin(p) * y;
        y = sin(p) * t + cos(p) * y;
    }
    glEnd();
}
void CCylinder::drawCylinder(float R,float H,float r,float g,float b)
{
    glBegin(GL_QUAD_STRIP);
    glColor3f(r,g,b);
     for (int i = 0 ;i <= 360;i += 15)
    {
         float  p = i *  3.14  /  180 ;
        glVertex3f(R*sin(p), R*cos(p), H/2);
        glVertex3f(R*sin(p), R*cos(p),  -H/2);
    }
    glEnd();
    glTranslatef(0,0,H/2);
    drawCircle(R,r,g,b);
    glTranslatef(0,0,-H);
    drawCircle(R,r,g,b);
}
