#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aktionmngr.h"
#include "storagemngr.h"
#include "pimanager.h"
#include "vareditor.h"


#include <QMessageBox>
#include <QSettings>
#include <QInputDialog>
#include <QFileDialog>


#define defaultPiAddrIp "raspberrypi"
#define defaultPiAddrPort 2000
#define defaultPiAddr ( QString(defaultPiAddrIp) + QString(":") + QString::number(defaultPiAddrPort) )


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int initList( QList<AKTIONMNGR_DATA> &list );

    std::vector<AktionMngr *> aktionMngrList;
    StorageMngr * storgMngr;
    PiManager *piMngr;


    AKTIONMNGR_DATA mainData;
    QMap<QString, QString> * globVars;

    QList<AKTIONMNGR_DATA> getAktMngrDataList();

private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_moveUp_clicked();

    void on_pushButton_moveDown_clicked();

    void on_pushButton_removeAktionMngr_clicked();

    void on_pushButton_add_aktionMngr_clicked();

    void on_pushButton_enable_clicked();

    void on_pushButton_disable_clicked();

    void on_pushButton_clicked();


    void createMessageBox(int type, QString title, QString msg);
    void changeVarValue(QString name, QString value);

    void createMessageBoxError(QString msg);
    void createMessageBoxWarning(QString msg);



    void on_pushButton_import_clicked();

    void on_pushButton_export_clicked();

    void on_actionAktivieren_checkableChanged(bool checkable);

    void on_actionDeaktivieren_triggered();

    void on_actionAktivieren_triggered();

    void on_actionNeue_Addresse_festlegen_triggered();

    void on_actionAnzeigen_triggered();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
