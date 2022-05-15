#include "CMouseToolBezier.h"

CMouseToolBezier *mouseToolBezier = new CMouseToolBezier();
CMouseToolBezier::CMouseToolBezier()
{
    qDebug() << "CMouseToolBezier has been created";
//    QDateTime local(QDateTime::currentDateTime());
//    QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
//    message = "System: "+localTime+"Drawing a bezier line.";
//    outMessage->append(message);
}
CMouseToolBezier::~CMouseToolBezier()
{
    qDebug() << "CMouseToolBezier has been deleted";
}
void CMouseToolBezier::init()
{
    mouseToolManager->insertMouse(mouseToolBezier);
    mouseToolManager->eraseMouse(mouseToolView);
    message = localTime+"Draw a bezier line.";
    outMessage->append(message);
    clean();
}
void CMouseToolBezier::finish()
{
    mouseToolManager->insertMouse(mouseToolView);
    mouseToolManager->eraseMouse(mouseToolBezier);
    message = localTime+"Create a bezier line suessfully.";
    outMessage->append(message);
    factory->create("CBezier",point[0],point[1],point[2],point[3],{1.0,1.0,1.0});
}
void CMouseToolBezier::clean()
{
    for(int i =0;i<4;i++) click[i] = false;
    for(int i =0;i<4;i++) point[i] = {0,0,0};
    for(int i =0;i<3;i++) line[i] = false;
    currentLine = nullptr;
    current = -1;
    next = 0;
}
void CMouseToolBezier::mouseLeftDown(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        current++;
        next++;
        click[current] = true;
        point[current] = getWorldViewPort(event);
        if(click[3] == true)
            finish();
//        factory->create("CLine",{0,0,0},
//                        getPoint(getWorldViewPort(event),camera->getWorldEye())
//                        ,{0.75,0.75,0.75});
    }
}
void CMouseToolBezier::mouseLeftUp(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
    }
}
void CMouseToolBezier::mouseMove (QMouseEvent* event)
{
    if(click[current] == true&&click[next] == false&&line[current] == false)
    {
        currentLine = (CLine*)factory->create("CLine",point[current],getWorldViewPort(event),{0.95,0.0,0.0});
        line[current] = true;
    }
    if(line[current] == true)
        currentLine->modifyLine(point[current],getWorldViewPort(event));

    if(event->buttons() & Qt::LeftButton)
    {
    }
}
Vector3 CMouseToolBezier::getWorldViewPort(QMouseEvent* event)
{
    GLint viewport[4] = {0,0,1590,690};
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera->getCameraView();

    // glRotatef(-90,1.0,0.0,0.0);
    // glRotatef(-90,0.0,0.0,1.0);
    //glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);

    winX = (float)event->pos().x();
    winY = (float)viewport[3] - (float)event->pos().y();
    glReadPixels(int(winX), int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    // Vector3 re = {(float)posX,(float)posY,(float)posZ};
    Vector3 re = {(float)posZ,(float)posX,(float)posY};
//    message = localTime+"->>>>>""x="+QString("%1").arg(re.x)
//            +",y="+QString("%1").arg(re.y)
//            +",z="+QString("%1").arg(re.z);
//    outMessage->append(message);
    return re;
}
Vector3 CMouseToolBezier::getPoint(Vector3 vec1,Vector3 vec2)
{
    float a = vec1.x- vec2.x;
    float b = vec1.y- vec2.y;
    float c = vec1.z- vec2.z;

    float t = 0;
    float x = vec1.x + a*t;
    float y = vec1.y + b*t;
    //   float z = vec1.z + c*t;

    t = -vec1.z/c;
    x = vec1.x + a*t;
    y = vec1.y + b*t;

    Vector3 re = {x,y,0};
    return re;
}

