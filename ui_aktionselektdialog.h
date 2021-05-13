/********************************************************************************
** Form generated from reading UI file 'aktionselektdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AKTIONSELEKTDIALOG_H
#define UI_AKTIONSELEKTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AktionSelektDialog
{
public:
    QGridLayout *gridLayout_4;
    QComboBox *comboBox_select_Aktion;
    QStackedWidget *stackedWidget;
    QWidget *page_0_empty;
    QWidget *page_1_Sleep;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spinBox_sleep_time_sekunden;
    QSpinBox *spinBox_sleep_time_minuten;
    QWidget *page_2_show_msg;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_sendMessage_messag;
    QWidget *page_3_run_command;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_command;
    QWidget *page_4_window_sichtbarkeit_veraendern;
    QFormLayout *formLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_chacnhe_visibility_window_name;
    QLabel *label_7;
    QComboBox *comboBox_change_vbty_parity;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_change_vbty_hide_button;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton_change_vbty_show_button;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_5_sound_mute;
    QFormLayout *formLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QRadioButton *radioButton_mute_system_mute_rad_button;
    QRadioButton *radioButton_mute_system_unmute_rad_button;
    QWidget *page_6_re_check_condition_again;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_5;
    QRadioButton *radioButton_recheck_con_stop_seq;
    QRadioButton *radioButton_recheck_con_skip_next_aktion;
    QRadioButton *radioButton_recheck_stop_programm;
    QSpacerItem *verticalSpacer;
    QWidget *page_7__fenster_bewegen;
    QFormLayout *formLayout_7;
    QLabel *label_11;
    QLineEdit *lineEdit_move_window_window_name;
    QLabel *label_12;
    QComboBox *comboBox_move_window_window_parity;
    QLabel *label_15;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *radioButton_aktiviereVollbild;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_8;
    QRadioButton *radioButton_fenster_verschieben;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_14_bildschirm;
    QSpinBox *spinBox_Bildschirm;
    QLabel *label_10_bewegennach;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_newPosY;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_10;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_absoltutePosY;
    QRadioButton *radioButton_relativ_posY;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QSpinBox *spinBox_move_window_pos_Y;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_newPosX;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_9;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_absoltutePosX;
    QRadioButton *radioButton_relativ_posX;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QSpinBox *spinBox_movewindow_pos_X;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_13_newSize;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_new_size_width;
    QVBoxLayout *verticalLayout_11;
    QFormLayout *formLayout_8;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton_absolute_size_width;
    QRadioButton *radioButton_relative_size_width;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_7;
    QSpinBox *spinBox_new_size_width;
    QSpacerItem *verticalSpacer_9;
    QGroupBox *groupBox_new_size_height;
    QVBoxLayout *verticalLayout_12;
    QFormLayout *formLayout_11;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *radioButton_absolute_size_heigth;
    QRadioButton *radioButton_relative_size_heigth;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_8;
    QSpinBox *spinBox_new_size_height;
    QSpacerItem *verticalSpacer_10;
    QWidget *page_8;
    QWidget *page_9;
    QWidget *page_10;
    QGroupBox *groupBox_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AktionSelektDialog)
    {
        if (AktionSelektDialog->objectName().isEmpty())
            AktionSelektDialog->setObjectName(QString::fromUtf8("AktionSelektDialog"));
        AktionSelektDialog->setWindowModality(Qt::WindowModal);
        AktionSelektDialog->resize(600, 426);
        gridLayout_4 = new QGridLayout(AktionSelektDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        comboBox_select_Aktion = new QComboBox(AktionSelektDialog);
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->addItem(QString());
        comboBox_select_Aktion->setObjectName(QString::fromUtf8("comboBox_select_Aktion"));

        gridLayout_4->addWidget(comboBox_select_Aktion, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(AktionSelektDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page_0_empty = new QWidget();
        page_0_empty->setObjectName(QString::fromUtf8("page_0_empty"));
        stackedWidget->addWidget(page_0_empty);
        page_1_Sleep = new QWidget();
        page_1_Sleep->setObjectName(QString::fromUtf8("page_1_Sleep"));
        formLayout = new QFormLayout(page_1_Sleep);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(page_1_Sleep);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(page_1_Sleep);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(page_1_Sleep);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        spinBox_sleep_time_sekunden = new QSpinBox(page_1_Sleep);
        spinBox_sleep_time_sekunden->setObjectName(QString::fromUtf8("spinBox_sleep_time_sekunden"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_sleep_time_sekunden->sizePolicy().hasHeightForWidth());
        spinBox_sleep_time_sekunden->setSizePolicy(sizePolicy2);
        spinBox_sleep_time_sekunden->setMaximum(59);
        spinBox_sleep_time_sekunden->setValue(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_sleep_time_sekunden);

        spinBox_sleep_time_minuten = new QSpinBox(page_1_Sleep);
        spinBox_sleep_time_minuten->setObjectName(QString::fromUtf8("spinBox_sleep_time_minuten"));
        sizePolicy2.setHeightForWidth(spinBox_sleep_time_minuten->sizePolicy().hasHeightForWidth());
        spinBox_sleep_time_minuten->setSizePolicy(sizePolicy2);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_sleep_time_minuten);

        stackedWidget->addWidget(page_1_Sleep);
        page_2_show_msg = new QWidget();
        page_2_show_msg->setObjectName(QString::fromUtf8("page_2_show_msg"));
        formLayout_3 = new QFormLayout(page_2_show_msg);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label = new QLabel(page_2_show_msg);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_sendMessage_messag = new QLineEdit(page_2_show_msg);
        lineEdit_sendMessage_messag->setObjectName(QString::fromUtf8("lineEdit_sendMessage_messag"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit_sendMessage_messag);

        stackedWidget->addWidget(page_2_show_msg);
        page_3_run_command = new QWidget();
        page_3_run_command->setObjectName(QString::fromUtf8("page_3_run_command"));
        formLayout_2 = new QFormLayout(page_3_run_command);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_5 = new QLabel(page_3_run_command);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEdit_command = new QLineEdit(page_3_run_command);
        lineEdit_command->setObjectName(QString::fromUtf8("lineEdit_command"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_command);

        stackedWidget->addWidget(page_3_run_command);
        page_4_window_sichtbarkeit_veraendern = new QWidget();
        page_4_window_sichtbarkeit_veraendern->setObjectName(QString::fromUtf8("page_4_window_sichtbarkeit_veraendern"));
        formLayout_4 = new QFormLayout(page_4_window_sichtbarkeit_veraendern);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_6 = new QLabel(page_4_window_sichtbarkeit_veraendern);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEdit_chacnhe_visibility_window_name = new QLineEdit(page_4_window_sichtbarkeit_veraendern);
        lineEdit_chacnhe_visibility_window_name->setObjectName(QString::fromUtf8("lineEdit_chacnhe_visibility_window_name"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_chacnhe_visibility_window_name);

        label_7 = new QLabel(page_4_window_sichtbarkeit_veraendern);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_7);

        comboBox_change_vbty_parity = new QComboBox(page_4_window_sichtbarkeit_veraendern);
        comboBox_change_vbty_parity->addItem(QString());
        comboBox_change_vbty_parity->addItem(QString());
        comboBox_change_vbty_parity->addItem(QString());
        comboBox_change_vbty_parity->addItem(QString());
        comboBox_change_vbty_parity->setObjectName(QString::fromUtf8("comboBox_change_vbty_parity"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, comboBox_change_vbty_parity);

        label_8 = new QLabel(page_4_window_sichtbarkeit_veraendern);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        radioButton_change_vbty_hide_button = new QRadioButton(page_4_window_sichtbarkeit_veraendern);
        radioButton_change_vbty_hide_button->setObjectName(QString::fromUtf8("radioButton_change_vbty_hide_button"));
        radioButton_change_vbty_hide_button->setChecked(true);

        horizontalLayout_4->addWidget(radioButton_change_vbty_hide_button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        radioButton_change_vbty_show_button = new QRadioButton(page_4_window_sichtbarkeit_veraendern);
        radioButton_change_vbty_show_button->setObjectName(QString::fromUtf8("radioButton_change_vbty_show_button"));

        horizontalLayout_4->addWidget(radioButton_change_vbty_show_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        formLayout_4->setLayout(2, QFormLayout::FieldRole, horizontalLayout_4);

        stackedWidget->addWidget(page_4_window_sichtbarkeit_veraendern);
        page_5_sound_mute = new QWidget();
        page_5_sound_mute->setObjectName(QString::fromUtf8("page_5_sound_mute"));
        formLayout_6 = new QFormLayout(page_5_sound_mute);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(page_5_sound_mute);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        radioButton_mute_system_mute_rad_button = new QRadioButton(page_5_sound_mute);
        radioButton_mute_system_mute_rad_button->setObjectName(QString::fromUtf8("radioButton_mute_system_mute_rad_button"));
        radioButton_mute_system_mute_rad_button->setChecked(true);

        horizontalLayout->addWidget(radioButton_mute_system_mute_rad_button);

        radioButton_mute_system_unmute_rad_button = new QRadioButton(page_5_sound_mute);
        radioButton_mute_system_unmute_rad_button->setObjectName(QString::fromUtf8("radioButton_mute_system_unmute_rad_button"));

        horizontalLayout->addWidget(radioButton_mute_system_unmute_rad_button);


        formLayout_6->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        stackedWidget->addWidget(page_5_sound_mute);
        page_6_re_check_condition_again = new QWidget();
        page_6_re_check_condition_again->setObjectName(QString::fromUtf8("page_6_re_check_condition_again"));
        gridLayout = new QGridLayout(page_6_re_check_condition_again);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        radioButton_recheck_con_stop_seq = new QRadioButton(page_6_re_check_condition_again);
        radioButton_recheck_con_stop_seq->setObjectName(QString::fromUtf8("radioButton_recheck_con_stop_seq"));
        radioButton_recheck_con_stop_seq->setChecked(true);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, radioButton_recheck_con_stop_seq);

        radioButton_recheck_con_skip_next_aktion = new QRadioButton(page_6_re_check_condition_again);
        radioButton_recheck_con_skip_next_aktion->setObjectName(QString::fromUtf8("radioButton_recheck_con_skip_next_aktion"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, radioButton_recheck_con_skip_next_aktion);

        radioButton_recheck_stop_programm = new QRadioButton(page_6_re_check_condition_again);
        radioButton_recheck_stop_programm->setObjectName(QString::fromUtf8("radioButton_recheck_stop_programm"));
        sizePolicy2.setHeightForWidth(radioButton_recheck_stop_programm->sizePolicy().hasHeightForWidth());
        radioButton_recheck_stop_programm->setSizePolicy(sizePolicy2);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, radioButton_recheck_stop_programm);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_5->setItem(3, QFormLayout::FieldRole, verticalSpacer);


        gridLayout->addLayout(formLayout_5, 0, 0, 1, 1);

        stackedWidget->addWidget(page_6_re_check_condition_again);
        page_7__fenster_bewegen = new QWidget();
        page_7__fenster_bewegen->setObjectName(QString::fromUtf8("page_7__fenster_bewegen"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(page_7__fenster_bewegen->sizePolicy().hasHeightForWidth());
        page_7__fenster_bewegen->setSizePolicy(sizePolicy3);
        formLayout_7 = new QFormLayout(page_7__fenster_bewegen);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_11 = new QLabel(page_7__fenster_bewegen);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        label_11->setFont(font);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_11);

        lineEdit_move_window_window_name = new QLineEdit(page_7__fenster_bewegen);
        lineEdit_move_window_window_name->setObjectName(QString::fromUtf8("lineEdit_move_window_window_name"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, lineEdit_move_window_window_name);

        label_12 = new QLabel(page_7__fenster_bewegen);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_12);

        comboBox_move_window_window_parity = new QComboBox(page_7__fenster_bewegen);
        comboBox_move_window_window_parity->addItem(QString());
        comboBox_move_window_window_parity->addItem(QString());
        comboBox_move_window_window_parity->addItem(QString());
        comboBox_move_window_window_parity->addItem(QString());
        comboBox_move_window_window_parity->setObjectName(QString::fromUtf8("comboBox_move_window_window_parity"));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        comboBox_move_window_window_parity->setFont(font1);

        formLayout_7->setWidget(1, QFormLayout::FieldRole, comboBox_move_window_window_parity);

        label_15 = new QLabel(page_7__fenster_bewegen);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_15);

        groupBox = new QGroupBox(page_7__fenster_bewegen);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        radioButton_aktiviereVollbild = new QRadioButton(groupBox);
        radioButton_aktiviereVollbild->setObjectName(QString::fromUtf8("radioButton_aktiviereVollbild"));
        radioButton_aktiviereVollbild->setFont(font);
        radioButton_aktiviereVollbild->setChecked(true);
        radioButton_aktiviereVollbild->setAutoExclusive(true);

        horizontalLayout_2->addWidget(radioButton_aktiviereVollbild);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        radioButton_fenster_verschieben = new QRadioButton(groupBox);
        radioButton_fenster_verschieben->setObjectName(QString::fromUtf8("radioButton_fenster_verschieben"));
        radioButton_fenster_verschieben->setFont(font);
        radioButton_fenster_verschieben->setChecked(false);
        radioButton_fenster_verschieben->setAutoExclusive(true);

        horizontalLayout_2->addWidget(radioButton_fenster_verschieben);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        formLayout_7->setWidget(2, QFormLayout::FieldRole, groupBox);

        label_14_bildschirm = new QLabel(page_7__fenster_bewegen);
        label_14_bildschirm->setObjectName(QString::fromUtf8("label_14_bildschirm"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_14_bildschirm->sizePolicy().hasHeightForWidth());
        label_14_bildschirm->setSizePolicy(sizePolicy4);
        label_14_bildschirm->setMinimumSize(QSize(100, 0));
        label_14_bildschirm->setFont(font);

        formLayout_7->setWidget(3, QFormLayout::LabelRole, label_14_bildschirm);

        spinBox_Bildschirm = new QSpinBox(page_7__fenster_bewegen);
        spinBox_Bildschirm->setObjectName(QString::fromUtf8("spinBox_Bildschirm"));
        spinBox_Bildschirm->setEnabled(true);
        sizePolicy2.setHeightForWidth(spinBox_Bildschirm->sizePolicy().hasHeightForWidth());
        spinBox_Bildschirm->setSizePolicy(sizePolicy2);
        spinBox_Bildschirm->setMinimumSize(QSize(0, 0));
        spinBox_Bildschirm->setMaximumSize(QSize(16777215, 16777215));
        spinBox_Bildschirm->setMinimum(1);

        formLayout_7->setWidget(3, QFormLayout::FieldRole, spinBox_Bildschirm);

        label_10_bewegennach = new QLabel(page_7__fenster_bewegen);
        label_10_bewegennach->setObjectName(QString::fromUtf8("label_10_bewegennach"));
        sizePolicy4.setHeightForWidth(label_10_bewegennach->sizePolicy().hasHeightForWidth());
        label_10_bewegennach->setSizePolicy(sizePolicy4);
        label_10_bewegennach->setMinimumSize(QSize(100, 0));
        label_10_bewegennach->setFont(font);

        formLayout_7->setWidget(4, QFormLayout::LabelRole, label_10_bewegennach);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox_newPosY = new QGroupBox(page_7__fenster_bewegen);
        groupBox_newPosY->setObjectName(QString::fromUtf8("groupBox_newPosY"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_newPosY->sizePolicy().hasHeightForWidth());
        groupBox_newPosY->setSizePolicy(sizePolicy5);
        verticalLayout_2 = new QVBoxLayout(groupBox_newPosY);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        radioButton_absoltutePosY = new QRadioButton(groupBox_newPosY);
        radioButton_absoltutePosY->setObjectName(QString::fromUtf8("radioButton_absoltutePosY"));
        radioButton_absoltutePosY->setEnabled(true);
        radioButton_absoltutePosY->setMinimumSize(QSize(120, 0));
        radioButton_absoltutePosY->setChecked(true);
        radioButton_absoltutePosY->setAutoExclusive(true);

        verticalLayout_7->addWidget(radioButton_absoltutePosY);

        radioButton_relativ_posY = new QRadioButton(groupBox_newPosY);
        radioButton_relativ_posY->setObjectName(QString::fromUtf8("radioButton_relativ_posY"));
        radioButton_relativ_posY->setAutoExclusive(true);

        verticalLayout_7->addWidget(radioButton_relativ_posY);


        formLayout_10->setLayout(0, QFormLayout::LabelRole, verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_5);

        spinBox_move_window_pos_Y = new QSpinBox(groupBox_newPosY);
        spinBox_move_window_pos_Y->setObjectName(QString::fromUtf8("spinBox_move_window_pos_Y"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox_move_window_pos_Y->sizePolicy().hasHeightForWidth());
        spinBox_move_window_pos_Y->setSizePolicy(sizePolicy6);
        spinBox_move_window_pos_Y->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_move_window_pos_Y->setMinimum(-9999);
        spinBox_move_window_pos_Y->setMaximum(99999);

        verticalLayout_4->addWidget(spinBox_move_window_pos_Y);

        verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_6);


        formLayout_10->setLayout(0, QFormLayout::FieldRole, verticalLayout_4);


        verticalLayout_2->addLayout(formLayout_10);


        gridLayout_2->addWidget(groupBox_newPosY, 0, 1, 1, 1);

        groupBox_newPosX = new QGroupBox(page_7__fenster_bewegen);
        groupBox_newPosX->setObjectName(QString::fromUtf8("groupBox_newPosX"));
        sizePolicy5.setHeightForWidth(groupBox_newPosX->sizePolicy().hasHeightForWidth());
        groupBox_newPosX->setSizePolicy(sizePolicy5);
        verticalLayout = new QVBoxLayout(groupBox_newPosX);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        formLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        radioButton_absoltutePosX = new QRadioButton(groupBox_newPosX);
        radioButton_absoltutePosX->setObjectName(QString::fromUtf8("radioButton_absoltutePosX"));
        radioButton_absoltutePosX->setEnabled(true);
        radioButton_absoltutePosX->setMinimumSize(QSize(120, 0));
        radioButton_absoltutePosX->setChecked(true);
        radioButton_absoltutePosX->setAutoExclusive(true);

        verticalLayout_5->addWidget(radioButton_absoltutePosX);

        radioButton_relativ_posX = new QRadioButton(groupBox_newPosX);
        radioButton_relativ_posX->setObjectName(QString::fromUtf8("radioButton_relativ_posX"));
        radioButton_relativ_posX->setAutoExclusive(true);

        verticalLayout_5->addWidget(radioButton_relativ_posX);


        formLayout_9->setLayout(0, QFormLayout::LabelRole, verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_4 = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_4);

        spinBox_movewindow_pos_X = new QSpinBox(groupBox_newPosX);
        spinBox_movewindow_pos_X->setObjectName(QString::fromUtf8("spinBox_movewindow_pos_X"));
        sizePolicy6.setHeightForWidth(spinBox_movewindow_pos_X->sizePolicy().hasHeightForWidth());
        spinBox_movewindow_pos_X->setSizePolicy(sizePolicy6);
        spinBox_movewindow_pos_X->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_movewindow_pos_X->setMinimum(-9999);
        spinBox_movewindow_pos_X->setMaximum(99999);

        verticalLayout_3->addWidget(spinBox_movewindow_pos_X);

        verticalSpacer_3 = new QSpacerItem(0, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_3);


        formLayout_9->setLayout(0, QFormLayout::FieldRole, verticalLayout_3);


        verticalLayout->addLayout(formLayout_9);


        gridLayout_2->addWidget(groupBox_newPosX, 0, 0, 1, 1);


        formLayout_7->setLayout(4, QFormLayout::FieldRole, gridLayout_2);

        label_13_newSize = new QLabel(page_7__fenster_bewegen);
        label_13_newSize->setObjectName(QString::fromUtf8("label_13_newSize"));
        sizePolicy4.setHeightForWidth(label_13_newSize->sizePolicy().hasHeightForWidth());
        label_13_newSize->setSizePolicy(sizePolicy4);
        label_13_newSize->setMinimumSize(QSize(100, 0));
        label_13_newSize->setFont(font);

        formLayout_7->setWidget(5, QFormLayout::LabelRole, label_13_newSize);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_new_size_width = new QGroupBox(page_7__fenster_bewegen);
        groupBox_new_size_width->setObjectName(QString::fromUtf8("groupBox_new_size_width"));
        sizePolicy5.setHeightForWidth(groupBox_new_size_width->sizePolicy().hasHeightForWidth());
        groupBox_new_size_width->setSizePolicy(sizePolicy5);
        verticalLayout_11 = new QVBoxLayout(groupBox_new_size_width);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        radioButton_absolute_size_width = new QRadioButton(groupBox_new_size_width);
        radioButton_absolute_size_width->setObjectName(QString::fromUtf8("radioButton_absolute_size_width"));
        radioButton_absolute_size_width->setMinimumSize(QSize(120, 0));
        radioButton_absolute_size_width->setChecked(true);
        radioButton_absolute_size_width->setAutoExclusive(true);

        verticalLayout_6->addWidget(radioButton_absolute_size_width);

        radioButton_relative_size_width = new QRadioButton(groupBox_new_size_width);
        radioButton_relative_size_width->setObjectName(QString::fromUtf8("radioButton_relative_size_width"));
        radioButton_relative_size_width->setAutoExclusive(true);

        verticalLayout_6->addWidget(radioButton_relative_size_width);


        formLayout_8->setLayout(0, QFormLayout::LabelRole, verticalLayout_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_7 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        spinBox_new_size_width = new QSpinBox(groupBox_new_size_width);
        spinBox_new_size_width->setObjectName(QString::fromUtf8("spinBox_new_size_width"));
        spinBox_new_size_width->setMinimum(-9999);
        spinBox_new_size_width->setMaximum(99999);

        verticalLayout_9->addWidget(spinBox_new_size_width);

        verticalSpacer_9 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);


        formLayout_8->setLayout(0, QFormLayout::FieldRole, verticalLayout_9);


        verticalLayout_11->addLayout(formLayout_8);


        gridLayout_3->addWidget(groupBox_new_size_width, 0, 0, 1, 1);

        groupBox_new_size_height = new QGroupBox(page_7__fenster_bewegen);
        groupBox_new_size_height->setObjectName(QString::fromUtf8("groupBox_new_size_height"));
        sizePolicy5.setHeightForWidth(groupBox_new_size_height->sizePolicy().hasHeightForWidth());
        groupBox_new_size_height->setSizePolicy(sizePolicy5);
        verticalLayout_12 = new QVBoxLayout(groupBox_new_size_height);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        radioButton_absolute_size_heigth = new QRadioButton(groupBox_new_size_height);
        radioButton_absolute_size_heigth->setObjectName(QString::fromUtf8("radioButton_absolute_size_heigth"));
        radioButton_absolute_size_heigth->setMinimumSize(QSize(120, 0));
        radioButton_absolute_size_heigth->setChecked(true);
        radioButton_absolute_size_heigth->setAutoExclusive(true);

        verticalLayout_8->addWidget(radioButton_absolute_size_heigth);

        radioButton_relative_size_heigth = new QRadioButton(groupBox_new_size_height);
        radioButton_relative_size_heigth->setObjectName(QString::fromUtf8("radioButton_relative_size_heigth"));
        radioButton_relative_size_heigth->setAutoExclusive(true);

        verticalLayout_8->addWidget(radioButton_relative_size_heigth);


        formLayout_11->setLayout(0, QFormLayout::LabelRole, verticalLayout_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalSpacer_8 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_8);

        spinBox_new_size_height = new QSpinBox(groupBox_new_size_height);
        spinBox_new_size_height->setObjectName(QString::fromUtf8("spinBox_new_size_height"));
        spinBox_new_size_height->setMinimum(-9999);
        spinBox_new_size_height->setMaximum(99999);

        verticalLayout_10->addWidget(spinBox_new_size_height);

        verticalSpacer_10 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_10);


        formLayout_11->setLayout(0, QFormLayout::FieldRole, verticalLayout_10);


        verticalLayout_12->addLayout(formLayout_11);


        gridLayout_3->addWidget(groupBox_new_size_height, 0, 1, 1, 1);


        formLayout_7->setLayout(5, QFormLayout::FieldRole, gridLayout_3);

        stackedWidget->addWidget(page_7__fenster_bewegen);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        stackedWidget->addWidget(page_10);

        gridLayout_4->addWidget(stackedWidget, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(AktionSelektDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMaximumSize(QSize(16777215, 1));

        gridLayout_4->addWidget(groupBox_2, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AktionSelektDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(AktionSelektDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AktionSelektDialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AktionSelektDialog, &QDialog::reject);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(AktionSelektDialog);
    } // setupUi

    void retranslateUi(QDialog *AktionSelektDialog)
    {
        AktionSelektDialog->setWindowTitle(QCoreApplication::translate("AktionSelektDialog", "Dialog", nullptr));
        comboBox_select_Aktion->setItemText(0, QCoreApplication::translate("AktionSelektDialog", "--Ausw\303\244hlen--", nullptr));
        comboBox_select_Aktion->setItemText(1, QCoreApplication::translate("AktionSelektDialog", "Pause", nullptr));
        comboBox_select_Aktion->setItemText(2, QCoreApplication::translate("AktionSelektDialog", "Nachricht anzeigen", nullptr));
        comboBox_select_Aktion->setItemText(3, QCoreApplication::translate("AktionSelektDialog", "Befehl ausf\303\274hren", nullptr));
        comboBox_select_Aktion->setItemText(4, QCoreApplication::translate("AktionSelektDialog", "Fenster Sichtbarkeit \303\244ndern", nullptr));
        comboBox_select_Aktion->setItemText(5, QCoreApplication::translate("AktionSelektDialog", "Tonasugabe muten", nullptr));
        comboBox_select_Aktion->setItemText(6, QCoreApplication::translate("AktionSelektDialog", "Wiederhohlte Bedingungspr\303\274fung", nullptr));
        comboBox_select_Aktion->setItemText(7, QCoreApplication::translate("AktionSelektDialog", "Fenster Bewegen", nullptr));
        comboBox_select_Aktion->setItemText(8, QCoreApplication::translate("AktionSelektDialog", "Mauszeiger Bewegen", nullptr));
        comboBox_select_Aktion->setItemText(9, QCoreApplication::translate("AktionSelektDialog", "Computer Herunterfahren / Neustarten", nullptr));

        label_3->setText(QCoreApplication::translate("AktionSelektDialog", "Dauer:", nullptr));
        label_2->setText(QCoreApplication::translate("AktionSelektDialog", "Sekunden:", nullptr));
        label_4->setText(QCoreApplication::translate("AktionSelektDialog", "Minuten:", nullptr));
        label->setText(QCoreApplication::translate("AktionSelektDialog", "Nachricht:", nullptr));
        label_5->setText(QCoreApplication::translate("AktionSelektDialog", "Befehl:", nullptr));
        label_6->setText(QCoreApplication::translate("AktionSelektDialog", "Fenstername:", nullptr));
        label_7->setText(QCoreApplication::translate("AktionSelektDialog", "\303\234bereinstimmung:", nullptr));
        comboBox_change_vbty_parity->setItemText(0, QCoreApplication::translate("AktionSelektDialog", "Namen m\303\274ssen zu 100% \303\274bereinstimmen", nullptr));
        comboBox_change_vbty_parity->setItemText(1, QCoreApplication::translate("AktionSelektDialog", "Fenstername muss den angegebenen Namen enthalten", nullptr));
        comboBox_change_vbty_parity->setItemText(2, QCoreApplication::translate("AktionSelektDialog", "Fenstername muss mit dem angegebenen Namen beginnen", nullptr));
        comboBox_change_vbty_parity->setItemText(3, QCoreApplication::translate("AktionSelektDialog", "Fenstername muss mit dem angegebenen Namen enden", nullptr));

        label_8->setText(QCoreApplication::translate("AktionSelektDialog", "Fenster", nullptr));
        radioButton_change_vbty_hide_button->setText(QCoreApplication::translate("AktionSelektDialog", "Verstecken", nullptr));
        radioButton_change_vbty_show_button->setText(QCoreApplication::translate("AktionSelektDialog", "Aufdecken", nullptr));
        label_9->setText(QCoreApplication::translate("AktionSelektDialog", "Mute Status:", nullptr));
        radioButton_mute_system_mute_rad_button->setText(QCoreApplication::translate("AktionSelektDialog", "Mute System", nullptr));
        radioButton_mute_system_unmute_rad_button->setText(QCoreApplication::translate("AktionSelektDialog", "Unmute System", nullptr));
        radioButton_recheck_con_stop_seq->setText(QCoreApplication::translate("AktionSelektDialog", "Aktionausf\303\274hren unterbrechen", nullptr));
        radioButton_recheck_con_skip_next_aktion->setText(QCoreApplication::translate("AktionSelektDialog", "N\303\244chste Aktion \303\274berspringen", nullptr));
        radioButton_recheck_stop_programm->setText(QCoreApplication::translate("AktionSelektDialog", "Programm beenden", nullptr));
        label_11->setText(QCoreApplication::translate("AktionSelektDialog", "Fenstername:", nullptr));
        label_12->setText(QCoreApplication::translate("AktionSelektDialog", "\303\234bereinstimmung:", nullptr));
        comboBox_move_window_window_parity->setItemText(0, QCoreApplication::translate("AktionSelektDialog", "Namen m\303\274ssen zu 100% \303\274bereinstimmen", nullptr));
        comboBox_move_window_window_parity->setItemText(1, QCoreApplication::translate("AktionSelektDialog", "Fenstername muss den angegebenen Namen enthalten", nullptr));
        comboBox_move_window_window_parity->setItemText(2, QCoreApplication::translate("AktionSelektDialog", "Fenstername muss mit dem angegebenen Namen beginnen", nullptr));
        comboBox_move_window_window_parity->setItemText(3, QCoreApplication::translate("AktionSelektDialog", "Fenstername muss mit dem angegebenen Namen enden", nullptr));

        label_15->setText(QCoreApplication::translate("AktionSelektDialog", "Verschieben als", nullptr));
        groupBox->setTitle(QString());
        radioButton_aktiviereVollbild->setText(QCoreApplication::translate("AktionSelektDialog", "Vollbild", nullptr));
        radioButton_fenster_verschieben->setText(QCoreApplication::translate("AktionSelektDialog", "Fenster", nullptr));
        label_14_bildschirm->setText(QCoreApplication::translate("AktionSelektDialog", "Bildschirm:", nullptr));
        label_10_bewegennach->setText(QCoreApplication::translate("AktionSelektDialog", "Bewegen nach:", nullptr));
        groupBox_newPosY->setTitle(QCoreApplication::translate("AktionSelektDialog", "Y - Koordinate", nullptr));
        radioButton_absoltutePosY->setText(QCoreApplication::translate("AktionSelektDialog", "Absolute Position", nullptr));
        radioButton_relativ_posY->setText(QCoreApplication::translate("AktionSelektDialog", "Relative Position", nullptr));
        groupBox_newPosX->setTitle(QCoreApplication::translate("AktionSelektDialog", "X - Koordinate", nullptr));
        radioButton_absoltutePosX->setText(QCoreApplication::translate("AktionSelektDialog", "Absolute Position", nullptr));
        radioButton_relativ_posX->setText(QCoreApplication::translate("AktionSelektDialog", "Relative Position", nullptr));
        label_13_newSize->setText(QCoreApplication::translate("AktionSelektDialog", "Neue Gr\303\266\303\237e", nullptr));
        groupBox_new_size_width->setTitle(QCoreApplication::translate("AktionSelektDialog", "Breite", nullptr));
        radioButton_absolute_size_width->setText(QCoreApplication::translate("AktionSelektDialog", "Absolute Breite", nullptr));
        radioButton_relative_size_width->setText(QCoreApplication::translate("AktionSelektDialog", "Relative Breite", nullptr));
        groupBox_new_size_height->setTitle(QCoreApplication::translate("AktionSelektDialog", "H\303\266he", nullptr));
        radioButton_absolute_size_heigth->setText(QCoreApplication::translate("AktionSelektDialog", "Absolute Breite", nullptr));
        radioButton_relative_size_heigth->setText(QCoreApplication::translate("AktionSelektDialog", "Relative Breite", nullptr));
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class AktionSelektDialog: public Ui_AktionSelektDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AKTIONSELEKTDIALOG_H
