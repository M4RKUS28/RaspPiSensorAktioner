#include "windowmanager.h"

int CALLBACK speichereFenster(HWND hwnd, LPARAM lParam){
    const unsigned long TITLE_SIZE = 1024;
    char windowTitle[TITLE_SIZE];

    GetWindowTextA(hwnd, windowTitle, TITLE_SIZE);
    QString title(windowTitle);

    if ( ::GetWindowTextLength(hwnd) == 0 || title == "Program Manager")
        return true;

    reinterpret_cast<QList<QString>*>(lParam)->push_back( title );
    return true;
}


WindowManager::WindowManager()
{


}

void WindowManager::changeWindowVisibility(AKTION::ChangeWindowVisibility w)
{
    QString name;
    if( (name = getWindowNameFromList( w.wNameParity, w.getWindowName() )) == "" ) {
        std::cerr << "getWindowNameFromList() failed: no window returned" << std::endl;
        return;
    }
    if(w.state == w.HIDDEN)
        hideWindow( name );
    else
        showWindow( name );
    return;
}

void WindowManager::moveWindow(AKTION::MoveWindow w)
{
    QString name;
    MyRect rect;
    if( (name = getWindowNameFromList( w.wNameParity, w.getWindowName() )) == "" ) {
        std::cerr << "getWindowNameFromList() failed: no window returned" << std::endl;
        return;
    }

    if(w.useFullScreen)
        rect = getFullScreenRect( w.fullScreenWindowScreen );
    else {
        rect = getCurrentWindowRect( name );
        rect.fillUp( w );
    }


    if( reSizeWindow( name, rect) != 0) {
        perror("reSizeWindow failed");
        return;
    }
    return;
}
#include <QWidget>
#include <QCursor>

QPoint WindowManager::getGlobalMousePos( )
{
    return QCursor::pos();
}

int WindowManager::hideWindow( QString wname )
{
    HWND window = ::FindWindowA(0, wname.toStdString().c_str() );
    if(! window ) {
        std::cout << "No windows found" << std::endl;
        return 1;
    } else if(/* ! SetWindowPos (window, HWND_TOP, 0, 0, 0, 0, SWP_HIDEWINDOW  //hide window
                                                            | SWP_NOMOVE // ignore x,y
                                                             | SWP_NOOWNERZORDER // ignore HWND_TOP
                                                            | SWP_NOSIZE // ignore w,h
                                                            //| SWP_NOZORDER // ignore HWND_TOP
                             )*/
 !ShowWindow(window, SW_HIDE)
              ) {
        std::cout << "Hide failed" << std::endl;
        return 3;
    }
    return 0;
}

int WindowManager::showWindow(QString wname)
{

    HWND window = ::FindWindowA(0, wname.toStdString().c_str() );
    if(! window ) {
        std::cout << "No windows found" << std::endl;
        return 1;
    } else if(false && ! SetWindowPos (window, HWND_TOP, 0, 0, 0, 0, SWP_SHOWWINDOW  //hide window
                               | SWP_NOMOVE // ignore x,y
                               // | SWP_NOOWNERZORDER // ignore HWND_TOP
                               | SWP_NOSIZE // ignore w,h
                               // | SWP_NOZORDER // ignore HWND_TOP
                               | SWP_NOACTIVATE

       //ShowWindow(window, SW_SHOW) )
               ) ) {
        std::cout << "Show failed" << std::endl;
        return 2;
    }

    ShowWindow(window, SW_SHOW );

     SetForegroundWindow( window );
    SetActiveWindow ( window );
    ::SetFocus( window );

    return 0;
}

int WindowManager::reSizeWindow(QString wname, MyRect windowR)
{
    HWND window = ::FindWindowA(0, wname.toStdString().c_str() );
    if(! window ) {
        std::cout << "No windows found" << std::endl;
        return 1;
    }

    std::cout << windowR.x << " " <<  windowR.y << " " <<  windowR.w << " " <<  windowR.h << std::endl;

    if( // !MoveWindow(window, windowR.x, windowR.y, windowR.w, windowR.h, true)
        !SetWindowPos( window, HWND_TOP, windowR.x, windowR.y, windowR.w, windowR.h, 0)
            ) {
        std::cout << "Moving failed" << std::endl;
        return 2;
    }

    return 0;
}


MyRect WindowManager::getCurrentWindowRect( QString wname)
{
    HWND window = ::FindWindowA(0, wname.toStdString().c_str() );
    if(! window ) {
        std::cout << "No windows found" << std::endl;
        return MyRect();
    }

    RECT rect;
    if( GetWindowRect( window, &rect) == 0 ) {
        std::cout << "Get Rect failed: " << GetLastError() << std::endl;
        return MyRect();
    }
    std::cout << rect.left << " " <<  rect.top << " " <<  rect.right << " " <<  rect.bottom << std::endl;

    return MyRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
}

QString WindowManager::getWindowNameFromList(AKTION::WINDOW_NAME_PARITY wp, QString name)
{
    QStringList sl;

    auto list = getWindowList();
    for ( const auto& title : qAsConst(list) ) {
      //  std::cout << title.toStdString() << "..." << std::endl;
        if( ( wp == AKTION::WINDOW_NAME_PARITY::EXACTLY     &&  title == name            ) ||
            ( wp == AKTION::WINDOW_NAME_PARITY::CONTAINS    &&  title.contains( name   ) ) ||
            ( wp == AKTION::WINDOW_NAME_PARITY::BEGINS_WITH &&  title.startsWith( name ) ) ||
            ( wp == AKTION::WINDOW_NAME_PARITY::ENDS_WITH   &&  title.endsWith( name   ) )
          ) {
            std::cout << "Title: " << title.toStdString() << std::endl;
            sl.push_back( title );
        }
    }

    if(sl.size() <= 0 || sl.size() > 1)
        return "";
    else
        return  sl.at(0);
}

QList<QString> WindowManager::getWindowList()
{
    QList<QString> titles;
    if( EnumWindows(speichereFenster, reinterpret_cast<LPARAM>(&titles)) == false ) {
        std::cout << "EnumWindows failed" << std::endl;
        return QList<QString>();
    }
    return titles;
}

int WindowManager::getScreenList()
{
    return QApplication::screens().count();
}

MyRect WindowManager::getFullScreenRect(int screen)
{
    auto screens = QApplication::screens();
    if(screen <= 0 || screen > screens.count()) {
        std::cout << "Invalid screen" << std::endl;
        return MyRect();
    }
    const auto &sc = screens.at( screen - 1);
    return MyRect(sc->geometry().x() , sc->geometry().y() , sc->geometry().width() ,sc->geometry().height() );
}




