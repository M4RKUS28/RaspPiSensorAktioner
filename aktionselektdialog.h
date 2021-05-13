#ifndef AKTIONSELEKTDIALOG_H
#define AKTIONSELEKTDIALOG_H


#include "mytypes.h"


namespace Ui {
class AktionSelektDialog;
}

class AktionSelektDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AktionSelektDialog(QWidget *parent = nullptr, AKTION initData = AKTION());
    ~AktionSelektDialog();

    Ui::AktionSelektDialog * ui;

    AKTION getAktion();
    void loadAktion( const AKTION &aktion );


private slots:

    void on_comboBox_select_Aktion_currentIndexChanged(int index);

    void on_radioButton_fenster_verschieben_clicked();

    void on_radioButton_aktiviereVollbild_clicked();

private:

};

#endif // AKTIONSELEKTDIALOG_H
