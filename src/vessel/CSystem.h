#ifndef CSYSTEM_H
#define CSYSTEM_H

#include <QDebug>
#include "tool/CCamera.h"
#include "tool/CMouseToolManager.h"
#include "tool/CMouseToolView.h"
#include "tool/CMouseToolPick.h"
#include "tool/CMouseToolBezier.h"
#include "tool/CFactory.h"
#include "tool/CTimer.h"
#include "CVessel.h"
#include "CRenderList.h"
#include "window/CMainWindow.h"
#include "window/CMessageWindow.h"
#include <QDateTime>

class CFactory;
class CMouseToolManager;
class CMouseToolView;
class CMouseToolPick;
class CMouseToolBezier;

extern CCamera *camera;
extern CFactory *factory;
extern CVessel *vessel;
extern CRenderList *renderHelper;
extern CMouseToolManager * mouseToolManager;
extern CMouseToolView * mouseToolView;
extern CMouseToolPick * mouseToolPick;
extern CMouseToolBezier *mouseToolBezier;
extern QTextEdit *outMessage;
extern QString localTime;



#endif // CSYSTEM_H
