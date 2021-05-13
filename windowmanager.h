#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


#include "mytypes.h"
#include <QRect>
#include <windows.h>
#include <QApplication>
#include <QScreen>

class WindowManager
{
public:
    WindowManager();

    void changeWindowVisibility( AKTION::ChangeWindowVisibility w);
    void moveWindow( AKTION::MoveWindow w);
    QPoint getGlobalMousePos();

    MyRect getFullScreenRect( int screen );

private:
    int hideWindow(QString wname);
    int showWindow(QString wname);
    int reSizeWindow(QString wname, MyRect windowR);
    MyRect getCurrentWindowRect(QString wname);

    QString getWindowNameFromList(AKTION::WINDOW_NAME_PARITY wp, QString name);
    QList<QString> getWindowList();
    std::pair<int, int> getScreenSize();

    int getScreenList();
};

#endif // WINDOWMANAGER_H
