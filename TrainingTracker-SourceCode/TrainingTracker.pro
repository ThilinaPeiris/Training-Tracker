#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T14:17:46
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainingTracker
TEMPLATE = app


SOURCES += main.cpp\
        signin.cpp \
    mainwindow.cpp \
    signup.cpp \
    newd.cpp \
    nemployee.cpp \
    ntraining.cpp \
    etedit.cpp \
    showe.cpp \
    showt.cpp

HEADERS  += signin.h \
    mainwindow.h \
    signup.h \
    newd.h \
    nemployee.h \
    ntraining.h \
    etedit.h \
    showe.h \
    showt.h

FORMS    += signin.ui \
    mainwindow.ui \
    signup.ui \
    newd.ui \
    nemployee.ui \
    ntraining.ui \
    etedit.ui \
    showe.ui \
    showt.ui

RESOURCES += \
    Resources.qrc
