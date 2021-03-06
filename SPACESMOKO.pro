QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Asteroid.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Hard_Enemy.cpp \
    Health.cpp \
    Medium_Enemy.cpp \
    Megaleg.cpp \
    Menu.cpp \
    Player.cpp \
    Score.cpp \
    main.cpp

HEADERS += \
    Asteroid.h \
    Bullet.h \
    Enemy.h \
    Game.h \
    Hard_Enemy.h \
    Health.h \
    Medium_Enemy.h \
    Megaleg.h \
    Menu.h \
    Player.h \
    Score.h

FORMS +=

TRANSLATIONS += \
    SPACESMOKO_en_US.ts

# Default rules for deployment.
qnx: target.path = /Users/devinmurray/Desktop/$${TARGET}
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
