QT       += core gui
QT       += sql
LIBS     += -lodbc32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delegate.cpp \
    error.cpp \
    ini_save.cpp \
    main.cpp \
    mainwindow.cpp \
    sql.cpp \
    tip.cpp \
    vscode.cpp

HEADERS += \
    const.h \
    delegate.h \
    error.h \
    ini_save.h \
    mainwindow.h \
    sql.h \
    tip.h \
    vscode.h

FORMS += \
    mainwindow.ui

RC_FILE += ./icon.rc

LIBS += -lole32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fakeCmd.ico \
    icon.rc
