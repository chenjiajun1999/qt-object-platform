#include "CMainWindow.h"

QString localTime = "";
CObjectManagerWindow * objectManagerWindow = nullptr;

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug()<<"CMainWindow has been created.";
    this->releaseKeyboard();
    opengl = new COpenGLWindow(this);
    opengl->releaseKeyboard();
    setCentralWidget(opengl);
    opengl->setMinimumSize(800,400);
    //resize(opengl->getWidth(),opengl->getHeight());

    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *menu = menuBar->addMenu("File");
    QAction *action = menu->addAction("Open");
    action = menu->addAction("Save");
    menu = menuBar->addMenu("Edit");
    menu = menuBar->addMenu("View");
    menu = menuBar->addMenu("Sorce");
    QMenu *menu2 = menu;
    menu = menu->addMenu("3D object");
    action = menu->addAction("Cube");
    connect(action,&QAction::triggered,[=]()
    {
        factory->create("CCuboid",vessel->pose,vessel->size,vessel->color);
    });
    action = menu->addAction("Triangular pyramid");
    action = menu->addAction("Cylinder");
    connect(action,&QAction::triggered,[=]()
    {
        factory->create("CCylinder",vessel->pose,vessel->size,vessel->color);
    });
    action = menu->addAction("Ball");
    connect(action,&QAction::triggered,[=]()
    {
        factory->create("CSphere",vessel->pose,vessel->size,vessel->color);
    });
    menu2 = menu2->addMenu("Geometric elements");
    action = menu2->addAction("Bezier");
    connect(action,&QAction::triggered,[=]()
    {
            mouseToolBezier->init();
    });
    action = menu2->addAction("Line");
    connect(action,&QAction::triggered,[=]()
    {
            //factory->create("CLine",{1,1,1},{0,0,10},{0.75,0.75,0.75});
    });

    QStatusBar *status = statusBar();
    stateLab = new QLabel(this);
    stateLab->setAlignment(Qt::AlignCenter);
    stateLab->setMinimumWidth(200);
    status->addPermanentWidget(stateLab);
    status->setStyleSheet("background-color: rgb(192,192,192);");
    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setMinimumWidth(200);
    status->addPermanentWidget(label);


    QDockWidget *dock = new QDockWidget(this);
    objectManagerWindow = new CObjectManagerWindow(this);
    dock->setWidget(objectManagerWindow);
    dock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->layout()->sizeConstraint();
    dock->setWindowTitle("3D Object Property");
    addDockWidget(Qt::RightDockWidgetArea,dock);

    QDockWidget *dock2 = new QDockWidget(this);
    CMessageWindow * messageWindow = new CMessageWindow(dock2);
    dock2->setWidget(messageWindow);
    dock2->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
    dock2->setAllowedAreas(Qt::BottomDockWidgetArea| Qt::RightDockWidgetArea);
    dock2->layout()->sizeConstraint();
    dock2->setWindowTitle("Program Message");
    addDockWidget(Qt::BottomDockWidgetArea,dock2);


    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=]()
    {
        mouseToolPick->update();
        opengl->update();
        objectManagerWindow->update();
        label->setText(mouseToolPick->getMessage());
        stateLab->setText(mouseToolBezier->getState());
        QDateTime local(QDateTime::currentDateTime());
        localTime = local.toString(" [yyyy-MM-dd hh:mm:ss] ");
    });
    timer->start(10);

    redPickSphere = (CSphere*)factory->create("Red Pick Sphere",vessel->pose,vessel->size,vessel->color);
    bluePickSphere = (CSphere*)factory->create("Blue Pick Sphere",vessel->pose,vessel->size,vessel->color);
    outMessage->clear();

    setWindowTitle(tr("Learning and Coding !!! -- J.J.Chen 2020.11.3"));
    setMouseTracking(true);
}
CMainWindow::~CMainWindow()
{
    delete mouseToolManager;
    delete mouseToolView;
    delete mouseToolPick;
    delete mouseToolBezier;
    delete camera;
    delete factory;
    delete renderHelper;
    delete vessel;
    qDebug()<<"CMainWindow has been deleted.";
}

