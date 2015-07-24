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
    templateparser.cpp \
    label.cpp \
    templateprinter.cpp

HEADERS  += cmdseeder.h \
    winsock_wrapper.h \
    templateparser.h \
    label.h \
    templateprinter.h

FORMS    += cmdseeder.ui \
    templateprinter.ui

RESOURCES += \
    icons.qrc \
    templates.qrc

DISTFILES +=

CONFIG += c++11
CONFIG += static
LIBS += -lws2_32
LIBS += -lQt5Core

static { # everything below takes effect with CONFIG ''= static
 CONFIG+= static
 CONFIG += staticlib # this is needed if you create a static library, not a static executable
 DEFINES+= STATIC
 message("~~~ static build ~~~") # this is for information, that the static build is done
 mac: TARGET = $$join(TARGET,,,_static) #this adds an _static in the end, so you can seperate static build from non static build
 win32: TARGET = $$join(TARGET,,,s) #this adds an s in the end, so you can seperate static build from non static build
}

# change the name of the binary, if it is build in debug mode
CONFIG (debug, debug|release) {
 mac: TARGET = $$join(TARGET,,,_debug)
 win32: TARGET = $$join(TARGET,,,d)
}
