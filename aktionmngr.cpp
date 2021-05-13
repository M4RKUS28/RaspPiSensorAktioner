#include "aktionmngr.h"
#include "ui_aktionmngr.h"


AktionMngr::AktionMngr(QWidget *parent, PiManager *piMngr, QString id)
    :  QDialog(parent),  ui(new Ui::AktionMngr)
{
    ui->setupUi(this);
    mThread = new AktionExecuterThread(this, piMngr);

    this->id = id;
}

AktionMngr::AktionMngr(QWidget *parent, PiManager *piMngr, const AKTIONMNGR_DATA &initData)
    :  QDialog(parent),   ui(new Ui::AktionMngr)
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
    //create  gui witch empty aktion
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
                                          + QString::number( action.sleep.sleep_time_sekunden ) + "s";
        break;
    case AKTION::RUN_COMMAND:
        name =  "[ Führe Befehl aus ]: " "Befehl: '" + action.runCommand.getCommand() + "'";
        break;
    case AKTION::SHOW_MSG:
        name =  "[ Nachricht anzeigen ]: " "Nachricht: '"   "'";
        break;
    case AKTION::WINDOW_CHANCHE_POS:
        name =  "[ Fenster Bewegung ]: " "Bewege das Fenster '"    "' nach ";
        break;
    case AKTION::WINDOW_CHANCHE_VISIBILITY:
        name =  "[ Fenster Sichtbarkeit verändern ]: " "Mache das Fenster '"    "' un/sichtbar ";
        break;
    case AKTION::RECHECK_CONDITION:
        name =  "[ Wiederhohle Bedingungscheck ]: " "Bedingung xyz";
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
    if( aktionMngr->ui->comboBoxBed1->currentIndex() == 0 )
        return false;
    else if( aktionMngr->ui->comboBoxBed1->currentText() == "Bedingung immer erfüllt")
        return true;
    else if ( aktionMngr->ui->comboBoxBed1->currentText() == "Error"  ) {
        if( ( aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind" && aktionMngr->ui->comboBox_Bed_3->currentText() == "verbundener Pi")
            ||  (aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind nicht" && aktionMngr->ui->comboBox_Bed_3->currentText() == "verbundener Pi") ) {

        }
         if( piMngr->isConnected() && ( aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind" && aktionMngr->ui->comboBox_Bed_3->currentText() == "verbundener Pi") ) {
             return true;
         }
         if(  ! piMngr->isConnected() && ( aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind nicht" && aktionMngr->ui->comboBox_Bed_3->currentText() == "verbundener Pi") ) {
             return true;
         }


    } else if ( aktionMngr->ui->comboBoxBed1->currentText() == "Mausposition" ) {

        auto l = aktionMngr->ui->lineEdit_BedInput->text().split(',');
        auto pos = winMngr->getGlobalMousePos();
        if(l.size() != 2)
            return false; // qmessage box errror && deaktivate aktion

        int x = l.at(0).toInt();
        int y = l.at(1).toInt();

        if(aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind kleiner" && pos.x() < x && pos.y() < y )
            return true ;
        else if( aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind größer" && pos.x() > x && pos.y() > y  )
            return true;

    } else if ( aktionMngr->ui->comboBoxBed1->currentText() == "Tür" ) {
        bool tuersollOffenSein;
        if( (aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind" && aktionMngr->ui->comboBox_Bed_3->currentText() == "offen")
            ||  (aktionMngr->ui->comboBox_Bed2->currentText() == "ist/sind nicht" && aktionMngr->ui->comboBox_Bed_3->currentText() == "geschlossen") )
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


    }
    return false;
}


#include <QMessageBox>

void AktionExecuterThread::run()
{
    int execCount = 0;
    auto & ui = aktionMngr->ui;

    while ( ! this->isInterruptionRequested() ) {
        usleep ( aktionMngr->ui->spinBox_aktualisierungsrate->value() * 1000 );

        if( ! aktionMngr->isHidden() )
            this->waitUGoOn();
        if( this->waitugoon || this->isdisabled )
            continue;
        if( !startSequenz() ) { // check if start coindition is true
            execCount = 0;
            continue;
        }
        if( (ui->spinBox_anzahl_ausfuehrungen->value() != 0) && execCount >= ui->spinBox_anzahl_ausfuehrungen->value()) {
            //std::cout << " Maximal ausführungen erreicht " << std::endl;
            continue;
        }
        else
            execCount++;

        for ( auto &action : aktionMngr->aktionList ) {


             if(action.type == action.SLEEP) {
                std::cout << "SLEEP..." << std::endl;
                sleep( action.sleep.sleep_time_minuten * 60 );
                sleep( action.sleep.sleep_time_sekunden );

            } else if( action.type == action.WINDOW_CHANCHE_POS ) {
                 winMngr->moveWindow( action.moveWindow );
                std::cout << "MOVED" << std::endl;

            } else if ( action.type == action.WINDOW_CHANCHE_VISIBILITY ) {
                std::cout << "make (in)visible a window..." << std::endl;
                winMngr->changeWindowVisibility( action.changeWVisibility );


            } else if ( action.type == action.RECHECK_CONDITION ) {
                std::cout << "RECHECK_CONDITION..." << std::endl;
                if( ! startSequenz() ) {
                    break;
                }


            } else if ( action.type == action.SHOW_MSG ) {
                std::cout << "showMsg...: " << action.showMsg.getMsg().toStdString() << std::endl;

            }



        }


    }
}





void AktionMngr::on_label_5_linkHovered(const QString &link)
{

}
