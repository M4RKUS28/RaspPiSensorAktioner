/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_add_aktionMngr;
    QPushButton *pushButton_removeAktionMngr;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_moveUp;
    QPushButton *pushButton_moveDown;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_enable;
    QPushButton *pushButton_disable;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(760, 591);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font;
        font.setPointSize(12);
        listWidget->setFont(font);
        listWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_add_aktionMngr = new QPushButton(centralwidget);
        pushButton_add_aktionMngr->setObjectName(QString::fromUtf8("pushButton_add_aktionMngr"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_add_aktionMngr->sizePolicy().hasHeightForWidth());
        pushButton_add_aktionMngr->setSizePolicy(sizePolicy);
        pushButton_add_aktionMngr->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Sans"));
        font1.setPointSize(26);
        font1.setKerning(true);
        pushButton_add_aktionMngr->setFont(font1);
        pushButton_add_aktionMngr->setLayoutDirection(Qt::LeftToRight);
        pushButton_add_aktionMngr->setStyleSheet(QString::fromUtf8("color: \"green\";"));

        horizontalLayout_3->addWidget(pushButton_add_aktionMngr);

        pushButton_removeAktionMngr = new QPushButton(centralwidget);
        pushButton_removeAktionMngr->setObjectName(QString::fromUtf8("pushButton_removeAktionMngr"));
        sizePolicy.setHeightForWidth(pushButton_removeAktionMngr->sizePolicy().hasHeightForWidth());
        pushButton_removeAktionMngr->setSizePolicy(sizePolicy);
        pushButton_removeAktionMngr->setMinimumSize(QSize(0, 0));
        pushButton_removeAktionMngr->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Liberation Sans"));
        font2.setPointSize(31);
        font2.setBold(false);
        pushButton_removeAktionMngr->setFont(font2);
        pushButton_removeAktionMngr->setStyleSheet(QString::fromUtf8("color: \"red\";"));

        horizontalLayout_3->addWidget(pushButton_removeAktionMngr);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_moveUp = new QPushButton(centralwidget);
        pushButton_moveUp->setObjectName(QString::fromUtf8("pushButton_moveUp"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_moveUp->sizePolicy().hasHeightForWidth());
        pushButton_moveUp->setSizePolicy(sizePolicy1);
        pushButton_moveUp->setMinimumSize(QSize(0, 0));
        pushButton_moveUp->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Liberation Sans"));
        font3.setPointSize(16);
        pushButton_moveUp->setFont(font3);

        horizontalLayout_3->addWidget(pushButton_moveUp);

        pushButton_moveDown = new QPushButton(centralwidget);
        pushButton_moveDown->setObjectName(QString::fromUtf8("pushButton_moveDown"));
        sizePolicy1.setHeightForWidth(pushButton_moveDown->sizePolicy().hasHeightForWidth());
        pushButton_moveDown->setSizePolicy(sizePolicy1);
        pushButton_moveDown->setMaximumSize(QSize(30, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Liberation Sans"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        pushButton_moveDown->setFont(font4);

        horizontalLayout_3->addWidget(pushButton_moveDown);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_enable = new QPushButton(centralwidget);
        pushButton_enable->setObjectName(QString::fromUtf8("pushButton_enable"));
        sizePolicy.setHeightForWidth(pushButton_enable->sizePolicy().hasHeightForWidth());
        pushButton_enable->setSizePolicy(sizePolicy);
        pushButton_enable->setMaximumSize(QSize(30, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Liberation Sans"));
        font5.setPointSize(18);
        font5.setKerning(true);
        pushButton_enable->setFont(font5);
        pushButton_enable->setLayoutDirection(Qt::LeftToRight);
        pushButton_enable->setStyleSheet(QString::fromUtf8("color: \"green\";"));

        horizontalLayout_3->addWidget(pushButton_enable);

        pushButton_disable = new QPushButton(centralwidget);
        pushButton_disable->setObjectName(QString::fromUtf8("pushButton_disable"));
        sizePolicy.setHeightForWidth(pushButton_disable->sizePolicy().hasHeightForWidth());
        pushButton_disable->setSizePolicy(sizePolicy);
        pushButton_disable->setMinimumSize(QSize(0, 0));
        pushButton_disable->setMaximumSize(QSize(30, 30));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Liberation Sans"));
        font6.setPointSize(18);
        font6.setBold(false);
        pushButton_disable->setFont(font6);
        pushButton_disable->setStyleSheet(QString::fromUtf8("color: \"red\";"));

        horizontalLayout_3->addWidget(pushButton_disable);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 760, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_add_aktionMngr->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_removeAktionMngr->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_moveUp->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        pushButton_moveDown->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        pushButton_enable->setText(QCoreApplication::translate("MainWindow", "\342\230\221", nullptr));
        pushButton_disable->setText(QCoreApplication::translate("MainWindow", "\342\226\241", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
