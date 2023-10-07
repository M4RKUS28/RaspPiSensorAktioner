#include "vareditor.h"
#include "ui_vareditor.h"
#include <iostream>


varEditor::varEditor(QMap<QString, QString> vars,QWidget *parent) :
    QDialog(parent),
    vars(vars),
    ui(new Ui::varEditor)
{
    ui->setupUi(this);

    //fill widget with existing vars

    QMapIterator<QString, QString> i(vars);
    while (i.hasNext()) {
        i.next();
        this->ui->listWidget->addItem( getItemName( i.key(),  i.value()  ));
    }


}



varEditor::~varEditor()
{
    delete ui;
}

void varEditor::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString varName = getNameByItem(item);
    EditVarDialog newVarEditGui(this);
    newVarEditGui.setWindowModality(Qt::WindowModality::ApplicationModal );


    if( ! vars.contains(varName) ) {
        this->ui->listWidget->removeItemWidget( item );
        return;
    }

    newVarEditGui.setVar( varName, vars[varName] );

    newVarEditGui.show();
    //wait for click finish
    if( newVarEditGui.QDialog::exec() == 0 /* == abgelehnt */ ) {    // accpet ==> automtic hide
        return;
    }

    vars[ varName ] =  newVarEditGui.getValue() ;
    item->setText( getItemName( varName, newVarEditGui.getValue() )  );

}


void varEditor::on_pushButton_add_clicked()
{
    EditVarDialog newVarEditGui(this);
    newVarEditGui.show();
    //wait for click finish
    if( newVarEditGui.QDialog::exec() == 0 /* == abgelehnt */ ) {    // accpet ==> automtic hide
        return;
    }

    if(newVarEditGui.getName() == "" || vars.contains( newVarEditGui.getName() ))
        return;

    vars.insert( newVarEditGui.getName(), newVarEditGui.getValue() );
    this->ui->listWidget->addItem( getItemName(newVarEditGui.getName(), newVarEditGui.getValue() ) );

}


void varEditor::on_pushButton_remove_clicked()
{
    QListWidgetItem * currentItem = ui->listWidget->currentItem();
    int index = ui->listWidget->currentRow();

    if (currentItem == nullptr || index < 0 || index > ui->listWidget->count() ) {
        return;
    } else
        currentItem = ui->listWidget->takeItem( index );

    if (currentItem != nullptr) {
        vars.remove( getNameByItem( currentItem ) );
        delete currentItem;
    }


}

QString varEditor::getItemName(QString name, QString value)
{
    return QString(name  + "\t\t\t[" + value  + "]" );
}



QString varEditor::getNameByItem(QListWidgetItem *item)
{
    return (item->text()).left( QString(item->text()).indexOf("\t\t\t") );
}

