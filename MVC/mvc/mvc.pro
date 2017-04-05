#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T10:26:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mvc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    event/switch_widget_event.cpp \
    switch_widget.cpp \
    controller/switch_processer.cpp \
    model/state_model.cpp

HEADERS  += mainwindow.h \
    event/switch_widget_event.h \
    switch_widget.h \
    controller/switch_processer.h \
    model/state_model.h

FORMS    += mainwindow.ui \
    switch_widget.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../../CHANGELOG.txt
