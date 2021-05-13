QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 -static-libstdc++ -static-libgcc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aktionmngr.cpp \
    aktionselektdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    mytypes.cpp \
    pimanager.cpp \
    storagemngr.cpp \
    windowmanager.cpp

HEADERS += \
    aktionmngr.h \
    aktionselektdialog.h \
    mainwindow.h \
    mytypes.h \
    pimanager.h \
    storagemngr.h \
    windowmanager.h

FORMS += \
    aktionmngr.ui \
    aktionselektdialog.ui \
    mainwindow.ui


LIBS += -lws2_32
INCLUDEPATH  += D:\Qt-Projekte\Qt\TCP_LIB_CLIENT_V2/
HEADERS      += D:\Qt-Projekte\Qt\TCP_LIB_CLIENT_V2/my_tcp_lib.h
SOURCES      += D:\Qt-Projekte\Qt\TCP_LIB_CLIENT_V2/my_tcp_lib.cpp



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
