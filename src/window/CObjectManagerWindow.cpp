#include "CObjectManagerWindow.h"

CObjectManagerWindow::CObjectManagerWindow(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<< "CObjectManagerWindow has been created.";

    QString data[16] = {"Size","L","W","H",
                        "Pose","X","Y","Z",
                        "Angle","X","Y","Z",
                        "Color","R","G","B"};

    setWindowTitle(tr("Object Manager Tools"));
    setAttribute(Qt::WA_DeleteOnClose);

    QGridLayout *layout = new QGridLayout(this);
    QLabel *label = new QLabel(this);

    label = new QLabel(tr("Type"),this);
    layout->addWidget(label,0,0);
    other[0] = new QLineEdit (this);
    other[0]->setMinimumWidth(120);
    other[0]->setAlignment(Qt::AlignRight);
    other[0]->setReadOnly(true);
    layout->addWidget(other[0],0,3,1,4);

    for(int i = 0;i<4;i++)
    {
        label = new QLabel(data[i*4],this);
        layout->addWidget(label,i+PLACE_MOVE,0,1,2);
    }
    for(int i = 0;i<12;i++)
    {
        label = new QLabel(data[i+(i/3+1)],this);
        layout->addWidget(label,i/3+PLACE_MOVE,i%3*2+2);
        edit[i] = new QLineEdit (this);
        edit[i]->setMaximumWidth(60);
        edit[i]->setAlignment(Qt::AlignRight);
        edit[i]->setReadOnly(false);
        connect(edit[i],SIGNAL(editingFinished()),this,SLOT(modify()));
        layout->addWidget(edit[i],i/3+PLACE_MOVE,i%3*2+3);
        if(i>2&&i<9)
        {
            pDfValidator[i] =  new  QDoubleValidator(-100.0, 100.0 , 2, edit[i]);
            pDfValidator[i]->setNotation(QDoubleValidator::StandardNotation);
            edit[i]->setValidator(pDfValidator[i]);
        }else if(i<=2)
        {
            pDfValidator[i] =  new  QDoubleValidator(0.0, 100.0 , 2, edit[i]);
            pDfValidator[i]->setNotation(QDoubleValidator::StandardNotation);
            edit[i]->setValidator(pDfValidator[i]);
        }else if(i>=9)
        {
            pDfValidator[i] =  new  QDoubleValidator(0.0, 255.0 , 2, edit[i]);
            pDfValidator[i]->setNotation(QDoubleValidator::StandardNotation);
            edit[i]->setValidator(pDfValidator[i]);
        }
    }
    setFixedSize(320,240);
}
CObjectManagerWindow::~CObjectManagerWindow()
{
    qDebug()<< "CObjectManagerWindow has been deleted.";
}
void CObjectManagerWindow::update()
{
    if(mouseToolPick->getState())
    {
        mouseToolPick->closeState();
        other[0]->setText(mouseToolPick->getCurrentType());
        edit[0]->setText(QString("%1").arg(vessel->getSize().x));
        edit[1]->setText(QString("%1").arg(vessel->getSize().y));
        edit[2]->setText(QString("%1").arg(vessel->getSize().z));
        edit[3]->setText(QString("%1").arg(vessel->getPose().getColumn(3).x));
        edit[4]->setText(QString("%1").arg(vessel->getPose().getColumn(3).y));
        edit[5]->setText(QString("%1").arg(vessel->getPose().getColumn(3).z));
        edit[6]->setText(QString("%1").arg(vessel->getPose().getAngle().x));
        edit[7]->setText(QString("%1").arg(vessel->getPose().getAngle().y));
        edit[8]->setText(QString("%1").arg(vessel->getPose().getAngle().z));
        edit[9]->setText(QString("%1").arg(int(vessel->getColor().x*255)));
        edit[10]->setText(QString("%1").arg(int(vessel->getColor().y*255)));
        edit[11]->setText(QString("%1").arg(int(vessel->getColor().z*255)));
    }
    if(mouseToolPick->getClean())
    {
        mouseToolPick->closeClean();
        for(int i = 0;i<12;i++)
        {
            edit[i]->clear();
            other[0]->clear();
            vessel->clearPose();
            vessel->setSize({1,1,1});
            vessel->setColor({0.75,0.75,0.75});
        }
    }
}
void CObjectManagerWindow::modify()
{
    qDebug()<<"change";
    Vector3 size = {edit[0]->displayText().toFloat(),edit[1]->displayText().toFloat(),edit[2]->displayText().toFloat()};
    Vector3 color = {(edit[9]->displayText()).toFloat()/255.0f,edit[10]->displayText().toFloat()/255.0f,edit[11]->displayText().toFloat()/255.0f};
    Matrix4 pose = {1,0,0,0,
                    0,1,0,0,
                    0,0,1,0,
                    0,0,0,1};
    pose.translate(edit[3]->displayText().toFloat(),edit[4]->displayText().toFloat(),edit[5]->displayText().toFloat());
    pose.rotateX((edit[6]->displayText()).toFloat());
    pose.rotateY((edit[7]->displayText()).toFloat());
    pose.rotateZ((edit[8]->displayText()).toFloat());
    vessel->setPose(pose);
    vessel->setSize(size);
    vessel->setColor(color);
    if(mouseToolPick->getCurrentObject() != nullptr)
    {
        mouseToolPick->getCurrentObject()->modifyPose(vessel->getPose());
        mouseToolPick->getCurrentObject()->modifySize(vessel->getSize());
        mouseToolPick->getCurrentObject()->modifyColor(vessel->getColor());
        redPickSphere->modifyPose(vessel->getPose());
        redPickSphere->modifySize(vessel->getSize());
    }
//    vessel->getPose().rotateX(vessel->getPose().getColumn(3).x-edit[3]->displayText().toFloat());
//    vessel->getPose().rotateY(vessel->getPose().getColumn(3).y-edit[4]->displayText().toFloat());
//    vessel->getPose().rotateZ(vessel->getPose().getColumn(3).z-edit[5]->displayText().toFloat());
}
void CObjectManagerWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    //other[0]->keyPressEvent(keyEvent);
}
void CObjectManagerWindow::keyReleaseEvent(QKeyEvent *keyEvent)
{
    //other[0]->keyPressEvent(keyEvent);
}
