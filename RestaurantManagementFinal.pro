QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cookstage.cpp \
    main.cpp \
    mainwindow.cpp \
    managerfunctionstage.cpp \
    managerstage.cpp \
    staffstage.cpp

HEADERS += \
    cookstage.h \
    mainwindow.h \
    managerfunctionstage.h \
    managerstage.h \
    staffstage.h

FORMS += \
    cookstage.ui \
    mainwindow.ui \
    managerfunctionstage.ui \
    managerstage.ui \
    staffstage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
