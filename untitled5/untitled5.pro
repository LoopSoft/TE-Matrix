#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T17:16:57
#
#-------------------------------------------------

QT       += core gui
QT       += widgets printsupport
QT       += quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



TARGET = untitled5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    matrixinterface.cpp \
    splash.cpp \
    sobre.cpp

HEADERS  += mainwindow.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    SistemasdeControle/headers/graphicLibs/plot.h \
    SistemasdeControle/src/graphicLibs/plot.hpp \
    qcustomplot.h \
    matrixinterface.h \
    splash.h \
    sobre.h

FORMS    += mainwindow.ui \
    splash.ui \
    sobre.ui

include(QtAdMob/QtAdMob.pri)

QTADMOB_LIB_DIR = $$PWD/QtAdMob

android:
{
    ANDROID_PACKAGE_SOURCE_DIR = $$QTADMOB_LIB_DIR/platform/android
    android:QT += androidextras gui-private
    android:DISTFILES += \
            $$ANDROID_PACKAGE_SOURCE_DIR/AndroidManifest.xml \
            $$ANDROID_PACKAGE_SOURCE_DIR/project.properties \
            $$ANDROID_PACKAGE_SOURCE_DIR/src/org/dreamdev/QtAdMob/QtAdMobActivity.java
}

ios:
{
    IOS_PACKAGE_SOURCE_DIR = $$PWD/platform/ios
    ios:QMAKE_INFO_PLIST = $$IOS_PACKAGE_SOURCE_DIR/Info.plist
}

DISTFILES += \
    SubWindow.qml

RESOURCES += \
    res.qrc
