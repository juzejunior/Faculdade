#-------------------------------------------------
#
# Project created by QtCreator 2016-11-12T12:42:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dijsktra
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graph.cpp \
    street.cpp

HEADERS  += mainwindow.h \
    graph.h \
    street.h

FORMS    += mainwindow.ui
