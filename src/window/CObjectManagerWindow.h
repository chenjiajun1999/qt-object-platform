#ifndef COBJECTMANAGERWINDOW_H
#define COBJECTMANAGERWINDOW_H

#include <QDebug>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDoubleValidator>
#include "vessel/CSystem.h"

#define PLACE_MOVE 1

class CObjectManagerWindow:public QWidget
{
    Q_OBJECT
private:
    const double w = 300, h  =1080;
    QLineEdit *edit[12] = {nullptr};
    QLineEdit *other[12] = {nullptr};
    QDoubleValidator *pDfValidator[12] = {nullptr};
public:
   // CObjectManagerWindow();
    CObjectManagerWindow(QWidget *parent = nullptr);
    ~CObjectManagerWindow();
    void update();
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

public slots:
    void modify();
};

#endif // COBJECTMANAGERWINDOW_H
