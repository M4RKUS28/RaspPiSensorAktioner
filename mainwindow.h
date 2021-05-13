#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aktionmngr.h"
#include "storagemngr.h"
#include "pimanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::vector<AktionMngr *> aktionMngrList;
    StorageMngr * storgMngr;
    PiManager *piMngr;

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
