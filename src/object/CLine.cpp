#include "CLine.h"

CLine::CLine(Vector3 f,Vector3 s,Vector3 c)
{
    qDebug() << "CLine has been created.";
    firstPiont = f;
    secondPiont = s;
    color = c;
    this->type = "Line";
    message = localTime+"Create a CLine object successfully.";
    outMessage->append(message);
    generateList();
}
CLine::~CLine()
{
    qDebug() << "CLine has been deleted.";
}
void CLine::generateList()
{
    if(disp_id == 0)
        disp_id = glGenLists(1);
    glNewList(disp_id, GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(RED,GRE,BLU);
    glVertex3f(firstPiont.x,firstPiont.y,firstPiont.z);
    glVertex3f(secondPiont.x,secondPiont.y,secondPiont.z);
    glEnd();
    glEndList();
}
void CLine::glDisplacement()
{

}
void CLine :: modifyLine(Vector3 firstPiont,Vector3 secondPiont)
{
    this->firstPiont = firstPiont;
    this->secondPiont = secondPiont;
    generateList();
}
