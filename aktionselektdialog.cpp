#include "aktionselektdialog.h"
#include "ui_aktionselektdialog.h"


AktionSelektDialog::AktionSelektDialog(QWidget *parent, AKTION initData) :
    QDialog(parent),
    ui(new Ui::AktionSelektDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled( true );

    ui->spinBox_Bildschirm->setMaximum( QApplication::screens().count() );
    ui->radioButton_aktiviereVollbild->click();


    if(initData.type != initData.EMPTY)
        loadAktion(initData);
}


AktionSelektDialog::~AktionSelektDialog()
{
    perror("~AktionSelektDialog");
    delete ui;
}

AKTION AktionSelektDialog::getAktion()
{
    enum AKTION::TYPE type = AKTION::TYPE( ui->comboBox_select_Aktion->currentIndex() );
    struct AKTION::Sleep sleep(ui->spinBox_sleep_time_m_sec->value(), ui->spinBox_sleep_time_sekunden->value(), ui->spinBox_sleep_time_minuten->value());
    struct AKTION::RunCommand runCommand( ui->lineEdit_command->text(), this->ui->lineEdit_RUNCOMMANDVARNAME->text(), ui->radioButton_saveRUNCOMMOUTPUT->isChecked() );
    struct AKTION::ShowMsg s( this->ui->lineEdit_sendMessage_messag->text() );
    struct AKTION::ChangeWindowVisibility cwv(this->ui->lineEdit_chacnhe_visibility_window_name->text(),
                                 AKTION::WINDOW_NAME_PARITY( ui->comboBox_change_vbty_parity->currentIndex()  ),
                                ( ui->radioButton_change_vbty_hide_button->isChecked() ? AKTION::ChangeWindowVisibility::STATE::HIDDEN : AKTION::ChangeWindowVisibility::STATE::VISIBLE)  );
    struct AKTION::SoundMute sm;  //( (ui->radioButton_mute_system_mute_rad_button ? AKTION::SoundMute::STATE::MUTE : AKTION::SoundMute::STATE::UNMUTE) );

    AKTION::ReCheckCondition::EFFEKT ef;
    if(ui->radioButton_recheck_con_stop_seq->isChecked())
        ef = AKTION::ReCheckCondition::EFFEKT::STOP_SEQUENZ;
    else if(ui->radioButton_recheck_con_skip_next_aktion->isChecked())
        ef = AKTION::ReCheckCondition::EFFEKT::SKIP_NEXT_AKTION;
    else
        ef = AKTION::ReCheckCondition::EFFEKT::STOP_PROGRAMM;
    struct AKTION::ReCheckCondition rcc( ef );

    struct AKTION::MoveWindow mw( ui->lineEdit_move_window_window_name->text(), ui->spinBox_movewindow_pos_X->value(), ui->spinBox_move_window_pos_Y->value() ,
                                  ui->spinBox_new_size_width->value(), ui->spinBox_new_size_height->value(), ui->spinBox_Bildschirm->value(), ui->radioButton_aktiviereVollbild->isChecked(),
                                  ui->radioButton_absoltutePosX->isChecked(), ui->radioButton_absoltutePosY->isChecked(),
                                  ui->radioButton_absolute_size_width->isChecked(), ui->radioButton_absolute_size_heigth->isChecked(),
                                  ( AKTION::WINDOW_NAME_PARITY( ui->comboBox_move_window_window_parity->currentIndex()  ) ) );

    struct AKTION::EditVar eV( ui->lineEdit_10_varName->text(), this->ui->lineEdit_10_newValue->text() );

    return AKTION( type, sleep, runCommand, s, cwv, sm, rcc, mw, eV );
}

void AktionSelektDialog::loadAktion(const AKTION &aktion)
{
    ui->comboBox_select_Aktion->setCurrentIndex( aktion.type );

    /*-AUSWÄHLEN- 0 == */


    //SLEEP
        ui->spinBox_sleep_time_sekunden->setValue( aktion.sleep.sleep_time_sekunden );
        ui->spinBox_sleep_time_minuten->setValue( aktion.sleep.sleep_time_minuten );
        ui->spinBox_sleep_time_m_sec->setValue( aktion.sleep.sleep_time_m_sec );

    //case AKTION::RUN_COMMAND:
        ui->lineEdit_command->setText( aktion.runCommand.getCommand() );
        ui->lineEdit_RUNCOMMANDVARNAME->setText( AKTION::getString( aktion.runCommand.saveInVarName ) );
        if(aktion.runCommand.saveVar)
            ui->radioButton_saveRUNCOMMOUTPUT->click();



    //    case AKTION::SHOW_MSG:
        ui->lineEdit_sendMessage_messag->setText(aktion.showMsg.getMsg());

    //    case AKTION::WINDOW_AKTION_ Visibility:
        ui->lineEdit_chacnhe_visibility_window_name->setText( aktion.changeWVisibility.getWindowName() );
        ui->comboBox_change_vbty_parity->setCurrentIndex( aktion.changeWVisibility.wNameParity );
        if(aktion.changeWVisibility.state == aktion.changeWVisibility.HIDDEN)
            ui->radioButton_change_vbty_hide_button->click();
        else
            ui->radioButton_change_vbty_show_button->click();


    //mute sound
        /*
        if(aktion.soundMute.state == aktion.soundMute.MUTE)
            ui->radioButton_mute_system_mute_rad_button->click();
        else
            ui->radioButton_mute_system_unmute_rad_button->click();*/

        // recheck condfition

        if(aktion.reCheckCondition.effekt == aktion.reCheckCondition.STOP_SEQUENZ)
            ui->radioButton_recheck_con_stop_seq->click();
        else if( aktion.reCheckCondition.effekt == aktion.reCheckCondition.SKIP_NEXT_AKTION )
            ui->radioButton_recheck_con_skip_next_aktion->click();
        else
            ui->radioButton_recheck_stop_programm->click();

//move window
        ui->lineEdit_move_window_window_name->setText( aktion.moveWindow.getWindowName() );
        std::cout << "         ui->comboBox_move_window_window_parity->setCurrentIndex " <<  aktion.moveWindow.wNameParity << std::endl;

        ui->comboBox_move_window_window_parity->setCurrentIndex( aktion.moveWindow.wNameParity );
        ui->spinBox_movewindow_pos_X ->setValue( aktion.moveWindow.newPosX );
        ui->spinBox_move_window_pos_Y ->setValue( aktion.moveWindow.newPosY );
        ui->spinBox_new_size_height ->setValue( aktion.moveWindow.nHeigth );
        ui->spinBox_new_size_width ->setValue( aktion.moveWindow.nWidth );

        ui->spinBox_Bildschirm ->setValue( aktion.moveWindow.fullScreenWindowScreen );

        // Radio buttons,

        ui->radioButton_fenster_verschieben->click(); // enable radio buttons
        // pos x
        if(aktion.moveWindow.useAbsolutePosX)
            ui->radioButton_absoltutePosX->click();
        else
            ui->radioButton_relativ_posX->click();
        //pos y
        if(aktion.moveWindow.useAbsolutePosY)
            ui->radioButton_absoltutePosY->click();
        else
            ui->radioButton_relativ_posY->click();
        //size width
        if(aktion.moveWindow.useAbsoluteHeight)
            ui->radioButton_absolute_size_heigth->click();
        else
            ui->radioButton_relative_size_heigth->click();
        //size heigth
        if(aktion.moveWindow.useAbsoluteWidth)
            ui->radioButton_absolute_size_width->click();
        else
            ui->radioButton_relative_size_width->click();

        //window/ full screen
        if(aktion.moveWindow.useFullScreen)
            ui->radioButton_aktiviereVollbild->click();
        else
            ui->radioButton_fenster_verschieben->click();

//
        ui->lineEdit_10_varName->setText (aktion.editVar.getName());
        ui->lineEdit_10_newValue->setText(aktion.editVar.getNewValue());
}

void AktionSelektDialog::on_comboBox_select_Aktion_currentIndexChanged(int index)
{
    ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled( ((index == 0) ? true : false) );
    ui->stackedWidget->setCurrentIndex(index);
}





void AktionSelektDialog::on_radioButton_fenster_verschieben_clicked()
{
    ui->groupBox_newPosX->setEnabled( true );
    ui->groupBox_newPosY->setEnabled( true );
    ui->groupBox_new_size_height->setEnabled ( true );
    ui->groupBox_new_size_width->setEnabled ( true );
    ui->label_13_newSize->setEnabled( true  );
    ui->label_10_bewegennach->setEnabled( true );

    ui->label_14_bildschirm->setEnabled  ( false );
    ui->spinBox_Bildschirm->setEnabled( false );

}

void AktionSelektDialog::on_radioButton_aktiviereVollbild_clicked()
{
    ui->groupBox_newPosX->setEnabled( false );
    ui->groupBox_newPosY->setEnabled( false );
    ui->groupBox_new_size_height->setEnabled ( false );
    ui->groupBox_new_size_width->setEnabled ( false );
    ui->label_13_newSize->setEnabled( false  );
    ui->label_10_bewegennach->setEnabled( false );

    ui->label_14_bildschirm->setEnabled  ( true );
    ui->spinBox_Bildschirm->setEnabled( true );
}





void AktionSelektDialog::on_radioButton_saveRUNCOMMOUTPUT_clicked(bool checked)
{
    ui->groupBox_run_command_ausgabespeichern->setEnabled( checked );

}

