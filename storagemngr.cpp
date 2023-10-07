#include "storagemngr.h"


StorageMngr::StorageMngr(QString filePath)
    : filePath(filePath)
{
    QFile loadData(filePath);

    if( loadData.open(QFile::ReadWrite) == false) {
        fileOpenFailed();
    }

    loadData.close();
}

StorageMngr::~StorageMngr()
{

}

QList<AKTIONMNGR_DATA> StorageMngr::getInitDataList()
{
    std::cout << "loading ini data" << std::endl;

    QList<AKTIONMNGR_DATA> list;

    QFile loadData(filePath);
    if( loadData.open(QFile::ReadOnly) == false)
        fileOpenFailed();
    auto wholeTextLineSplitted = QString(loadData.readAll()).split('}');
    loadData.close();

    for ( auto &line : wholeTextLineSplitted ) {

        if( ! line.contains("ID=") || ! line.contains("{") )
            continue;
        if(line.size() > 1 && line.at(0) == '\n')
            line.remove(0, 1);

       // std::cout << "DATA: '" << line.toStdString() << "+(})'" << std::endl;
        auto aktionMngr = aktionMngrDataFromQString(line + "}");
        list.push_back(aktionMngr);

    }

    return list;
}


void StorageMngr::reStoreAll(QList<AKTIONMNGR_DATA> dataList)
{
    std::cout << "Storing..." << std::endl;

    QFile loadData(filePath);
    if( loadData.open(QFile::ReadWrite | QFile::Truncate ) == false)
        fileOpenFailed();

    for( int i = 0; i < dataList.size(); i++) {
        if(dataList.at(i).id == "") {
            perror("ERROR:try to store data with no id");
            continue;;
        }
        loadData.write( ( aktionMngrDataToQString( dataList.at(i) ) + "\n" ).toStdString().c_str() );
    }

    loadData.close();
}


AKTIONMNGR_DATA StorageMngr::getInitData(QString id)
{
    return aktionMngrDataFromQString( this->getInitDataString(id) );
}

QString StorageMngr::getInitDataString(QString id)
{
    if(id == "") {
        perror("ERROR:try to get data with empty id");
        return "";
    }

    QFile loadData(filePath);
    if( loadData.open(QFile::ReadOnly) == false)
        fileOpenFailed();
    auto wholeTextLineSplitted = QString(loadData.readAll()).split('}');

    for ( auto &line : wholeTextLineSplitted ) {
        if(line.contains("ID=" + id + ",")) {
            if(line.size() > 1 && line.at(0) == '\n')
                line.remove(0, 1);
            return line + "}";
        }
    }

    perror(("WARNUNG: Konnte keinen Eintrag mit der ID " + id.toStdString() + " finden").c_str());
    return "";
}

QString StorageMngr::getNewID()
{
    QString id = QString::number( QDateTime::currentSecsSinceEpoch() );
    while ( idExists(id) )
        id+="0";
    return id;
}

QString StorageMngr::aktionMngrDataToQString(const AKTIONMNGR_DATA &data)
{
    //Ablauf einstellungen
     auto retVal = "{" + QString( "ID=" + data.id + ",NAME=" + data.getString(data.NAME, false) + ",EXEC_COUNT=" + QString::number(data.anzahl_ausfuehrungen)
                                  + ",UPDATE_RATE=" + QString::number(data.aktualisierungsrate) + ",ENABLED=" + QString::number(data.enabled)
                                  + ",IND_BED_1=" + QString::number(data.indexBed1) + ",IND_BED_2=" + QString::number(data.indexBed2) + ",IND_BED_3=" + QString::number(data.indexBed3)
                                  + ",INPUT_BED=" + data.getString(data.BEDINGUNG_INPUT_TEXT, false) + ",MAIN_DATA_PI_ADDR=" +  data.piAddr + ",");

     //AKTIONEN
     for ( const auto & action : data.aktionList ) {
        retVal += "AKTION=[TYPE=";

         //save Type

        if(action.type == AKTION::EMPTY) {
            retVal += "EMPTY";
        } else if( action.type == AKTION::SLEEP){
            retVal += "SLEEP";
        } else if( action.type == AKTION::RUN_COMMAND){
            retVal += "RUN_COMMAND";
        }  else if( action.type == AKTION::SHOW_MSG){
            retVal += "SHOW_MSG";
        } else if( action.type == AKTION::SOUND_MUTE){
            retVal += "SOUND_MUTE";
        } else if( action.type == AKTION::WINDOW_CHANCHE_VISIBILITY){
            retVal += "WINDOW_CHANCHE_VISIBILITY";
        } else if( action.type == AKTION::WINDOW_CHANCHE_POS){
            retVal += "WINDOW_CHANCHE_POS";
        } else if( action.type == AKTION::RECHECK_CONDITION){
            retVal += "RECHECK_CONDITION";
        } else if( action.type == AKTION::GLOBAL_VAR){
            retVal += "GLOBAL_VAR";
        } else if( action.type == AKTION::EDIT_VAR){
            retVal += "EDIT_VAR";

        } else if( action.type == AKTION::EMPTY){
            retVal += "...";
        } else {
            perror(("Unbekannter Type: " + std::to_string(action.type)).c_str());
        }

        retVal += ";SLEEP_TIME_MIN=" + QString::number(action.sleep.sleep_time_minuten) + ";"
                + "SLEEP_TIME_SEC=" + QString::number(action.sleep.sleep_time_sekunden) + ";"
                + "SLEEP_TIME_M_SEC=" + QString::number(action.sleep.sleep_time_m_sec) + ";"

                + "RC_COMMAND=" + action.runCommand.getCommand(false) + ";"
                + "RC_VARNAME=" + action.runCommand.saveInVarName + ";"
                + "RC_SAVEOUTPUT=" +  QString::number(action.runCommand.saveVar) + ";"


                + "CWV_W_NAME=" + action.changeWVisibility.getWindowName(false) + ";"
                + "CWV_W_PARITY=" + QString::number(action.changeWVisibility.wNameParity) + ";"
                + "CWV_W_STAE=" + QString( action.changeWVisibility.state == action.changeWVisibility.HIDDEN ? "HIDE" : "SHOW" ) + ";"
                + "SHOW_MSG_TEXT=" + action.showMsg.getMsg(false) + ";"

                + "MW_W_PARITY=" +  QString::number(action.moveWindow.wNameParity) + ";"
                + "MW_W_NAME=" + action.moveWindow.getWindowName(false) + ";"
                + "MW_W_NEW_POS_X=" +  QString::number(action.moveWindow.newPosX) + ";"
                + "MW_W_NEW_POS_Y=" +  QString::number(action.moveWindow.newPosY) + ";"
                + "MW_W_NEW_WIDTH=" +  QString::number(action.moveWindow.nWidth) + ";"
                + "MW_W_NEW_HEIGTH=" +  QString::number(action.moveWindow.nHeigth) + ";"
                + "MW_FS_S=" +  QString::number(action.moveWindow.fullScreenWindowScreen) + ";"
                + "MW_UFS=" +  QString::number(action.moveWindow.useFullScreen) + ";"
                + "MW_USE_ABSOLUTE_X=" +  QString::number(action.moveWindow.useAbsolutePosX) + ";"
                + "MW_USE_ABSOLUTE_Y=" +  QString::number(action.moveWindow.useAbsolutePosY) + ";"
                + "MW_USE_ABSOLUTE_WIDTH=" +  QString::number(action.moveWindow.useAbsoluteWidth) + ";"
                + "MW_USE_ABSOLUTE_HEIGHT=" +  QString::number(action.moveWindow.useAbsoluteHeight) + ";"
                + "GLOBAL_VAR_NAME=" +  action.globalVar.name  + ";"
                + "GLOBAL_VAR_VALUE=" + action.globalVar.value   + ";"
                + "EDIT_VAR_NAME=" + action.editVar.name   + ";"
                + "EDIT_VAR_NEW_VALUE=" + action.editVar.newValue   + ";"



                ;



        retVal += "],";
     }


     return retVal + "}";
}

AKTIONMNGR_DATA StorageMngr::aktionMngrDataFromQString(QString str)
{
    //std::cout << "CONVERT: " << str.toStdString() << std::endl;
    if( ! str.contains("{") || ! str.contains("}") ) {
        std::cout << "INVALID AKTIONMNGR_STRING: " << str.toStdString() << std::endl;
        AKTIONMNGR_DATA();
    }

    //check what happen if string is invalid

    AKTIONMNGR_DATA retVal;


    str.remove(0, str.indexOf("{") + 1);
    str.remove(str.indexOf("}"), str.length() - str.indexOf("}"));
    QStringList strList = str.split(',');
    for( const auto &line : strList ) {
        QString what = line.left(line.indexOf("="));
        QString value = line.right( line.length() - line.indexOf("=") - 1);
        //std::cout << "NEW_LINE:l(" << line.toStdString() << ") w(" << what.toStdString() << ") = v(" << value.toStdString() << ")" << std::endl;

        if( ! QString(line).contains("=") || what.length() <= 0 )
            continue;


        if( what == "AKTION") {
            AKTION a = getAktionByQString( value );

            if(a.type == a.EMPTY) {
                std::cout << "getAktionByQString() failed, INVALID DATA: " << value.toStdString() << std::endl;
                continue;
            }
            retVal.aktionList.push_back( a );

        } else if ( what == "ID" ) {
            retVal.id = value;

        } else if ( what == "NAME" ) {
            retVal.setStringValue(AKTIONMNGR_DATA::NAME, value );

        } else if ( what == "EXEC_COUNT" ) {
            if(saveIntInVarFailed(retVal.anzahl_ausfuehrungen, value))
                    return AKTIONMNGR_DATA();

        } else if ( what == "UPDATE_RATE" ) {
            if( saveIntInVarFailed(retVal.aktualisierungsrate, value) )
                return AKTIONMNGR_DATA();

        } else if ( what == "ENABLED" ) {
            if( saveIntInVarFailed(retVal.enabled, value) )
                return AKTIONMNGR_DATA();

        } else if ( what == "IND_BED_1" ) {
            if( saveIntInVarFailed(retVal.indexBed1, value) )
                return AKTIONMNGR_DATA();

        } else if ( what == "IND_BED_2" ) {
            if( saveIntInVarFailed(retVal.indexBed2, value) )
                return AKTIONMNGR_DATA();

        } else if ( what == "IND_BED_3" ) {
            if( saveIntInVarFailed(retVal.indexBed3, value) )
                return AKTIONMNGR_DATA();

        } else if ( what == "INPUT_BED" ) {
            retVal.setStringValue(AKTIONMNGR_DATA::BEDINGUNG_INPUT_TEXT, value );

        } else if ( what == "MAIN_DATA_PI_ADDR" ) {
            retVal.piAddr = value ;

        } else if ( what == "id" ) {
            retVal.id = value;
        } else if ( what == "id" ) {
            retVal.id = value;
        } else if ( what == "id" ) {
            retVal.id = value;
        } else if ( what == "id" ) {
            retVal.id = value;
        } else {
            std::cout << "INVALID TYPE: " << what.toStdString()
                      << " == " << value.toStdString() << std::endl;
        }

    }


    return retVal;
}

AKTION StorageMngr::getAktionByQString(QString str)
{
    AKTION aktion;

    str.remove(0, 1);
    str.remove(str.length() - 1, 1);
    QStringList strList = str.split(';');
    for( const auto &line : qAsConst(strList) ) {
        if(line == "")
            continue;
        QString what = line.left(line.indexOf("="));
        QString value = line.right(line.length() - line.indexOf("=") - 1);
        //std::cout << "NEW_LINE_AKTION: w(" << what.toStdString() << ") = v(" << value.toStdString() << ")" << std::endl;

        if( ! QString(line).contains("=") || what.length() <= 0 )
            continue;


        if( what == "TYPE" ) {
            if(value == "SLEEP" )
                aktion.type = AKTION::SLEEP;
            else if( value == "RUN_COMMAND" )
                aktion.type = AKTION::RUN_COMMAND;
            else if( value == "" || value == "EMPTY" )
                aktion.type = AKTION::EMPTY;
            else if( value == "SHOW_MSG" )
                aktion.type = AKTION::SHOW_MSG;
            else if( value == "SOUND_MUTE" )
                aktion.type = AKTION::SOUND_MUTE;
            else if( value == "WINDOW_CHANCHE_POS" )
                aktion.type = AKTION::WINDOW_CHANCHE_POS;
            else if( value == "WINDOW_CHANCHE_VISIBILITY" )
                aktion.type = AKTION::WINDOW_CHANCHE_VISIBILITY;
            else if ( value == "RECHECK_CONDITION" )
                aktion.type = AKTION::RECHECK_CONDITION;
            else if( value == "-" )
                aktion.type = AKTION::EMPTY;
            else if( value == "GLOBAL_VAR" )
                aktion.type = AKTION::GLOBAL_VAR;
            else if( value == "EDIT_VAR" )
                aktion.type = AKTION::EDIT_VAR;

            else if( value == "-" )
                aktion.type = AKTION::EMPTY;

            else {
                std::cout << "INVALID TYPE: " << value.toStdString() << std::endl;
                return AKTION();
            }

        } else if( what == "SLEEP_TIME_MIN" ) {
            if(saveIntInVarFailed( aktion.sleep.sleep_time_minuten, value ) )
                return AKTION();

        } else if( what == "SLEEP_TIME_SEC" ) {
            if(saveIntInVarFailed( aktion.sleep.sleep_time_sekunden, value ) )
                return AKTION();

        } else if( what == "RC_COMMAND" ) {
            aktion.runCommand.setCommand( value );

        } else if( what == "SHOW_MSG_TEXT" ) {
            aktion.showMsg.setMsg( value );
        } else if( what == "CWV_W_NAME" ) {
            aktion.changeWVisibility.setWindowName( value );
        } else if( what == "CWV_W_PARITY" ) {
            int i;
            if(saveIntInVarFailed(i, value) )
                return AKTION();
            //check if i is a possible enum num \-/

            aktion.changeWVisibility.wNameParity = AKTION::WINDOW_NAME_PARITY( i );

        } else if( what == "CWV_W_STAE" ) {
            aktion.changeWVisibility.state = ((value == "HIDE") ? aktion.changeWVisibility.HIDDEN : aktion.changeWVisibility.VISIBLE);

        } else if( what == "MW_W_PARITY" ) {
            int i;
            if(saveIntInVarFailed(i, value) )
                return AKTION();
            //check if i is a possible enum num \-/

            aktion.moveWindow.wNameParity = AKTION::WINDOW_NAME_PARITY( i );

        } else if( what == "MW_W_NAME" ) {
            aktion.moveWindow.setWindowName( value );

        } else if( what == "MW_W_NEW_POS_X" ) {
            if(saveIntInVarFailed(aktion.moveWindow.newPosX, value) )
                return AKTION();

        } else if( what == "MW_W_NEW_POS_Y" ) {
            if(saveIntInVarFailed(aktion.moveWindow.newPosY, value) )
                return AKTION();

        } else if( what == "MW_W_NEW_WIDTH" ) {
            if(saveIntInVarFailed(aktion.moveWindow.nWidth, value) )
                return AKTION();

        } else if( what == "MW_W_NEW_HEIGTH" ) {
            if(saveIntInVarFailed(aktion.moveWindow.nHeigth, value) )
                return AKTION();

        } else if( what == "MW_FS_S" ) {
            if(saveIntInVarFailed(aktion.moveWindow.fullScreenWindowScreen, value) )
                return AKTION();

        } else if( what == "MW_UFS" ) {
            if(saveIntInVarFailed(aktion.moveWindow.useFullScreen, value) )
                return AKTION();

        } else if( what == "MW_USE_ABSOLUTE_X" ) {
            if(saveIntInVarFailed(aktion.moveWindow.useAbsolutePosX, value) )
                return AKTION();

        } else if( what == "MW_USE_ABSOLUTE_Y" ) {
            if(saveIntInVarFailed(aktion.moveWindow.useAbsolutePosY, value) )
                return AKTION();

        } else if( what == "MW_USE_ABSOLUTE_WIDTH" ) {
            if(saveIntInVarFailed(aktion.moveWindow.useAbsoluteWidth, value) )
                return AKTION();

        } else if( what == "MW_USE_ABSOLUTE_HEIGHT" ) {
            if(saveIntInVarFailed(aktion.moveWindow.useAbsoluteHeight, value) )
                return AKTION();

        } else if( what == "SLEEP_TIME_M_SEC" ) {
            if(saveIntInVarFailed( aktion.sleep.sleep_time_m_sec, value ) )
                return AKTION();

        } else if( what == "GLOBAL_VAR_NAME" ) {
            aktion.globalVar.name = value;

        } else if( what == "GLOBAL_VAR_VALUE" ) {
            aktion.globalVar.value = value;

        } else if( what == "EDIT_VAR_NAME" ) {
            aktion.editVar.name = value;

        } else if( what == "EDIT_VAR_NEW_VALUE" ) {
            aktion.editVar.newValue = value;

        } else if( what == "RC_VARNAME" ) {
            aktion.runCommand.saveInVarName = value;

        } else if( what == "RC_SAVEOUTPUT" ) {
            if(saveIntInVarFailed( aktion.runCommand.saveVar, value ) )
                return AKTION();

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else if( what == "" ) {

        } else {
            std::cout << "INVALID ACKTION TYPE: " << what.toStdString()
                      << " == " << value.toStdString() << std::endl;
        }


    }

    return aktion;
}

bool StorageMngr::saveIntInVarFailed(int &saveTo, const QString &str)
{
    bool ok;
    saveTo = str.toInt(&ok);
    if(!ok)
        std::cout << "Ungültige Zahl!: '" << str.toStdString() << "'" << std::endl;
    return !ok;
}

void StorageMngr::fileOpenFailed()
{
    QMessageBox::critical(nullptr, "Failed to open file",
                         "Konnte Datei zum wiederherstellen der alten Einstellungen nicht öffen: \"" + QString("") + "\"");
    exit(12);
}

bool StorageMngr::idExists(QString id)
{
    QFile loadData(filePath);
    if( loadData.open(QFile::ReadOnly) == false)
        fileOpenFailed();

    return (QString(loadData.readAll()).contains( "ID=" + id + "," ) ? true : false);
}
