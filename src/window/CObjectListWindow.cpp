#include "CObjectListWindow.h"

CObjectListWindow::CObjectListWindow(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<< "CObjectListWindow has been created.";

    setWindowTitle(tr("Object List"));
    setAttribute(Qt::WA_DeleteOnClose);

   // QGridLayout *layout = new QGridLayout(this);
}
CObjectListWindow::~CObjectListWindow()
{
    qDebug()<< "CObjectListWindow has been deleted.";

   // QGridLayout *layout = new QGridLayout(this);
}
