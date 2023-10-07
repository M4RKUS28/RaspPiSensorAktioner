#ifndef AKTIONMNGR_H
#define AKTIONMNGR_H


#include "aktionselektdialog.h"
#include "mytypes.h"
#include "windowmanager.h"

#include <QString>


class AktionExecuterThread;


namespace Ui {
class AktionMngr;
}

enum MSG_TYPE {
    information,
    critical,
    warning
};

class AktionMngr : public QDialog
{
    Q_OBJECT

public:
    explicit AktionMngr(QWidget *parent, PiManager *piMngr, QString id, QMap<QString, QString> *gVars);
    explicit AktionMngr(QWidget *parent, PiManager *piMngr, const AKTIONMNGR_DATA &initData, QMap<QString, QString> *gVars);

    ~AktionMngr();

    const QString getName();
    //void removeCancelButton();

    AktionExecuterThread * mThread;
    QString id;


    Ui::AktionMngr *ui;
    std::vector<AKTION> aktionList;

    void loadInitData( const AKTIONMNGR_DATA &initD);
    AKTIONMNGR_DATA getInitData();

    QString getListName(AKTION action);

    QString replaceVars(QString s);

    const QMap<QString, QString> &getgVarListCopy() const;


    QMap<QString, QString> *gVarsPrivate;


signals:

    void wandCreateMsgBox(int type, QString title, QString msg);
    void wantchangeVarValue(QString name, QString value);




private slots:
    void on_pushButton_add_aktion_clicked();

    void on_listWidget_aktionen_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_removeAktion_clicked();

    void on_pushButton_moveUp_clicked();

    void on_pushButton_moveDown_clicked();



    void on_comboBoxBed1_currentTextChanged(const QString &arg1);

    void on_comboBox_Bed2_currentTextChanged(const QString &arg1);

    void on_comboBox_Bed_3_currentTextChanged(const QString &arg1);

private:


};


class AktionExecuterThread : public QThread
{
    Q_OBJECT
public:
    AktionExecuterThread(AktionMngr *parent, PiManager *piMngr);
    ~AktionExecuterThread();
    void waitUGoOn();
    void goOn();

    void disable();
    void enable();
    bool isDisabled() const;

private:
    void run();

    bool startSequenz();
    bool waitugoon, isdisabled;
    AktionMngr * aktionMngr;
    PiManager *piMngr;
    WindowManager * winMngr;

};



#endif // AKTIONMNGR_H
