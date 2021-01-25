#-------------------------------------------------
#
# Project created by QtCreator 2021-01-11T15:18:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    HAT_AD_cType.h \
    HAT_AD_pcpt_interface.h

FORMS    += widget.ui
CONFIG   +=C++11
