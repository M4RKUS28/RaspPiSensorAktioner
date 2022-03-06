#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storgMngr = new StorageMngr( /*QDir::currentPath()*/ QDir::homePath() + "/settings.senacs");
    QList<AKTIONMNGR_DATA> aML = storgMngr->getInitDataList();


    //MAIN INIT: create entry for main Data if noone exists:
    bool mainINITExists = false;
    for( const auto &aM : qAsConst(aML))
        if(aM.id == "-1")
            mainINITExists = true;

    if(mainINITExists == false) {
        //Create Main INIT
        AKTIONMNGR_DATA md;
        md.id = "-1";

        //Default settings:
        md.setPiAddr("raspberrypi:2000");


        //save new version
        aML.push_front(md);
        storgMngr->reStoreAll(aML);
    }


    //load Sequenzes from File
    initList(aML);


    //INIT PI



    piMngr = new PiManager();
    on_pushButton_clicked(); // try connect


    //ui->listWidget->setStyleSheet("QListWidget { background: white; } QListWidget::item { background: #EFFFFF; border: 1px solid black; border-radius: 5px; margin: 2px; } QListWidget::item:selected { background: #66DFFF; }");
    /*

    this->ui->listWidget->setStyleSheet(

    "QListView::item {"
        "border: 1px solid #000;"
        "border-radius: 5px;"
        "margin: 2px;"
    "}"

    "QListView::item:selected {"
        "color: black;"
        "background-color: #DCDEF1;"
        "border: 1px solid #000;"
        "border-radius: 5px;"
        "border-style: solid;"


    "}"

    "QListView::item:selected:!active {"
        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                "stop: 0 #ABAFE5, stop: 1 #8588B2);"
    "}"

    "QListView::item:selected:active {"
        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                "stop: 0 #6a6ea9, stop: 1 #888dd9);"
    "}"

    "QListView::item:hover {"
        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                "stop: 0 cyan, stop: 1 green);"

    );
*/

}


int MainWindow::initList(QList<AKTIONMNGR_DATA> &aML)
{


    for( const auto &aM : qAsConst(aML)) {
        if( aM.id == "") {
            std::cout << "Überrpringen ungültigen Eintrag" << std::endl;
            continue;
        }

        if(aM.id == "-1") {
            //save mainData for later storage update
            this->mainData = aM;

            std::cout << "restore main data..: setText: " <<  aM.getPiAddr().toStdString() << std::endl;

            //INIT DATA FOR THIS THREAD
            ui->action127_0_0_1->setText( aM.getPiAddr() );

            continue;
        }


        AktionMngr * newAktionMngr = new AktionMngr(this, piMngr, aM);
        QListWidgetItem * newLWI = new QListWidgetItem( newAktionMngr->getName() );
        this->ui->listWidget->addItem(newLWI);
        if( ! aM.enabled ) {
            newLWI->setForeground(Qt::gray);
            newAktionMngr->mThread->disable(); // double but better alse if forgotten
        }

        //
        int index = ui->listWidget->row(newLWI);
        if( index > (int)aktionMngrList.size() ) {
            std::cerr << "Kann neue Aktion nicht in Listen einfügen, Zu einfügende Stelle ist größer als Listen!" << std::endl;
            ui->listWidget->removeItemWidget( newLWI ); // remove + delete
            delete newAktionMngr;
            continue;;
        } else
            //add item to list
            this->aktionMngrList.insert(aktionMngrList.begin() + index, newAktionMngr);

        //connect object
        connect(newAktionMngr, SIGNAL(wandCreateMsgBox(int,QString,QString)), this, SLOT(createMessageBox(int,QString,QString)));
        //Start thread
        newAktionMngr->mThread->start();
    }


}


MainWindow::~MainWindow()
{
    for ( auto e : aktionMngrList )
        if(e)
            delete e;

    delete ui;
    delete storgMngr;
    delete piMngr;

    perror("~MainWindow()");
}



QList<AKTIONMNGR_DATA> MainWindow::getAktMngrDataList()
{
    QList<AKTIONMNGR_DATA> l;
    l.push_front(mainData);

    for( unsigned i = 0; i < this->aktionMngrList.size(); i++)
        l.push_back(aktionMngrList.at(i)->getInitData());
    return l;
}





void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{    
    int index = ui->listWidget->row(item);
    if(index < 0 || index >= static_cast<int>(this->aktionMngrList.size()) ) {
        std::cout << "Error: Invalid User Data" << std::endl;
        return;
    }
    //make it visible for editing
    this->aktionMngrList.at(index)->show();

    //stop thread
    this->aktionMngrList.at(index)->mThread->waitUGoOn();


    if( aktionMngrList.at(index)->QDialog::exec() == 0 /* == abgelehnt */ ) {
        QString now = storgMngr->aktionMngrDataToQString( aktionMngrList.at(index)->getInitData() );
        QString old =  storgMngr->getInitDataString( aktionMngrList.at(index)->id );
        if(now == old) { // wenn nichts verändert wurde
            //go on with thread (stoped with setVisible() not anymore -> since update  in this funktion with waitGoOn)
            return this->aktionMngrList.at(index)->mThread->goOn();

        } else if( QMessageBox::question(this, "Nicht speichern?", "Möchten sie die Änderungen verwerfen?") != QMessageBox::StandardButton::No ) {
            //restore old settings...
            aktionMngrList.at(index)->loadInitData( storgMngr->getInitData( aktionMngrList.at(index)->id ) );
            item->setText(aktionMngrList.at(index)->getName()); // teoretisch unnötig, aber gute debug mglkeit

            //go on with thread (stoped with setVisible() not anymore -> since update  in this funktion with waitGoOn)
            return this->aktionMngrList.at(index)->mThread->goOn();
        }

    }

    //update name
    item->setText(aktionMngrList.at(index)->getName());

    //Save new settings
    storgMngr->reStoreAll(this->getAktMngrDataList());

    //go on with thread (stoped with setVisible() not anymore -> since update  in this funktion with waitGoOn)
    this->aktionMngrList.at(index)->mThread->goOn();
}


void MainWindow::on_pushButton_moveUp_clicked()
{
    int row;
    if(ui->listWidget->selectedItems().size() <= 0) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!", 1000);
        return;
    } else if( (row = ui->listWidget->currentRow() ) <= 0 ) {
        ui->statusbar->showMessage("Bereits ganz oben!", 1000);
        return; // wichtig sonst stürzt programm beu current item ab
    }
    //move current selected one up ( take from and insert)
    ui->listWidget->insertItem( row - 1,   ui->listWidget->takeItem( row ) );
    ui->listWidget->setCurrentRow( row - 1);

    //repos Vector
    iter_swap(aktionMngrList.begin() + row -1, aktionMngrList.begin() + row );

    //restroe all
    this->storgMngr->reStoreAll(this->getAktMngrDataList());
}

void MainWindow::on_pushButton_moveDown_clicked()
{
    int row;
    if(ui->listWidget->selectedItems().size() <= 0) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!", 1000);
        return;
    } else if( (row = ui->listWidget->currentRow() ) >= (ui->listWidget->count() - 1) ) {
        ui->statusbar->showMessage("Bereits ganz unten!", 1000);
        return;
    }
    //move current selected one up ( take from and insert)
    ui->listWidget->insertItem( row + 1,   ui->listWidget->takeItem( row ) );
    ui->listWidget->setCurrentRow( row + 1);

    //repüos vector
    iter_swap(aktionMngrList.begin() + row, aktionMngrList.begin() + row + 1 );

    //restroe all
    this->storgMngr->reStoreAll(this->getAktMngrDataList());
}



void MainWindow::on_pushButton_removeAktionMngr_clicked()
{
    this->ui->pushButton_removeAktionMngr->setDisabled(false);

    QListWidgetItem * currentItem = ui->listWidget->currentItem();
    int index = ui->listWidget->currentRow();

    if (currentItem == nullptr) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!", 1000);
        return;
    } else
        currentItem = ui->listWidget->takeItem( index );

    if (currentItem == nullptr) {
        ui->statusbar->showMessage("Konnte Eintrag nicht aus der Liste entfernen!", 1000);
        return;
    } else
        delete currentItem;

    if(index < 0 || index >= static_cast<int>(this->aktionMngrList.size()) ) {
        std::cout << "Error: Invalid User Data" << std::endl;
        return;
    }
    //remove aktion from vector
    auto pT = aktionMngrList.at(index);
    this->aktionMngrList.erase( this->aktionMngrList.begin() + index);
    //remove entry from storage
    //storgMngr->remove(pT->id);
    storgMngr->reStoreAll(this->getAktMngrDataList());

    this->ui->pushButton_removeAktionMngr->setDisabled(false);
    delete pT;
}

void MainWindow::on_pushButton_add_aktionMngr_clicked()
{
    // verhindern, dass es eine id 2 mal gibt, da  getNewId() nur funktioniert,
    //wenn das fenster mit der selben id berits abgespeichert wurde, bevor getNewID() aufgerufen wurde
    this->ui->pushButton_add_aktionMngr->setDisabled(true);

    AktionMngr * newAktionMngr = new AktionMngr(this, piMngr, storgMngr->getNewID() );

    newAktionMngr->show();
    if( newAktionMngr->QDialog::exec() == 0 /* == abgelehnt */ ) {
        delete  newAktionMngr;
        this->ui->pushButton_add_aktionMngr->setDisabled(false);
        return;
    }
    // accpet == automtic hide

    QListWidgetItem * newLWI = new QListWidgetItem( newAktionMngr->getName() );


    int index = ui->listWidget->currentRow() + 1;
    if( index > (int)aktionMngrList.size()) {
        std::cerr << "Kann neue Aktion nicht in Listen einfügen, Zu einfügende Stelle ist größer als Listen!" << std::endl;
        delete newLWI;
        this->ui->pushButton_add_aktionMngr->setDisabled(false);
        return;
    }
    //insert list Text item
    this->ui->listWidget->insertItem( index, newLWI);
    this->ui->listWidget->setCurrentItem(newLWI);

    //insert mngr in vector list
    this->aktionMngrList.insert(aktionMngrList.begin() + index, newAktionMngr);

    //save settings....
    storgMngr->reStoreAll(this->getAktMngrDataList());

    //connect object
    connect(newAktionMngr, SIGNAL(wandCreateMsgBox(int, QString, QString)), this, SLOT(createMessageBox(int, QString, QString)));

    //Start thread
    newAktionMngr->mThread->start();

    this->ui->pushButton_add_aktionMngr->setDisabled(false);
}

void MainWindow::on_pushButton_enable_clicked()
{
    if(ui->listWidget->selectedItems().size() <= 0) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!", 1000);
        return;
    }
    int index = ui->listWidget->currentRow();
    if(index < 0 || index >= static_cast<int>(this->aktionMngrList.size()) ) {
        std::cout << "Error: Invalid User Data" << std::endl;
        return;
    }
    QListWidgetItem * item = ui->listWidget->item(index);
    if(!item)
        return;
    else
        item->setForeground(Qt::black);

    aktionMngrList.at(index)->mThread->enable();
    storgMngr->reStoreAll( this->getAktMngrDataList() );
}

void MainWindow::on_pushButton_disable_clicked()
{
    if(ui->listWidget->selectedItems().size() <= 0) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!", 1000);
        return;
    }
    int index = ui->listWidget->currentRow();
    if(index < 0 || index >= static_cast<int>(this->aktionMngrList.size()) ) {
        std::cout << "Error: Invalid User Data" << std::endl;
        return;
    }
    QListWidgetItem * item = ui->listWidget->item(index);
    if(!item)
        return;
    else
        item->setForeground(Qt::gray);

    aktionMngrList.at(index)->mThread->disable();
    storgMngr->reStoreAll( this->getAktMngrDataList() );

}

void MainWindow::on_pushButton_clicked()
{

    int port = -1;
    std::string ip;
    auto d = mainData.getPiAddr().split(':');
    if (d.size() != 2 || ( ( port = d.at(1).toInt()) <= 0 || port > 65535 ) ) {
        ui->statusbar->showMessage("Ungültige Addresse für Pi!", 2000);
        ip = "raspberrypi";
        port = 2000;

        mainData.setPiAddr("raspberrypi:2000");
        this->ui->action127_0_0_1->setText("raspberrypi:2000");
        storgMngr->reStoreAll(this->getAktMngrDataList());


    }
    else {
        ip = d.at(0).toStdString();
    }

    if( piMngr->connect(ip, port) == 0) {
        ui->pushButton->setDisabled(true);
        ui->statusbar->showMessage("Verbunden!", 1000);

    } else
        ui->statusbar->showMessage("Verbindung fehlgeschlagen: " + piMngr->getLastErrorMsg() +" !", 2800);

}

void MainWindow::createMessageBox(int type, QString title, QString msg)
{
    if(type == MSG_TYPE::warning)
        QMessageBox::warning(this, title, msg);

    else if (type == MSG_TYPE::critical)
        QMessageBox::critical(this, title, msg);

    else // (type == MSG_TYPE::information )
        QMessageBox::information(this, title, msg);

}


void MainWindow::createMessageBoxError(QString msg)
{

}

void MainWindow::createMessageBoxWarning(QString msg)
{

}



void MainWindow::on_pushButton_import_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode( QFileDialog::ExistingFile );
    dialog.setNameFilter(tr("Settings Files (*.senacs)"));
    dialog.setWindowTitle("Wählen sie eine Einstellungsdatei aus");
    dialog.setDirectory(QDir::homePath());

    QStringList fileNames;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
        if(fileNames.size() > 0 && QFile(fileNames.at(0)).exists()) {
            StorageMngr tmpStorgMngr(fileNames.at(0));

            auto t = tmpStorgMngr.getInitDataList();
            for( int i = 0; i < t.size(); i++)
                if(t.at(i).id != "-1" )
                    t[i].id = QString::number( tmpStorgMngr.getNewID().toULongLong() + i );
                else {
                    //es existieren neue Main Window Einstellungen -> entferne ggf diese
                    if( QMessageBox::question(this, "Haupteinstellungen überschreiben?", "Möchten sie die Haupteinstellungen wie z.B. die Ip Addresse des Raspberry pi's aus der Datei importieren? Derzeitige Einstellungen werden dabei überschrieben!") != QMessageBox::StandardButton::Yes ) {
                        t.remove( i );
                    }
                }

            //füge einträge (inc. main einstellungen ) hinzu
            initList(t);

            //speichere die neuen einträge
            storgMngr->reStoreAll( this->getAktMngrDataList() );


        }
    }
}


void MainWindow::on_pushButton_export_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode( QFileDialog::Directory );
    dialog.setWindowTitle("Wählen sie den Export Ordner aus");
    dialog.setDirectory(QDir::homePath());

    QStringList fileNames;
    QString newFileName = "/Settings BackUP.senacs";
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();


        //wen eingabe ok war
        if(fileNames.size() > 0 && QDir(fileNames.at(0)).exists()) {

            //wenn datei existiert, fragen wegen löschen
            if( QFile(fileNames.at(0) + newFileName).exists() ) {
                if( QMessageBox::question(this, "Datei überschreiben?", "Es existiert bereits die Datei \"" + fileNames.at(0) + newFileName + ". Wollen sie diese überschreiben?" ) != QMessageBox::StandardButton::Yes ) {
                    return;
                } else {
                    QFile::remove( fileNames.at(0) + newFileName );
                }
            }

            //kopieren
            if( QFile::copy( storgMngr->filePath, fileNames.at(0) + newFileName  ) == false )
                ui->statusbar->showMessage("Exportieren der Datei \" + storgMngr->filePath + \" fehlgeschlagen!", 2000);
            else
                ui->statusbar->showMessage("Datei " + fileNames.at(0) + newFileName + " erfolgreich exportiert!", 2000);



        }
    }

}

#include <QFileInfo>
#include <QStandardPaths>


void MainWindow::on_actionAktivieren_checkableChanged(bool checkable)
{

}


void MainWindow::on_actionDeaktivieren_triggered()
{
    //QSettings bootUpSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    //bootUpSettings.remove("Sensor Aktioner");

    //billig version:
    QFile::remove( QString( QDir::homePath() + QString( "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/SensorAktioner.exe") )  );

}


void MainWindow::on_actionAktivieren_triggered()
{
   // QSettings bootUpSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
   // bootUpSettings.setValue("Sensor Aktioner",  QDir::toNativeSeparators(QCoreApplication::applicationFilePath()));
   // bootUpSettings.sync();
   // std::cout << "added" << std::endl;

    //billig version:
    QFile::copy( QCoreApplication::applicationFilePath(),
                 QString( QDir::homePath() + QString( "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/SensorAktioner.exe") )  );

}


void MainWindow::on_actionNeue_Addresse_festlegen_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Raspberry Pi Addresse festlegen"),
                                             tr("Neue Addresse:"), QLineEdit::Normal,
                                             ui->action127_0_0_1->text(), &ok);
    if (ok && !text.isEmpty()) {

        mainData.setPiAddr( text );
        this->ui->action127_0_0_1->setText( mainData.getPiAddr() );
        storgMngr->reStoreAll( this->getAktMngrDataList() );

    }

}

