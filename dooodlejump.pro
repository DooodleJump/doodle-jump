#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T10:33:15
#
#-------------------------------------------------

QT       += core gui \
         multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dooodlejump
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Doodle.cpp \
    Enemy.cpp \
    Score.cpp \
    Board.cpp \
    Bullet.cpp \
    Award.cpp \
    Umbrella.cpp \
    Spring.cpp \
    Springboard.cpp \
    Brownboard.cpp \
    Blueboard.cpp \
    Bluemon.cpp \
    Fly.cpp \
    Missile.cpp \
    Button.cpp

HEADERS  += \
    Game.h \
    Doodle.h \
    Enemy.h \
    Score.h \
    Board.h \
    Bullet.h \
    Award.h \
    Umbrella.h \
    Missile.h \
    Spring.h \
    Springboard.h \
    Brownboard.h \
    Blueboard.h \
    Bluemon.h \
    Fly.h \
    Button.h

RESOURCES += \
    res.qrc \
    res.qrc

OTHER_FILES += \
    readme.txt
