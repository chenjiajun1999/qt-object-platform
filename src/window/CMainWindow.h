#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QMainWindow>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QDockWidget>
#include <QDialog>
#include <QTimer>
#include <QLabel>
#include <QStatusBar>

#include "COpenGLWindow.h"
#include "CObjectManagerWindow.h"
#include "CMessageWindow.h"
#include "vessel/CSystem.h"
#include "object/CSphere.h"

extern CSphere *redPickSphere;
extern CSphere *bluePickSphere;

class CTimer;
class COpenGLWindow;
class CObjectManagerWindow;

class CMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    COpenGLWindow *opengl = nullptr;
    QTimer *timer = nullptr;
    QLabel *label = nullptr;
    QLabel *stateLab = nullptr;


    QLabel *lab[10] = {nullptr};
    QMenu *menu[10] = {nullptr};

    bool bezier = false;

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();
};
#endif // CMAINWINDOW_H
