#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


#include "mytypes.h"
#include <QRect>
#include <windows.h>
#include <QApplication>
#include <QScreen>
#include <QProcess>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <unistd.h>
#include <fstream>

#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h> //</endpointvolume.h></mmdeviceapi.h></windows.h>


class WindowManager
{
public:
    WindowManager();

    void changeWindowVisibility( AKTION::ChangeWindowVisibility w);
    void moveWindow( AKTION::MoveWindow w);
    QPoint getGlobalMousePos();

    MyRect getFullScreenRect( int screen );


    QString runCommand(QObject *p, QString command, int maxWaitTime = -1 /*unendlich lang*/);

    unsigned long getCurrenSoundVolume();
    void setSoundVolume(float fLevel);

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
