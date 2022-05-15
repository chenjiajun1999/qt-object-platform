#ifndef COBJECTLISTWINDOW_H
#define COBJECTLISTWINDOW_H

#include <QDebug>
#include <QWidget>
#include <QGridLayout>

class CObjectListWindow:public QWidget
{
    Q_OBJECT
private:
    const double w = 300, h  =1080;
public:
    CObjectListWindow(QWidget *parent = nullptr);
    ~CObjectListWindow();
};

#endif // COBJECTLISTWINDOW_H
