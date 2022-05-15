#ifndef CMESSAGEWINDOW_H
#define CMESSAGEWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>

class CMessageWindow:public QWidget
{
    Q_OBJECT
private:
public:
    CMessageWindow(QWidget *parent = nullptr);
    ~CMessageWindow();
};

#endif // CMESSAGEWINDOW_H
