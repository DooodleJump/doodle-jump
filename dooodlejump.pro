#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T10:33:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dooodlejump
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Doodle.cpp \
    Enemy.cpp \
    Score.cpp \
    Board.cpp \
    Bullet.cpp

HEADERS  += \
    Game.h \
    Doodle.h \
    Enemy.h \
    Score.h \
    Board.h \
    Bullet.h

RESOURCES += \
    res.qrc
