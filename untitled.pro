#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T19:24:56
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += bluetooth
QT       += sensors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    configwindow.cpp \
    controlwindow.cpp \
    smartcarhelper.cpp \
    settingwindow.cpp \
    aboutwindow.cpp \
    bluetoothhandle.cpp \
    zhandle.cpp

HEADERS += \
        mainwindow.h \
    configwindow.h \
    controlwindow.h \
    smartcarhelper.h \
    settingwindow.h \
    aboutwindow.h \
    bluetoothhandle.h \
    zhandle.h

FORMS += \
        mainwindow.ui \
    configwindow.ui \
    controlwindow.ui \
    smartcarhelper.ui \
    settingwindow.ui \
    aboutwindow.ui

CONFIG += mobility
MOBILITY = 

