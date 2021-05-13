#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storgMngr = new StorageMngr( /*QDir::currentPath()*/ QDir::homePath() + "/settings");
    piMngr = new PiManager(/*"raspberrypi"*/"10.40.8.114", 2000);
    if( piMngr->connect() == 0)
        ui->pushButton->setDisabled(true);

    QList<AKTIONMNGR_DATA> aML = storgMngr->getInitDataList();
    for( const auto &aM : aML) {
        if( aM.id == "") {
            std::cout << "Überrpringen ungültigen Eintrag" << std::endl;
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

        //Start thread
        newAktionMngr->mThread->start();
    }


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

    if( aktionMngrList.at(index)->QDialog::exec() == 0 /* == abgelehnt */ ) {
        QString now = storgMngr->aktionMngrDataToQString( aktionMngrList.at(index)->getInitData() );
        QString old =  storgMngr->getInitDataString( aktionMngrList.at(index)->id );
        if(now == old) { // wenn nichts verändert wurde
            return;
        } else if( QMessageBox::question(this, "Nicht speichern?", "Möchten sie die Änderungen verwerfen?") != QMessageBox::StandardButton::No ) {
            //restore old settings...
            aktionMngrList.at(index)->loadInitData( storgMngr->getInitData( aktionMngrList.at(index)->id ) );
            item->setText(aktionMngrList.at(index)->getName()); // teoretisch unnötig, aber gute debug mglkeit
            return;
        }

    }

    //update name
    item->setText(aktionMngrList.at(index)->getName());

    //Save new settings
    storgMngr->reStoreAll(this->getAktMngrDataList());

    //go on with thread (stoped with setVisible())
    this->aktionMngrList.at(index)->mThread->goOn();
}


void MainWindow::on_pushButton_moveUp_clicked()
{
    int row;
    if(ui->listWidget->selectedItems().size() <= 0) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!");
        return;
    } else if( (row = ui->listWidget->currentRow() ) <= 0 ) {
        ui->statusbar->showMessage("Bereits ganz oben!");
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
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!");
        return;
    } else if( (row = ui->listWidget->currentRow() ) >= (ui->listWidget->count() - 1) ) {
        ui->statusbar->showMessage("Bereits ganz unten!");
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
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!");
        return;
    } else
        currentItem = ui->listWidget->takeItem( index );

    if (currentItem == nullptr) {
        ui->statusbar->showMessage("Konnte Eintrag nicht aus der Liste entfernen!");
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

    //Start thread
    newAktionMngr->mThread->start();

    this->ui->pushButton_add_aktionMngr->setDisabled(false);
}

void MainWindow::on_pushButton_enable_clicked()
{
    if(ui->listWidget->selectedItems().size() <= 0) {
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!");
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
        ui->statusbar->showMessage("Kein Eintrag ausgewählt!");
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
    if( piMngr->connect() == 0)
        ui->pushButton->setDisabled(true);

}
