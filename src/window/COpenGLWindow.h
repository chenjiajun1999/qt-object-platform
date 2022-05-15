#ifndef COPENGLWINDOW_H
#define COPENGLWINDOW_H

#include <QKeyEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "vessel/CSystem.h"
#include "tool/CMouseToolPick.h"


class COpenGLWindow:public QOpenGLWidget,
                    protected QOpenGLFunctions
{
   Q_OBJECT
private:
    //const double w = 1920,h = 1020;
    const double w = 1590,h = 690;
private:
    GLuint screenID = 0;
    void glRenderScreen();
    void loadTextures();
    void drawAxis();
    void drawGrid(qreal size, int nbSubdivisions);
    void drawCircle(float R,float r,float g,float b);
    void drawCylinder(float R,float H,float r,float g,float b);
    void trick();
public:
    explicit COpenGLWindow();
    explicit COpenGLWindow(QWidget *parent = nullptr);
    ~COpenGLWindow();
    double getHeight(){return h;}
    double getWidth(){return w;}
protected:
    friend class CMouseToolPick;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void wheelEvent(QWheelEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // COPENGLWINDOW_H
