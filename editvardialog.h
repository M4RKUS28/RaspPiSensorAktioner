#ifndef EDITVARDIALOG_H
#define EDITVARDIALOG_H

#include <QDialog>

namespace Ui {
class EditVarDialog;
}

class EditVarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditVarDialog(QWidget *parent = nullptr);
    void setVar(QString name, QString value);

    ~EditVarDialog();

    QString getName() const;
    QString getValue() const;

private:
    Ui::EditVarDialog *ui;
};

#endif // EDITVARDIALOG_H
