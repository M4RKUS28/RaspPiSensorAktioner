#include "aktionmngr.h"
#include "ui_aktionmngr.h"


AktionMngr::AktionMngr(QWidget *parent, PiManager *piMngr, QString id, QMap<QString, QString> *gVars)
    :  QDialog(parent),  ui(new Ui::AktionMngr), gVarsPrivate(gVars)
{
    ui->setupUi(this);
    mThread = new AktionExecuterThread(this, piMngr);

    this->id = id;
}

AktionMngr::AktionMngr(QWidget *parent, PiManager *piMngr, const AKTIONMNGR_DATA &initData, QMap<QString, QString> *gVars)
    :  QDialog(parent),   ui(new Ui::AktionMngr), gVarsPrivate(gVars)
{
    ui->setupUi(this);
    mThread = new AktionExecuterThread(this, piMngr);

    //Lade standart einstellungen
    loadInitData(initData);

}


AktionMngr::~AktionMngr()
{
    delete mThread; // delete Thread bevore ui, etc !!!!!!, thread verwerndet die anderen objecte



    aktionList.clear();
    delete ui;

    perror("~AktionMngr");
}


void AktionMngr::on_pushButton_add_aktion_clicked()
{
    //create  gui with empty aktion
    AktionSelektDialog newAktionGui(this);
    newAktionGui.show();
    //wait for click finish
    if( newAktionGui.QDialog::exec() == 0 /* == abgelehnt */ ) {    // accpet ==> automtic hide
        return;
    }

    //create new item
    QListWidgetItem * newLWI = new QListWidgetItem( getListName( newAktionGui.getAktion() ) );

    int index = ui->listWidget_aktionen->currentRow() + 1;
    if( index > (int)aktionList.size() ) {
        std::cerr << "Kann neue Aktion nicht in Listen einfügen, Zu einfügende Stelle ist größer als Listen!" << std::endl;
        delete newLWI;
        return;
    }
    //save aktion
    this->aktionList.insert(aktionList.begin() + index, newAktionGui.getAktion());
    //add item to list
    this->ui->listWidget_aktionen->insertItem(index, newLWI);
    this->ui->listWidget_aktionen->setCurrentItem(newLWI);
}



void AktionMngr::on_pushButton_moveUp_clicked()
{
    int row;
    if(ui->listWidget_aktionen->selectedItems().size() <= 0) {
        std::cout << "NIx ausgewählt!" << std::endl;
        return;
    } else if( (row = ui->listWidget_aktionen->currentRow() ) <= 0 ) {
        std::cout << "Schon ganz oben!" << std::endl;
        return; // wichtig sonst stürzt programm beu current item ab
    }

    //move current selected one up ( take from and insert)
    ui->listWidget_aktionen->insertItem( row - 1,   ui->listWidget_aktionen->takeItem( row ) );
    ui->listWidget_aktionen->setCurrentRow( row - 1);
    //repos Vector
    iter_swap(aktionList.begin() + row -1, aktionList.begin() + row );
}

void AktionMngr::on_pushButton_moveDown_clicked()
{
    int row;
    if(ui->listWidget_aktionen->selectedItems().size() <= 0) {
        std::cout << "NIx ausgewählt!" << std::endl;
        return;
    } else if( (row = ui->listWidget_aktionen->currentRow() ) >= (ui->listWidget_aktionen->count() - 1) ) {
        std::cout << "Schon ganz unten!" << std::endl;
        return;
    }

    //move current selected one up ( take from and insert)
    ui->listWidget_aktionen->insertItem( row + 1,   ui->listWidget_aktionen->takeItem( row ) );
    ui->listWidget_aktionen->setCurrentRow( row + 1);
    //repüos vector
    iter_swap(aktionList.begin() + row, aktionList.begin() + row + 1 );

}


void AktionMngr::on_listWidget_aktionen_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->listWidget_aktionen->row(item);
    if(index < 0 || index >= static_cast<int>(this->aktionList.size()) ) {
        std::cout << "Error: Invalid User Data" << std::endl;
        return;
    }

    //create gui with old settings
    AktionSelektDialog newAktionGui(this, this->aktionList.at(index));
    newAktionGui.show();

    //wait for finish editing
    if( newAktionGui.exec() == 0 /* == abgelehnt */ )
        return;

    //save edited aktion + update Listview
    this->aktionList.at(index) = newAktionGui.getAktion();
    item->setText( getListName( newAktionGui.getAktion()) );

}



void AktionMngr::on_pushButton_removeAktion_clicked()
{
    QListWidgetItem * currentItem = ui->listWidget_aktionen->currentItem();
    int index = ui->listWidget_aktionen->currentRow();

    if (currentItem == nullptr) {
        perror("Kein Eintrag ausgewählt!");
        return;
    } else
        currentItem = ui->listWidget_aktionen->takeItem( index );

    if (currentItem == nullptr) {
        perror("Konnte Eintrag nicht aus der Liste entfernen!");
        return;
    } else
        delete currentItem;

    if(index < 0 || index >= static_cast<int>(this->aktionList.size()) ) {
        std::cout << "Error: Invalid User Data" << std::endl;
        return;
    } else
    //remove aktion from vector
        this->aktionList.erase( this->aktionList.begin() + index);
}


const QString AktionMngr::getName()
{
    return ((ui->lineEdit_name->text() == "") ? "Aktion Namenlos" : ui->lineEdit_name->text());
}


void AktionMngr::loadInitData(const AKTIONMNGR_DATA &initD)
{
    //Clear lists
    this->aktionList.clear();
    this->ui->listWidget_aktionen->clear();

    //reset input Fields
    this->id = initD.id;
    this->ui->lineEdit_name->setText( initD.getString(AKTIONMNGR_DATA::NAME) );
    this->ui->spinBox_anzahl_ausfuehrungen->setValue(initD.anzahl_ausfuehrungen);
    this->ui->spinBox_aktualisierungsrate->setValue( initD.aktualisierungsrate );
    if( ! initD.enabled )
        mThread->disable();
    this->ui->comboBoxBed1->setCurrentIndex( initD.indexBed1 );
    this->ui->comboBox_Bed2->setCurrentIndex( initD.indexBed2 );
    this->ui->comboBox_Bed_3->setCurrentIndex( initD.indexBed3 );
    this->ui->lineEdit_BedInput->setText( initD.getString(AKTIONMNGR_DATA::BEDINGUNG_INPUT_TEXT, true) );

    //re fill lists
    for( unsigned i = 0; i < initD.aktionList.size() ; i++ ) {

        //create new item
        QListWidgetItem * newLWI = new QListWidgetItem( getListName( initD.aktionList.at(i) ) );
        this->ui->listWidget_aktionen->addItem(newLWI);

        //
        int index = ui->listWidget_aktionen->row(newLWI);
        if( index > (int)aktionList.size() ) {
            std::cerr << "Kann neue Aktion nicht in Listen einfügen, Zu einfügende Stelle ist größer als Listen!" << std::endl;
            ui->listWidget_aktionen->removeItemWidget( newLWI ); // remove + delete
            continue;;
        } else
            //add item to list
            this->aktionList.insert(aktionList.begin() + index, initD.aktionList.at(i));
    }

}

AKTIONMNGR_DATA AktionMngr::getInitData()
{
    return AKTIONMNGR_DATA(this->aktionList, this->ui->lineEdit_name->text(),
                           ui->spinBox_anzahl_ausfuehrungen->value(), this->id, this->ui->spinBox_aktualisierungsrate->value(),  ! mThread->isDisabled(),
                           ui->comboBoxBed1->currentIndex(), ui->comboBox_Bed2->currentIndex(), ui->comboBox_Bed_3->currentIndex(), ui->lineEdit_BedInput->text()
                            );
}

QString AktionMngr::getListName(AKTION action)
{
    QString name;
    switch (action.type) {
    case AKTION::EMPTY:
        name = "[ -Auswählen- ]: "" Keine Aktion ausgewählt!";
        break;
    case AKTION::SLEEP:
        name = "[ Pause ]: " "Warte für " + QString::number( action.sleep.sleep_time_minuten ) + "m "
                                          + QString::number( action.sleep.sleep_time_sekunden ) + "s "
                                          + QString::number( action.sleep.sleep_time_m_sec ) + "ms";

        break;
    case AKTION::RUN_COMMAND:
        name =  "[ Führe Befehl aus ]: " "Befehl: \"" + action.runCommand.getCommand() + "\"";
        break;
    case AKTION::SHOW_MSG:
        name =  "[ Nachricht anzeigen ]: " "Nachricht: \"" + action.showMsg.getMsg() +  "\"";
        break;
    case AKTION::WINDOW_CHANCHE_POS:
        name =  "[ Fenster Bewegung ]: " "Bewege das Fenster \"" + action.moveWindow.getWindowName() + "\" ("+QString::number( action.moveWindow.nWidth )  + "x" + QString::number( action.moveWindow.nHeigth )
                +  ") nach ("
                + QString::number( action.moveWindow.newPosX ) + "|" + QString::number(action.moveWindow.newPosY ) + ")";
        break;
    case AKTION::WINDOW_CHANCHE_VISIBILITY:
        name =  "[ Fenster Sichtbarkeit verändern ]: " "Mache das Fenster " + QString(action.changeWVisibility.state == action.changeWVisibility.VISIBLE ? "sichtbar" : "unsichtbar" );
        break;
    case AKTION::RECHECK_CONDITION:
        name =  "[ Wiederhohle Bedingungscheck ]: " + QString( action.reCheckCondition.effekt == action.reCheckCondition.SKIP_NEXT_AKTION ? "Wenn erfüllt, überspringe nächste Aktion"
                                              :   ( action.reCheckCondition.effekt == action.reCheckCondition.STOP_PROGRAMM ? "Wenn erfüllt, beende das Programm"
                                              : "Wenn erfüllt, brich die Sequenz ab"  )   );
        break;
    case AKTION::EDIT_VAR:
        name =  "[ Lege Variablenwert fest ]: Speichere in "  + QString( action.editVar.getName() ) + ": [" + action.editVar.getNewValue() + "]"  ;
        break;
    default:
        name =  "[ Unbekannte Aktion ]: " "ID: " + QString::number(action.type);
        break;
    }
    return name;
}



AktionExecuterThread::AktionExecuterThread(AktionMngr *parent, PiManager * piMngr)
    : QThread(parent),  waitugoon(false),isdisabled(false), aktionMngr(parent)
{
    winMngr = new WindowManager();
    this->piMngr = piMngr;
}

AktionExecuterThread::~AktionExecuterThread()
{
    this->QThread::requestInterruption();
    //stop thread
    this->quit();
    if( ! this->wait(200) ) {
        this->terminate();
        if( ! this->wait(200) ) {
            perror("Stop QThread failed!");
        }
    }

    delete  winMngr;
    perror("~AktionExecuterThread");
}

void AktionExecuterThread::waitUGoOn()
{
    //wenn man alte einstellungen wiederherstellt, dann solte thread warten
    waitugoon = true;
}

void AktionExecuterThread::goOn()
{
    waitugoon = false;
}

void AktionExecuterThread::disable()
{
    this->isdisabled = true;
}

void AktionExecuterThread::enable()
{
    this->isdisabled = false;
}

bool AktionExecuterThread::isDisabled() const
{
    return this->isdisabled;
}

bool AktionExecuterThread::startSequenz()
{
    //ALLES ÄNDERN ZU 1 NER BOX!!!!
    QString bt1 = aktionMngr->ui->comboBoxBed1->currentText(),
            bt2 = aktionMngr->ui->comboBox_Bed2->currentText(),
            bt3 = aktionMngr->ui->comboBox_Bed_3->currentText();

    if( aktionMngr->ui->comboBoxBed1->currentIndex() == 0 )
        return false;

    else if( bt1 == "Bedingung immer erfüllt")
        return true;
    else if ( bt1 == "Error"  ) {
        if( ( bt2 == "ist/sind" && bt3 == "verbundener Pi") ||  (bt2 == "ist/sind nicht" && bt3 == "verbundener Pi") ) {

        }
         if( piMngr->isConnected() && ( bt2 == "ist/sind" && bt3 == "verbundener Pi") ) {
             return true;
         }
         if(  ! piMngr->isConnected() && ( bt2 == "ist/sind nicht" && bt3 == "verbundener Pi") ) {
             return true;
         }


    } else if ( bt1 == "Mausposition" ) {

        auto l = aktionMngr->ui->lineEdit_BedInput->text().split(',');
        auto pos = winMngr->getGlobalMousePos();
        if(l.size() != 2)
            return false; // qmessage box errror && deaktivate aktion

        int x = l.at(0).toInt();
        int y = l.at(1).toInt();

        if(bt2 == "ist/sind kleiner" && pos.x() < x && pos.y() < y )
            return true ;
        else if( bt2 == "ist/sind größer" && pos.x() > x && pos.y() > y  )
            return true;

    } else if ( bt1 == "Tür" ) {
        bool tuersollOffenSein;
        if( (bt2 == "ist/sind" && bt3 == "offen") ||  (bt2 == "ist/sind nicht" && bt3 == "geschlossen") )
            tuersollOffenSein = true;
        else
            tuersollOffenSein = false;

        int status = piMngr->getSensorState( piMngr->DOR_STATE );
        if( status == -1) {
            //perror(" ERROR: KONNTE KEINEN TÜR-WERT VOM PI ENTFANGEN!!");
            return false;
        }

        if( status != tuersollOffenSein )
            return true;


    } else if( bt1 == "Variable") {
        if( aktionMngr->getgVarListCopy()[ aktionMngr->ui->lineEdit_bedinungsinput_anfang->text() ] == aktionMngr->ui->lineEdit_BedInput->text() )
            return true;



    }

    return false;
}





void AktionExecuterThread::run()
{
    int execCount = 0;
    auto & ui = aktionMngr->ui;
    bool break_var = false;

    while ( ! this->isInterruptionRequested() ) {
        usleep ( aktionMngr->ui->spinBox_aktualisierungsrate->value() * 1000 );

    //    if( ! aktionMngr->isHidden() )
    //        this->waitUGoOn();
        if( this->waitugoon || this->isdisabled )
            continue;
        if( !startSequenz() ) { // check if start coindition is true
            execCount = 0;
            continue;
        }
        if( (ui->spinBox_anzahl_ausfuehrungen->value() != 0) && execCount >= ui->spinBox_anzahl_ausfuehrungen->value()) {
            std::cout << " Maximal ausführungen erreicht " << std::endl;
            this->waitUGoOn();
            execCount = 0;
            continue;
        }
        else
            execCount++;

        for ( auto &a : aktionMngr->aktionList ) {
             if( this->waitugoon || this->isdisabled )
                break;

             //EXECUTE AKTION....
             switch (a.type) {
             case AKTION::SLEEP:
             {
                 std::cout << "SLEEP..." << std::endl;
                 sleep( a.sleep.sleep_time_minuten * 60 );
                 sleep( a.sleep.sleep_time_sekunden );
                 usleep( a.sleep.sleep_time_m_sec * 1000 );
                 break;
             }
             case AKTION::WINDOW_CHANCHE_POS:
             {
                 std::cout << "move..." << std::endl;
                 winMngr->moveWindow( a.moveWindow );
                 break;

             }
             case AKTION::WINDOW_CHANCHE_VISIBILITY:
             {
                 std::cout << "make (in)visible a window..." << std::endl;
                 winMngr->changeWindowVisibility( a.changeWVisibility );
                 break;

             }
             case AKTION::RECHECK_CONDITION :
             {
                 std::cout << "RECHECK_CONDITION..." << std::endl;
                 if( ! startSequenz() )
                     break_var = true;
                 break;

             }
             case AKTION::EDIT_VAR :
             {
                 std::cout << "editVar..." << a.editVar.newValue.toStdString()  <<  " --- " <<  aktionMngr->replaceVars( a.editVar.newValue ).toStdString() << std::endl;
                 emit aktionMngr->wantchangeVarValue( a.editVar.name, aktionMngr->replaceVars( a.editVar.newValue )  );
                 //if(a.editVar.name != "")
                 //   aktionMngr->gVarsPrivate->insert( a.editVar.name, aktionMngr->replaceVars( a.editVar.newValue ) );
                 break;

             }
             case AKTION::SHOW_MSG :
             {
                 std::cout << "showMsg...: " << a.showMsg.getMsg().toStdString() << std::endl;
                 emit aktionMngr->wandCreateMsgBox(MSG_TYPE::information,  aktionMngr->replaceVars( AKTION::getString(a.showMsg.title) ),  aktionMngr->replaceVars( a.showMsg.getMsg() ) );
                 break;
             }
             case AKTION::SOUND_MUTE :
             {
                 std::cout << winMngr->getCurrenSoundVolume() << std::endl;
                 break;
             }
             case AKTION::TYPE::EMPTY :
             {
                 break;
             }
             case AKTION::TYPE::RUN_COMMAND :
             {
                QString retVal = winMngr->runCommand(this,  aktionMngr->replaceVars( a.runCommand.getCommand() ) );
                std::cout << "GOT: " << retVal.toStdString() << std::endl;
                if(a.runCommand.saveVar) {
                    //if(a.editVar.name != "")
                    //   aktionMngr->gVarsPrivate->insert( a.editVar.name, aktionMngr->replaceVars( a.editVar.newValue ) );
                    emit aktionMngr->wantchangeVarValue( AKTION::getString(a.runCommand.saveInVarName), retVal  );
                }
                break;
             }
             case AKTION::TYPE::GLOBAL_VAR :
             {
                 //ERROR EIGENTLICH                 //speichere trotzdem Wert
                 emit aktionMngr->wantchangeVarValue( a.globalVar.getName(), aktionMngr->replaceVars( a.globalVar.getValue() )  );
                 break;
             }
//             case AKTION:: :
//             {
//                 break;
//             }
//             case AKTION:: :
//             {

//                 break;
//             }
             default:
             {
                 //UNKNOWN TYPE -> SKIP
                 break;
             }
             } // SWITCH

             if(break_var)
                 break;
        } //AKTION LIST LOOP


    }//Thread while true loop
}







void AktionMngr::on_comboBoxBed1_currentTextChanged(const QString &arg1)
{

}


void AktionMngr::on_comboBox_Bed2_currentTextChanged(const QString &arg1)
{

}


void AktionMngr::on_comboBox_Bed_3_currentTextChanged(const QString &arg1)
{

}

#include <iostream>


QString AktionMngr::replaceVars(QString s)
{
    int p1 = 0, p2 = 0;
    QString var;

    for(p1 = s.indexOf( "%" ); p1 != -1; p1 = s.indexOf( "%", p2 +1 )) {
        if( (  p2 =  s.indexOf( "%", p1 + 1 ) ) == -1 )
            break;
        else if ( (var = s.mid(p1 + 1, p2 - p1 - 1 )) == "" )
            continue;
        else if( getgVarListCopy().contains( var )  )
            s.replace( "%" + var + "%",  getgVarListCopy()[var] );
        else {
            //UNKNOWN VAR!
        }
    }
    return s;
}

const QMap<QString, QString> &AktionMngr::getgVarListCopy() const
{
    return *gVarsPrivate;
}

