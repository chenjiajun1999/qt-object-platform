#include <QApplication>
#include "window/CMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont f("微软雅黑",10);
    a.setFont(f);

    CMainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
