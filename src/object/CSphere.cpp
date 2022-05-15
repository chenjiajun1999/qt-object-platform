#include "CSphere.h"

CSphere *redPickSphere = nullptr;
CSphere *bluePickSphere = nullptr;

CSphere::CSphere()
{
    qDebug() << "CSphere has been created";
}
CSphere::CSphere(Matrix4 pose,Vector3 size,Vector3 color)
{
    qDebug() << "CSphere has been created";
    this->pose = pose;
    this->size = size;
    this->color = color;
    this->type = "Sphere";
    message = localTime+"Create a sphere object successfully.";
    outMessage->append(message);
    generateList();
}
CSphere::CSphere(Matrix4 pose,Vector3 size,Vector3 color,SPHERE_MODE mode)
{
    qDebug() << "CSphere has been created";
    this->pose = pose;
    this->size = size;
    this->color = color;
    this->type = "Sphere";
    this->mode = mode;
    message = localTime+"Create a sphere object successfully.";
    outMessage->append(message);
    generateList();
}
CSphere::~CSphere()
{
    qDebug() << "CSphere has been deleted";
}
void CSphere::generateList()
{
    if(disp_id == 0)
        disp_id = glGenLists(1);
    glNewList(disp_id, GL_COMPILE);
    drawSphere(RADIUS,int(14+RADIUS),mode);
    glEndList();
}
int CSphere::getPoint(GLfloat radius,GLfloat a,GLfloat b,point &p)
{
    p.x=radius*sin(a*pi/180.0)*cos(b*pi/180.0);
    p.y=radius*sin(a*pi/180.0)*sin(b*pi/180.0);
    p.z=radius*cos(a*pi/180.0);
    return 1;
}
void CSphere::drawSlice(point &p1,point &p2,point &p3,point &p4,SPHERE_MODE mode)
{
    switch(mode)
    {
    case SOLID:
        glBegin(GL_QUADS);
        break;
    case WIRE:
        glBegin(GL_LINE_LOOP);
        break;
    }
    glColor3f(RED,GRE,BLU);
    glVertex3f(p1.x,p1.y,p1.z);
    glVertex3f(p2.x,p2.y,p2.z);
    glVertex3f(p3.x,p3.y,p3.z);
    glVertex3f(p4.x,p4.y,p4.z);
    glEnd();
}
point* CSphere::getPointMatrix(GLfloat radius,GLint slices)
{
    int i,j,w=2*slices,h=slices;
    float a=0.0,b=0.0;
    float hStep=180.0/(h-1);
    float wStep=360.0/w;
    int length=w*h;
    point *matrix;
    matrix=(point *)malloc(length*sizeof(point));
    if(!matrix)return NULL;
    for(a=0.0,i=0;i<h;i++,a+=hStep)
        for(b=0.0,j=0;j<w;j++,b+=wStep)
            getPoint(radius,a,b,matrix[i*w+j]);
    return matrix;
}
int CSphere::drawSphere(GLfloat radius,GLint slices,SPHERE_MODE mode)
{
    int i=0,j=0,w=2*slices,h=slices;
    point *mx;
    mx=getPointMatrix(radius,slices);
    if(!mx)return 0;
    for(;i<h-1;i++)
    {
        for(j=0;j<w-1;j++)
            drawSlice(mx[i*w+j],mx[i*w+j+1],mx[(i+1)*w+j+1],mx[(i+1)*w+j],mode);
        drawSlice(mx[i*w+j],mx[i*w],mx[(i+1)*w],mx[(i+1)*w+j],mode);
    }
    free(mx);
    return 1;
}
