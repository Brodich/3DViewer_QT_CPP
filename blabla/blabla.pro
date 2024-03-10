QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    front/main.cpp \
    front/glwidget.cpp \
    back/affine.c \
    back/parser.c \
    front/mainwindow.cpp


HEADERS += \
    front/glwidget.h \
    back/parser.h \
    front/mainwindow.h

FORMS += \
    front/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_SPEC_T = $$[QMAKE_SPEC]
contains(QMAKE_SPEC_T,.*win32.*){
    IS_WINDOWS = 1
}
contains(QMAKE_SPEC_T,.*macx.*){
    IS_MACOS = 1
}
contains(QMAKE_SPEC_T,.*linux.*){
    IS_LINUX = 1
}
#and then anywhere to check:

!isEmpty(IS_WINDOWS): LIBS += -lOpenGL32
!isEmpty(IS_LINUX): LIBS += -lGL
