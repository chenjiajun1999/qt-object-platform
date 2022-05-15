#include "CVessel.h"

CVessel *vessel = new CVessel();
CVessel::CVessel()
{
    qDebug() << "CVessel has been created";
}
CVessel::~CVessel()
{
    qDebug() << "CVessel has been deleted";
}
