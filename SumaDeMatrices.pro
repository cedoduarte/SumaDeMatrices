#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T20:36:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SumaDeMatrices
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    NumeroRealSpinBoxDelegate.cpp \
    IntroducirOrdenDeMatricesDialog.cpp

HEADERS  += Widget.h \
    NumeroRealSpinBoxDelegate.h \
    IntroducirOrdenDeMatricesDialog.h

FORMS    += Widget.ui \
    IntroducirOrdenDeMatricesDialog.ui

QMAKE_CXXFLAGS += -std=gnu++14
