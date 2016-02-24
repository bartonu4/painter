#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T23:51:00
#
#-------------------------------------------------

QT       += core gui xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = kursova_oop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    handler.cpp \
    shape.cpp \
    scene.cpp \
    zigzag.cpp \
    sector.cpp

HEADERS  += mainwindow.h \
    handler.h \
    shape.h \
    scene.h \
    zigzag.h \
    sector.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    images/zig.jpg \
    images/sendtoback.png \
    images/sec.png \
    images/pointer.png \
    images/linecolor.png \
    images/floodfill.png \
    images/flip.png \
    images/ellipse.png \
    images/delete.png \
    images/bringtofront.png \
    images/line3.png \
    images/line2.png \
    images/line1.png \
    images/flipV.png \
    images/flipH.png

RESOURCES += \
    images.qrc
