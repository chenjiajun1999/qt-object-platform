#include "CMessageWindow.h"

QTextEdit *outMessage = nullptr;

CMessageWindow::CMessageWindow(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"CMessageWindow has been created.";

    QGridLayout *layout = new QGridLayout(this);
    outMessage = new QTextEdit(this);
    outMessage->setStyleSheet("background-color: rgb(245,245,245);");
    layout->addWidget(outMessage,0,0);
    outMessage->setReadOnly(true);
    //setFixedSize(1580,300);
}
CMessageWindow::~CMessageWindow()
{
    qDebug()<<"CMessageWindow has been deleted.";
}
