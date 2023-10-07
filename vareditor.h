#ifndef VAREDITOR_H
#define VAREDITOR_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMap>

#include "editvardialog.h"

namespace Ui {
class varEditor;
}

class varEditor : public QDialog
{
    Q_OBJECT

public:
    explicit varEditor(QMap<QString,QString> vars, QWidget *parent = nullptr);
    ~varEditor();
    QMap<QString,QString> vars;


private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    QString getItemName(QString name, QString value);
    QString getNameByItem(QListWidgetItem * item);

private:
    Ui::varEditor *ui;
};

#endif // VAREDITOR_H
