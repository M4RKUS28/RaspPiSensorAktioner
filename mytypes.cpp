#include "mytypes.h"


AKTION::AKTION()
    : type(TYPE::EMPTY)
{

}

QString AKTION::replaceSZ(QString text)
{
    return text.replace(";", "#SIMICOLON#").replace(",", "#KOMMA#").replace("[", "#ECK_KLAMMER_AUF#").replace
                       ("]", "#ECK_KLAMMER_ZU#").replace("{", "#GESCHW_KLAMMER_AUF#").replace("}", "#GESCHW_KLAMMER_ZU#").replace("\n", "#BACKSLASHn#") ;
}

QString AKTION::reReplaceSZ(QString text) {
    return text.replace("#KOMMA#", ",").replace("#SIMICOLON#", ";" ).replace("#ECK_KLAMMER_AUF#", "[" ).replace( "#ECK_KLAMMER_ZU#", "]" ).
            replace("#GESCHW_KLAMMER_AUF#", "{").replace("#GESCHW_KLAMMER_ZU#", "}").replace("#BACKSLASHn#", "\n");
}

void AKTION::setString(QString &ziel, const QString &value, bool hasSonderzeichen)
{
    ziel = hasSonderzeichen ? replaceSZ(value) : value;
}

QString AKTION::getString(const QString &var, bool withSonderzeichen)
{
    return withSonderzeichen ? reReplaceSZ(var) : var;
}

AKTION::AKTION(AKTION::TYPE t, AKTION::Sleep s, AKTION::RunCommand r, AKTION::ShowMsg sMsg, AKTION::ChangeWindowVisibility cwv,
               AKTION::SoundMute sm, AKTION::ReCheckCondition rcc, AKTION::MoveWindow mw, EditVar eV)
    : type(t), sleep(s), runCommand(r), showMsg(sMsg), changeWVisibility(cwv),
      soundMute(sm), reCheckCondition(rcc), moveWindow(mw), editVar(eV)
{

}

AKTION::AKTION(QString globVarName, QString globVarValue)
    : type(TYPE::GLOBAL_VAR), globalVar(GlobalVar(globVarName, globVarValue) )
{

}

AKTION::Sleep::Sleep()
{

}

AKTION::Sleep::Sleep(int m_sec, int sec, int min)
    : sleep_time_sekunden(sec), sleep_time_minuten(min), sleep_time_m_sec(m_sec)
{

}

AKTION::RunCommand::RunCommand()
{

}

AKTION::RunCommand::RunCommand(QString command, QString saveInVarNameWITHSZ, int saveInt)
{
    setCommand(command);
    AKTION::setString( this->saveInVarName, saveInVarNameWITHSZ, true);
    saveVar = saveInt;
}

void AKTION::RunCommand::setCommand(QString command)
{
    this->command = reReplaceSZ( command );
}

QString AKTION::RunCommand::getCommand(bool withSonderzeichen) const
{
    if(withSonderzeichen)
        return this->command;
    else
        return replaceSZ(this->command);}

AKTION::ShowMsg::ShowMsg()
{

}

AKTION::ShowMsg::ShowMsg(QString msg)
{
    setMsg(msg);
}

void AKTION::ShowMsg::setMsg(QString command)
{
    this->msg = reReplaceSZ(command);
}

QString AKTION::ShowMsg::getMsg(bool withSonderzeichen) const
{
    if(withSonderzeichen)
        return this->msg;
    else
        return reReplaceSZ(this->msg);
}

AKTION::ChangeWindowVisibility::ChangeWindowVisibility()
{

}

AKTION::ChangeWindowVisibility::ChangeWindowVisibility(QString windowName, WINDOW_NAME_PARITY nP, AKTION::ChangeWindowVisibility::STATE s)
    :  state(s), wNameParity(nP)
{
    setWindowName(windowName);
}

void AKTION::ChangeWindowVisibility::setWindowName(QString windowName)
{
    this->windowName = reReplaceSZ(windowName);
}

QString AKTION::ChangeWindowVisibility::getWindowName(bool withSonderzeichen) const
{
    if(withSonderzeichen)
        return this->windowName;
    else
        return replaceSZ(this->windowName);
}





AKTIONMNGR_DATA::AKTIONMNGR_DATA()
{

}

AKTIONMNGR_DATA::AKTIONMNGR_DATA(QString name)
{
    setStringValue(STRING::NAME, name);
}

AKTIONMNGR_DATA::AKTIONMNGR_DATA(const std::vector<AKTION> &v, QString name, int anzahl_ausfuehrungen, QString id, int aktualisierungsrate,
                                 bool enabled,  int indexBed1, int indexBed2, int indexBed3, QString bedInputText)
    : aktionList(v), anzahl_ausfuehrungen(anzahl_ausfuehrungen), aktualisierungsrate(aktualisierungsrate),
      enabled(enabled),indexBed1(indexBed1), indexBed2(indexBed2), indexBed3(indexBed3), id(id)
{
    setStringValue(STRING::NAME, name);
    setStringValue(STRING::BEDINGUNG_INPUT_TEXT, bedInputText);

}

QString AKTIONMNGR_DATA::getString(const STRING &str, bool withSonderzeichen) const
{
    if(withSonderzeichen)
        return  strings[str];
    else
        return AKTION::replaceSZ(strings[str]);
}



void AKTIONMNGR_DATA::setStringValue(const AKTIONMNGR_DATA::STRING &str, const QString &value)
{
    strings[str] = AKTION::reReplaceSZ( value );
}

const QString AKTIONMNGR_DATA::getPiAddr() const
{
    return AKTION::reReplaceSZ(piAddr);
}

void AKTIONMNGR_DATA::setPiAddr(const QString &newPiAddr)
{
    piAddr = AKTION::replaceSZ(newPiAddr);
}



AKTION::SoundMute::SoundMute()
{

}

AKTION::SoundMute::SoundMute(AKTION::SoundMute::STATE s)
    : state(s)
{

}

AKTION::MoveWindow::MoveWindow()
{

}

AKTION::MoveWindow::MoveWindow(QString windowName, unsigned newPosX, unsigned newPosY, unsigned newWidth,
                               unsigned newHeigth, unsigned fsws, bool useFullScreen, bool useAbsolutePosX, bool useAbsolutePosY, bool useAbsoluteWidth, bool useAbsoluteHeight, AKTION::WINDOW_NAME_PARITY np)
    : newPosX(newPosX), newPosY(newPosY), nWidth(newWidth), nHeigth(newHeigth),
      fullScreenWindowScreen(fsws), useFullScreen(useFullScreen), useAbsolutePosX(useAbsolutePosX),
      useAbsoluteWidth(useAbsoluteWidth) ,useAbsolutePosY(useAbsolutePosY), useAbsoluteHeight(useAbsoluteHeight),
      wNameParity(np)
{
    this->setWindowName(windowName);
}

void AKTION::MoveWindow::setWindowName(QString windowName)
{
    this->windowName = reReplaceSZ(windowName);
}

QString AKTION::MoveWindow::getWindowName(bool WithSonderZeichen) const
{
    if(WithSonderZeichen)
        return this->windowName;
    else
        return replaceSZ(this->windowName);
}

AKTION::ReCheckCondition::ReCheckCondition()
{

}

AKTION::ReCheckCondition::ReCheckCondition(AKTION::ReCheckCondition::EFFEKT ef)
    : effekt(ef)
{

}

MyRect::MyRect()
    : x(0), y(0), w(0), h(0)
{

}

MyRect::MyRect(int x_, int y_, int w_, int h_)
    : x(x_), y(y_), w(w_), h(h_)
{

}

void MyRect::fillUp(AKTION::MoveWindow w)
{
    if( w.useAbsolutePosX )
        this->x = w.newPosX;
    else
        this->x += w.newPosX;

    if(w.useAbsolutePosY )
        this->y = w.newPosY;
    else
        this->y += w.newPosY;

    if( w.useAbsoluteWidth  )
        this->w = w.nWidth;
    else
        this->w += w.nWidth;

    if( w.useAbsoluteHeight )
        this->h = w.nHeigth;
    else
        this->h += w.nHeigth;

}

AKTION::GlobalVar::GlobalVar()
{

}

AKTION::GlobalVar::GlobalVar(QString nameWITHSZ, QString valueWITHSZ)
{
    name = replaceSZ(nameWITHSZ);
    value = replaceSZ(valueWITHSZ);
}

void AKTION::GlobalVar::setName(QString nameMitSonderzeicehn)
{
    name = replaceSZ(nameMitSonderzeicehn);
}

QString AKTION::GlobalVar::getName(bool withSonderzeichen) const
{
    return withSonderzeichen ? name : reReplaceSZ(name);
}

void AKTION::GlobalVar::setValue(QString valueMitSOnderzeicehn)
{
    value = replaceSZ(valueMitSOnderzeicehn);
}

QString AKTION::GlobalVar::getValue(bool withSonderzeichen) const
{
    return withSonderzeichen ? value : reReplaceSZ(value);
}

AKTION::EditVar::EditVar()
{

}

AKTION::EditVar::EditVar(QString Name, QString setValue)
{
    setEditVarName(Name);
    setEditVarNewValue(setValue);
}

void AKTION::EditVar::setEditVarName(QString nameMitSonderzeichen)
{
    name = replaceSZ(nameMitSonderzeichen);
}

void AKTION::EditVar::setEditVarNewValue(QString valueMitSonderzeichen)
{
    newValue = replaceSZ(valueMitSonderzeichen);
}

QString AKTION::EditVar::getName(bool withSonderzeichen) const
{
    return withSonderzeichen ? name : reReplaceSZ(name);
}

QString AKTION::EditVar::getNewValue(bool withSonderzeichen) const
{
    return withSonderzeichen ? newValue : reReplaceSZ( newValue );
}
