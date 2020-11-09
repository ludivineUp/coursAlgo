#-------------------------------------------------
#
# Project created by QtCreator 2012-11-20T16:50:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demineur
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plateau.cpp \
    plateausender.cpp \
    buttondemineur.cpp

HEADERS  += mainwindow.h \
    plateau.h \
    plateausender.h \
    buttondemineur.h

FORMS    += mainwindow.ui
