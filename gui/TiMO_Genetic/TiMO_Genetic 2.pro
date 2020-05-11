QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 sdk_no_version_check -Wa,-mbig-obj app_bundle

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += inc\

SOURCES += \
    src/Math_Parser.cpp \
    src/NSGA.cpp \
    src/Population.cpp \
    src/VEGA.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/paretowindow.cpp \
    src/progresswindow.cpp \
    src/qcustomplot.cpp

HEADERS += \
    inc/Math_Parser.hpp \
    inc/NSGA.hpp \
    inc/Population.hpp \
    inc/Test_Functions.h \
    inc/VEGA.hpp \
    inc/exprtk.hpp \
    inc/mainwindow.h \ \
    inc/paretowindow.h \
    inc/progresswindow.h \
    inc/qcustomplot.h

FORMS += \
    ui/mainwindow.ui \
    ui/paretowindow.ui \
    ui/progresswindow.ui

RESOURCES += \
    icons.qrc
