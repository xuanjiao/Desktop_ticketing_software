#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T21:21:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += widgets
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ticketProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasedialog.cpp \
    databasesetting.cpp \
    usersettingdialog.cpp \
    user.cpp \
    serialportsettingdialog.cpp \
    docdialog.cpp

HEADERS  += mainwindow.h \
    databasedialog.h \
    databasesetting.h \
    usersettingdialog.h \
    user.h \
    serialportsettingdialog.h \
    docdialog.h

FORMS    += mainwindow.ui \
    databasedialog.ui \
    usersettingdialog.ui \
    serialportsettingdialog.ui \
    docdialog.ui

OTHER_FILES +=

RESOURCES += \
    resources.qrc

RC_ICONS = "logo\winIcon.ico"
