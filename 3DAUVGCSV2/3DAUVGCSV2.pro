#-------------------------------------------------
#
# Project created by QtCreator 2021-01-14T11:12:39
#
#-------------------------------------------------

QT       += core gui network printsupport serialport webenginewidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DAUVGCS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    qmytableviewbtndelegate.cpp \
    mapchannel.cpp \
    taskwidget.cpp \
    waypoint.cpp \
    paramlist.cpp \
    common.cpp \
    datadelegate.cpp \
    tableview.cpp \
    tracerplus.cpp

HEADERS += \
        mainwindow.h \
    common.h \
    qcustomplot.h \
    qmytableviewbtndelegate.h \
    mapchannel.h \
    taskwidget.h \
    waypoint.h \
    paramlist.h \
    datadelegate.h \
    tableview.h \
    tracerplus.h

FORMS += \
        mainwindow.ui \
    taskwidget.ui \
    paramlist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/sdk/ -lquc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/sdk/ -lqucd
#LIBS += -L$$OUT_PWD/sdk/ -lqucd

INCLUDEPATH += $$PWD/sdk
DEPENDPATH += $$PWD/sdk

RESOURCES += \
    image.qrc

DISTFILES += \
    logo.rc
RC_FILE+=logo.rc



