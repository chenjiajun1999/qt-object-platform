#include "CObject.h"

CObject::CObject()
{
}
//公共插入显示列表和拾取ID的函数
void CObject::render()
{
    if(disp_id == 0)
      return;
    glLoadName(disp_id);            //作为拾取的ID
    glPushMatrix();                 //push当前shader的位姿
    glPushAttrib(GL_CURRENT_BIT);   //push当前shader的颜色
    glDisplacement();               //会改变，不存到list里面
    glCallList(disp_id);            //执行显示列表所存储的函数
    glPopAttrib();                  //pop当前shader的颜色
    glPopMatrix();                  //pop当前shader的位姿
}
void CObject::glDisplacement()
{
    //glLoadMatrixf(pose.getTranspose());
    glTranslatef(pose.getColumn(3).x,pose.getColumn(3).y,pose.getColumn(3).z);
    //pyr
    glRotatef(pose.getAngle().x,1.0,0.0,0.0);
    glRotatef(pose.getAngle().y,0.0,1.0,0.0);
    glRotatef(pose.getAngle().z,0.0,0.0,1.0);
}
void CObject::modifyPose(Matrix4 pose)
{
    this->pose = pose;
    generateList();
}
void CObject::modifySize(Vector3 size)
{
    this->size = size;
    generateList();
}
void CObject::modifyColor(Vector3 color)
{
    this->color = color;
    generateList();
}
void CObject::disappear()
{
    this->size = {0,0,0};
    generateList();
}
