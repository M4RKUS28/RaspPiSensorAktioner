#ifndef MYTYPES_H
#define MYTYPES_H

#include <QApplication>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QPushButton>
#include <QThread>

#include <QString>
#include <QFile>
#include <QDir>
#include <QList>
#include <QDateTime>

#include <iostream>
#include <vector>
#include <unistd.h>

#include "pimanager.h"

struct AKTION{
    AKTION();

    enum TYPE {
        EMPTY = 0,
        SLEEP = 1,
        SHOW_MSG = 2,
        RUN_COMMAND = 3,
        WINDOW_CHANCHE_VISIBILITY = 4,
        SOUND_MUTE = 5,
        RECHECK_CONDITION = 6,
        WINDOW_CHANCHE_POS = 7,
        //MOVE_MOUSE = 8,
        //SHUTDOWN_PC = 9
        //CECHK CONDITION = 10
        //SEND TCP MSG = 11

        EDIT_VAR = 12,

        GLOBAL_VAR = 999
    } type;

    enum WINDOW_NAME_PARITY {
        EXACTLY,
        CONTAINS,
        BEGINS_WITH,
        ENDS_WITH
    };

    static QString replaceSZ(QString text);
    static QString reReplaceSZ(QString text);

    static void setString( QString &ziel, const QString &value, bool hasSonderzeichen = true );
    static QString getString(  const QString &var, bool withSonderzeichen = true );

    bool enabled = true;

    struct Sleep {
        Sleep();
        Sleep(int m_sec, int sec, int min);
        int sleep_time_sekunden = 0;
        int sleep_time_minuten = 0;
        int sleep_time_m_sec = 0;
    } sleep;

    struct RunCommand {
        RunCommand();
        RunCommand(QString command, QString saveInVarNameWITHSZ, int saveInt );
        void setCommand(QString command);
        QString getCommand( bool withSonderzeichen = true) const;

        QString command, saveInVarName;
        int saveVar = false;


    } runCommand;

    struct ShowMsg {
        ShowMsg();
        ShowMsg( QString msg );
        void setMsg(QString command);
        QString getMsg( bool withSonderzeichen = true) const;
        QString title;
    private:
        QString msg;
    } showMsg;

    struct ChangeWindowVisibility {
        enum STATE {
            VISIBLE,
            HIDDEN
        } state;
        WINDOW_NAME_PARITY wNameParity;

        ChangeWindowVisibility();
        ChangeWindowVisibility( QString windowName, WINDOW_NAME_PARITY nP, STATE state );

        void setWindowName(QString windowName);
        QString getWindowName( bool withSonderzeichen = true) const;

    private:
        QString windowName;
    } changeWVisibility;

    struct SoundMute {
        enum STATE {
            UNMUTE,
            MUTE
        } state;

        SoundMute();
        SoundMute(STATE s);

    } soundMute;

    struct ReCheckCondition {
        enum EFFEKT {
            STOP_SEQUENZ,
            SKIP_NEXT_AKTION,
            STOP_PROGRAMM
        } effekt;

        ReCheckCondition();
        ReCheckCondition( EFFEKT ef );


    } reCheckCondition;

    struct MoveWindow {
        MoveWindow();
        MoveWindow( QString windowName, unsigned newPosX, unsigned newPosY, unsigned newWidth, unsigned newHeigth,
                    unsigned fsws, bool useFullScreen, bool useAbsolutePosX, bool useAbsolutePosY, bool useAbsoluteWidth, bool useAbsoluteHeight,
                    WINDOW_NAME_PARITY np  );

        void setWindowName(QString windowName);
        QString getWindowName( bool WithSonderZeichen = true ) const;

        int newPosX = -1, newPosY = -1, nWidth = -1,
            nHeigth = -1, fullScreenWindowScreen = -1,
        useFullScreen = false, useAbsolutePosX = true, useAbsoluteWidth = true, useAbsolutePosY = true, useAbsoluteHeight = true;
        WINDOW_NAME_PARITY wNameParity;
    private:
        QString windowName;
    } moveWindow;

    struct GlobalVar {
        GlobalVar();
        GlobalVar(QString nameWITHSZ, QString valueWITHSZ);

        void setName(QString nameMitSonderzeicehn);
        QString getName( bool withSonderzeichen = true) const;

        void setValue(QString valueMitSOnderzeicehn);
        QString getValue( bool withSonderzeichen = true) const;

        QString name, value;

    } globalVar;

    struct EditVar {
        EditVar();
        EditVar( QString Name, QString setValue  );
        void setEditVarName(QString nameMitSonderzeichen);
        void setEditVarNewValue(QString valueMitSonderzeichen);

        QString getName( bool withSonderzeichen = true) const;
        QString getNewValue( bool withSonderzeichen = true) const;

        QString name, newValue;

    } editVar;

    AKTION(enum TYPE t, struct Sleep s, struct RunCommand r, ShowMsg sMsg, ChangeWindowVisibility cwv, SoundMute sm, ReCheckCondition rcc, MoveWindow mw, EditVar eV);
    AKTION(QString globVarName, QString globVarValue);
};


struct MyRect {
    MyRect();
    MyRect( int x, int y, int w, int h);
    void fillUp( AKTION::MoveWindow w);
    int x, y, w, h;
};


struct AKTIONMNGR_DATA {
    AKTIONMNGR_DATA();
    AKTIONMNGR_DATA(QString name);
    AKTIONMNGR_DATA(const std::vector<AKTION> & v, QString name, int anzahl_ausfuehrungen, QString id, int aktualisierungsrate, bool enabled,
                    int indexBed1, int indexBed2, int indexBed3, QString bedInputText);

    enum STRING {
        NAME,
        BEDINGUNG_INPUT_TEXT
    };

    std::vector<AKTION> aktionList;
    int anzahl_ausfuehrungen;
    int aktualisierungsrate;
    int enabled = true;
    int indexBed1, indexBed2, indexBed3;
    QString id;


    QString getString(const STRING & str, bool withSonderzeichen = true) const;
    void  setStringValue(const STRING & str, const QString &value);


    //DATA for GLOABAL AKTIONMNGR DATA
    QString piAddr;


public:
    const QString getPiAddr() const;
    void setPiAddr(const QString &newPiAddr);

private:
    QString strings[3];


};




#endif // MYTYPES_H
