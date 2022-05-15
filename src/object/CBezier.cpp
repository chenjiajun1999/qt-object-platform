#include "CBezier.h"

CBezier::CBezier(Vector3 *point,Vector3 c)
{
    qDebug() << "CBezier has been created.";
    this->type = "Bezier";
    this->color = c;
    for(int i = 0;i<4;i++)
        this->point[i] = point[i];
    message = localTime+"Create a CBezier object successfully.";
    outMessage->append(message);
    generateList();
}
CBezier::~CBezier()
{
    qDebug() << "CBezier has been deleted.";
}
void CBezier::generateList()
{
    if(disp_id == 0)
        disp_id = glGenLists(1);
    glNewList(disp_id, GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(RED,GRE,BLU);
    drawCurve();
    glEnd();
    glEndList();
}
void CBezier::glDisplacement()
{

}
void CBezier::drawCurve()
{ //绘制一个三维三次贝塞尔曲线
    glPointSize(1.0);
    for (GLfloat t = 0; t <= 1.0; t += 0.001)
    {
        GLfloat x0 = point[0].x * pow(1.0f - t, 3) + 3 * point[1].x * t * pow(1.0f - t, 2) + 3 * point[2].x * t * t * (1.0f - t) + point[3].x * pow(t, 3);
        GLfloat y0 = point[0].y * pow(1.0f - t, 3) + 3 * point[1].y * t * pow(1.0f - t, 2) + 3 * point[2].y * t * t * (1.0f - t) + point[3].y * pow(t, 3);
        GLfloat z0 = point[0].z * pow(1.0f - t, 3) + 3 * point[1].z * t * pow(1.0f - t, 2) + 3 * point[2].z * t * t * (1.0f - t) + point[3].z * pow(t, 3);

        glBegin(GL_POINTS);
        glVertex3f(x0, y0, z0);
        glEnd();
    }
}
