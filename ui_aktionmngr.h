/********************************************************************************
** Form generated from reading UI file 'aktionmngr.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AKTIONMNGR_H
#define UI_AKTIONMNGR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AktionMngr
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_BedInput;
    QLabel *label_2;
    QComboBox *comboBox_Bed_3;
    QComboBox *comboBox_Bed2;
    QComboBox *comboBoxBed1;
    QLabel *label_9;
    QFormLayout *formLayout;
    QLabel *label_3;
    QSpinBox *spinBox_anzahl_ausfuehrungen;
    QLabel *label_6;
    QLabel *label_7;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QSpinBox *spinBox_aktualisierungsrate;
    QLabel *label_8;
    QLabel *label_4;
    QListWidget *listWidget_aktionen;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_add_aktion;
    QPushButton *pushButton_removeAktion;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_moveUp;
    QPushButton *pushButton_moveDown;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AktionMngr)
    {
        if (AktionMngr->objectName().isEmpty())
            AktionMngr->setObjectName(QString::fromUtf8("AktionMngr"));
        AktionMngr->setWindowModality(Qt::NonModal);
        AktionMngr->resize(866, 542);
        verticalLayout = new QVBoxLayout(AktionMngr);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(AktionMngr);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(AktionMngr);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout_3->addWidget(lineEdit_name, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_BedInput = new QLineEdit(AktionMngr);
        lineEdit_BedInput->setObjectName(QString::fromUtf8("lineEdit_BedInput"));

        gridLayout_2->addWidget(lineEdit_BedInput, 0, 6, 1, 1);

        label_2 = new QLabel(AktionMngr);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        comboBox_Bed_3 = new QComboBox(AktionMngr);
        comboBox_Bed_3->addItem(QString());
        comboBox_Bed_3->addItem(QString());
        comboBox_Bed_3->addItem(QString());
        comboBox_Bed_3->addItem(QString());
        comboBox_Bed_3->addItem(QString());
        comboBox_Bed_3->setObjectName(QString::fromUtf8("comboBox_Bed_3"));
        comboBox_Bed_3->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(comboBox_Bed_3, 0, 5, 1, 1);

        comboBox_Bed2 = new QComboBox(AktionMngr);
        comboBox_Bed2->addItem(QString());
        comboBox_Bed2->addItem(QString());
        comboBox_Bed2->addItem(QString());
        comboBox_Bed2->addItem(QString());
        comboBox_Bed2->addItem(QString());
        comboBox_Bed2->setObjectName(QString::fromUtf8("comboBox_Bed2"));
        comboBox_Bed2->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(comboBox_Bed2, 0, 4, 1, 1);

        comboBoxBed1 = new QComboBox(AktionMngr);
        comboBoxBed1->addItem(QString());
        comboBoxBed1->addItem(QString());
        comboBoxBed1->addItem(QString());
        comboBoxBed1->addItem(QString());
        comboBoxBed1->addItem(QString());
        comboBoxBed1->setObjectName(QString::fromUtf8("comboBoxBed1"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxBed1->sizePolicy().hasHeightForWidth());
        comboBoxBed1->setSizePolicy(sizePolicy);
        comboBoxBed1->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(comboBoxBed1, 0, 1, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        label_9 = new QLabel(AktionMngr);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(AktionMngr);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_anzahl_ausfuehrungen = new QSpinBox(AktionMngr);
        spinBox_anzahl_ausfuehrungen->setObjectName(QString::fromUtf8("spinBox_anzahl_ausfuehrungen"));
        spinBox_anzahl_ausfuehrungen->setValue(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_anzahl_ausfuehrungen);


        verticalLayout->addLayout(formLayout);

        label_6 = new QLabel(AktionMngr);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(AktionMngr);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_5 = new QLabel(AktionMngr);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        spinBox_aktualisierungsrate = new QSpinBox(AktionMngr);
        spinBox_aktualisierungsrate->setObjectName(QString::fromUtf8("spinBox_aktualisierungsrate"));
        spinBox_aktualisierungsrate->setMinimum(1);
        spinBox_aktualisierungsrate->setMaximum(999999);
        spinBox_aktualisierungsrate->setValue(100);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_aktualisierungsrate);


        verticalLayout->addLayout(formLayout_2);

        label_8 = new QLabel(AktionMngr);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_4 = new QLabel(AktionMngr);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        listWidget_aktionen = new QListWidget(AktionMngr);
        listWidget_aktionen->setObjectName(QString::fromUtf8("listWidget_aktionen"));

        verticalLayout->addWidget(listWidget_aktionen);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_add_aktion = new QPushButton(AktionMngr);
        pushButton_add_aktion->setObjectName(QString::fromUtf8("pushButton_add_aktion"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_add_aktion->sizePolicy().hasHeightForWidth());
        pushButton_add_aktion->setSizePolicy(sizePolicy1);
        pushButton_add_aktion->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Sans"));
        font1.setPointSize(26);
        pushButton_add_aktion->setFont(font1);
        pushButton_add_aktion->setStyleSheet(QString::fromUtf8("color: \"green\";"));

        horizontalLayout_2->addWidget(pushButton_add_aktion);

        pushButton_removeAktion = new QPushButton(AktionMngr);
        pushButton_removeAktion->setObjectName(QString::fromUtf8("pushButton_removeAktion"));
        sizePolicy1.setHeightForWidth(pushButton_removeAktion->sizePolicy().hasHeightForWidth());
        pushButton_removeAktion->setSizePolicy(sizePolicy1);
        pushButton_removeAktion->setMinimumSize(QSize(0, 0));
        pushButton_removeAktion->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Liberation Sans"));
        font2.setPointSize(31);
        font2.setBold(false);
        pushButton_removeAktion->setFont(font2);
        pushButton_removeAktion->setStyleSheet(QString::fromUtf8("color: \"red\";"));

        horizontalLayout_2->addWidget(pushButton_removeAktion);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_moveUp = new QPushButton(AktionMngr);
        pushButton_moveUp->setObjectName(QString::fromUtf8("pushButton_moveUp"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_moveUp->sizePolicy().hasHeightForWidth());
        pushButton_moveUp->setSizePolicy(sizePolicy2);
        pushButton_moveUp->setMinimumSize(QSize(0, 0));
        pushButton_moveUp->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Liberation Sans"));
        font3.setPointSize(16);
        pushButton_moveUp->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_moveUp);

        pushButton_moveDown = new QPushButton(AktionMngr);
        pushButton_moveDown->setObjectName(QString::fromUtf8("pushButton_moveDown"));
        sizePolicy2.setHeightForWidth(pushButton_moveDown->sizePolicy().hasHeightForWidth());
        pushButton_moveDown->setSizePolicy(sizePolicy2);
        pushButton_moveDown->setMaximumSize(QSize(30, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Liberation Sans"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        pushButton_moveDown->setFont(font4);

        horizontalLayout_2->addWidget(pushButton_moveDown);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(AktionMngr);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AktionMngr);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AktionMngr, &QDialog::reject);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AktionMngr, &QDialog::accept);

        QMetaObject::connectSlotsByName(AktionMngr);
    } // setupUi

    void retranslateUi(QDialog *AktionMngr)
    {
        AktionMngr->setWindowTitle(QCoreApplication::translate("AktionMngr", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AktionMngr", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("AktionMngr", "Start Bedingung:", nullptr));
        comboBox_Bed_3->setItemText(0, QString());
        comboBox_Bed_3->setItemText(1, QCoreApplication::translate("AktionMngr", "ung\303\274ltiger Pi Sensor Wert", nullptr));
        comboBox_Bed_3->setItemText(2, QCoreApplication::translate("AktionMngr", "verbundener Pi", nullptr));
        comboBox_Bed_3->setItemText(3, QCoreApplication::translate("AktionMngr", "geschlossen", nullptr));
        comboBox_Bed_3->setItemText(4, QCoreApplication::translate("AktionMngr", "offen", nullptr));

        comboBox_Bed2->setItemText(0, QString());
        comboBox_Bed2->setItemText(1, QCoreApplication::translate("AktionMngr", "ist/sind", nullptr));
        comboBox_Bed2->setItemText(2, QCoreApplication::translate("AktionMngr", "ist/sind nicht", nullptr));
        comboBox_Bed2->setItemText(3, QCoreApplication::translate("AktionMngr", "ist/sind gr\303\266\303\237er", nullptr));
        comboBox_Bed2->setItemText(4, QCoreApplication::translate("AktionMngr", "ist/sind kleiner", nullptr));

        comboBoxBed1->setItemText(0, QString());
        comboBoxBed1->setItemText(1, QCoreApplication::translate("AktionMngr", "Bedingung immer erf\303\274llt", nullptr));
        comboBoxBed1->setItemText(2, QCoreApplication::translate("AktionMngr", "Error", nullptr));
        comboBoxBed1->setItemText(3, QCoreApplication::translate("AktionMngr", "T\303\274r", nullptr));
        comboBoxBed1->setItemText(4, QCoreApplication::translate("AktionMngr", "Mausposition", nullptr));

        label_9->setText(QCoreApplication::translate("AktionMngr", "Diese Bedingung muss erf\303\274llt sein, dass die unten aufgelisteten Aktionen der Reihe nach ausgef\303\274hrt werden.", nullptr));
        label_3->setText(QCoreApplication::translate("AktionMngr", "Anzahl der Ausf\303\274hrungen", nullptr));
        label_6->setText(QCoreApplication::translate("AktionMngr", "Wenn die Anzahl erreicht, muss die Startbedingung f\303\274r einen erneuten Ablauf erst erneut erf\303\274llt sein, um die Aktionen auszuf\303\274hren.", nullptr));
        label_7->setText(QCoreApplication::translate("AktionMngr", "Mit der der Zahl 0 kann dieses Limit deaktiviert werden.", nullptr));
        label_5->setText(QCoreApplication::translate("AktionMngr", "Aktualisierungsrate in ms:", nullptr));
        label_8->setText(QCoreApplication::translate("AktionMngr", "Mit diesem Wert wird festgelegt, wie lange nach einer Startbedingungs\303\274berpr\303\274fung gewartet werden soll, bis diese erneut gepr\303\274ft wird", nullptr));
        label_4->setText(QCoreApplication::translate("AktionMngr", "Aktionen:", nullptr));
        pushButton_add_aktion->setText(QCoreApplication::translate("AktionMngr", "+", nullptr));
        pushButton_removeAktion->setText(QCoreApplication::translate("AktionMngr", "-", nullptr));
        pushButton_moveUp->setText(QCoreApplication::translate("AktionMngr", "\342\226\262", nullptr));
        pushButton_moveDown->setText(QCoreApplication::translate("AktionMngr", "\342\226\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AktionMngr: public Ui_AktionMngr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AKTIONMNGR_H
