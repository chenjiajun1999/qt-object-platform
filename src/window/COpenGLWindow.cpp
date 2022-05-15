#include "COpenGLWindow.h"

COpenGLWindow::COpenGLWindow()
{
}
COpenGLWindow::COpenGLWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
    qDebug()<<"COpenGLWindow has been created.";
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setProfile(QSurfaceFormat::CoreProfile);
    this->setFormat(format);
    this->grabKeyboard();
    mouseToolView->setOpenGL(this);
    mouseToolPick->setOpenGL(this);
    mouseToolBezier->setOpenGL(this);
    mouseToolManager->insertMouse(mouseToolView);
    mouseToolManager->insertMouse(mouseToolPick);
    setMouseTracking(true);
}
COpenGLWindow::~COpenGLWindow()
{
    qDebug()<<"COpenGLWindow has been deleted.";
}
void COpenGLWindow::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1,1,1,1);
    setGeometry(0, 0, w, h);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);


}

void COpenGLWindow::paintGL()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera->getCameraView();
    glRotatef(-90,1.0,0.0,0.0);
    glRotatef(-90,0.0,0.0,1.0);
    glRenderScreen();
    glInitNames();
    glPushName(0);
    renderHelper->render();
    glFlush();
}

void COpenGLWindow::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = float(width)/float(height);
    //glOrtho(-1,1,-1,1,1,-1);
    gluPerspective(45.0,aspect,1.0,800);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void COpenGLWindow::glRenderScreen()
{
    if(screenID == 0)
    {
        screenID = glGenLists(1);
        glNewList(screenID, GL_COMPILE);
        drawGrid(20,20);
        drawAxis();
        glEndList();
    }else
    {
        glPushMatrix();
        glPushAttrib(GL_CURRENT_BIT);
        glCallList(screenID);
        glPopAttrib();
        glPopMatrix();
    }
}
void COpenGLWindow::drawGrid(qreal size, int nbSubdivisions)
{
    GLboolean lighting;
    glGetBooleanv(GL_LIGHTING, &lighting);
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glLineWidth(10.0f);
    glColor3f(0, 0 , 1);
    for (int i = 0; i <= nbSubdivisions; ++i) {
        const float pos = size * (2.0 * i / nbSubdivisions - 1.0);
        glVertex2d(pos, -size);
        glVertex2d(pos, +size);
        glVertex2d(-size, pos);
        glVertex2d(size, pos);
    }
    glEnd();
    if (lighting)
        glEnable(GL_LIGHTING);
}
void COpenGLWindow::drawAxis()
{
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    drawCylinder(0.01,0.8,1.0,0.0,0.0);
    glRotatef(-90,1,0,0);
    drawCylinder(0.01,0.8,0.0,1.0,0.0);
    glRotatef(90,0,1,0);
    drawCylinder(0.01,0.8,0.0,0.0,1.0);
    glPopAttrib();
    glPopMatrix();
}
void COpenGLWindow::drawCircle(float R,float r,float g,float b)
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
}
void COpenGLWindow::drawCylinder(float R,float H,float r,float g,float b)
{
    glBegin(GL_QUAD_STRIP);
    glColor3f(r,g,b);
     for (int i = 0 ;i <= 360;i += 15)
    {
         float  p = i *  3.14  /  180 ;
        glVertex3f(R*sin(p), R*cos(p), H);
        glVertex3f(R*sin(p), R*cos(p),  0.0f);
    }
    glEnd();
    drawCircle(R,r,g,b);
    glTranslatef(0,0,H);
    drawCircle(R,r,g,b);
    glColor3f(r,g,b);
    glTranslatef(0,0,-H);
}
void COpenGLWindow::mousePressEvent(QMouseEvent *event)
{
     mouseToolManager->mouseLeftDown(event);
     mouseToolManager->mouseRightDown(event);
}
void COpenGLWindow::mouseReleaseEvent(QMouseEvent *event)
{
     mouseToolManager->mouseLeftUp(event);
     mouseToolManager->mouseRightUp(event);
}
void COpenGLWindow::mouseMoveEvent(QMouseEvent *event)
{
     mouseToolManager->mouseMove(event);
}
void COpenGLWindow::wheelEvent(QWheelEvent* event)
{
     mouseToolManager->mouseWheel(event);
}
void COpenGLWindow::keyPressEvent(QKeyEvent *event)
{
     mouseToolManager->keyDown(event);
     objectManagerWindow->keyPressEvent(event);
}
void COpenGLWindow::keyReleaseEvent(QKeyEvent *event)
{
     mouseToolManager->keyUp(event);
     objectManagerWindow->keyReleaseEvent(event);
}

