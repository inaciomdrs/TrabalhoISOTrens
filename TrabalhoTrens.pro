#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T23:19:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoTrens
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trem.cpp \
    coordenada.cpp \
    semaforo.cpp \
    trilho.cpp

HEADERS  += mainwindow.h \
    trem.h \
    coordenada.h \
    semaforo.h \
    trilho.h

FORMS    += mainwindow.ui
