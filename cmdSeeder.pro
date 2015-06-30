#-------------------------------------------------
#
# Project created by QtCreator 2015-06-20T15:29:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cmdSeeder
TEMPLATE = app


SOURCES += main.cpp\
        cmdseeder.cpp \
    winsock_wrapper.cpp \
    templateparser.cpp

HEADERS  += cmdseeder.h \
    winsock_wrapper.h \
    templateparser.h

FORMS    += cmdseeder.ui

RESOURCES += \
    icons.qrc \
    templates.qrc

DISTFILES +=

CONFIG += c++11
LIBS += -lws2_32