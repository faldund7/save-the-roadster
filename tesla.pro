TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        clues.cpp \
        gameArena.cpp \
        initiateGame.cpp \
        main.cpp \
        muskMove.cpp \
        starmanMove.cpp

HEADERS += \
    clues.h \
    gameArena.h \
    initiateGame.h \
    muskMove.h \
    starmanMove.h
