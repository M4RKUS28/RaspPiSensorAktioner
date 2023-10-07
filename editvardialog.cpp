#include "editvardialog.h"
#include "ui_editvardialog.h"

EditVarDialog::EditVarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditVarDialog)
{
    ui->setupUi(this);
}

void EditVarDialog::setVar(QString name, QString value)
{
    ui->lineEdit_name->setText(name);
    ui->lineEdit_value->setText(value);
    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_name->setDisabled(true);
}

EditVarDialog::~EditVarDialog()
{
    delete ui;
}

QString EditVarDialog::getName() const
{
    return ui->lineEdit_name->text();
}

QString EditVarDialog::getValue() const
{
    return ui->lineEdit_value->text();

}
