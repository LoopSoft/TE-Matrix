#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T17:16:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += widgets printsupport

TARGET = untitled5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    matrixinterface.cpp

HEADERS  += mainwindow.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    SistemasdeControle/headers/graphicLibs/plot.h \
    SistemasdeControle/src/graphicLibs/plot.hpp \
    qcustomplot.h \
    matrixinterface.h

FORMS    += mainwindow.ui
