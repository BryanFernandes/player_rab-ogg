######################################################################
# Automatically generated by qmake (3.0) Wed Jan 31 15:17:45 2018
######################################################################

TEMPLATE = app
TARGET = Player
INCLUDEPATH += . ../core/include /usr/local/include
LIBS += -L../qtspeech -lQtSpeech -pthread -lvorbis -logg -lSDL -lSDL_mixer
#LIBS += -L../qtspeech -lQtSpeech -pthread -lvorbis -logg -lSDL -lSDL_mixer ../qtspeech/festival/festival/src/modules/Text/xxml.o ../qtspeech/festival/festival/src/modules/MultiSyn/*.o
QT += #CONFIG += c++11
QMAKE_CXXFLAGS += -std=gnu++0x
QMAKE_CFLAGS += -std=gnu++0x

include(../qtspeech/QtSpeech.pri)

# Input
HEADERS += accessibility.h \
           player.h \
           SDLMain.h \
           soundCTRL.h \
           sounddevice.h \
           ui_meta.h \
           ui_player.h \
           ../core/include/format.h \
           ../core/include/lgmk.h \
           ../core/include/lgmk_ogg.h \
           ../core/include/sound.h \
           ../core/include/wave.h \
           ../core/include/data.h \
           ../core/include/generic.h \
           ../core/include/chunkfactory.h \
           ../core/include/meta.h
FORMS += player.ui
SOURCES += accessibility.cpp \
           main.cpp \
           player.cpp \
           soundCTRL.cpp \
           sounddevice.cpp \
           ui_meta.cpp \
           ../core/format.cpp \
           ../core/lgmk.cpp \
           ../core/lgmk_ogg.cpp \
           ../core/sound.cpp \
           ../core/wave.cpp \
           ../core/data.cpp \
           ../core/generic.cpp \
           ../core/chunkfactory.cpp \
           ../core/meta.cpp
           
RESOURCES += resource.qrc

test { # following files will be included for unit test build
    message(Test build)

    QT += testlib #needed for QtTest
    SOURCES -= main.cpp

    HEADERS += \
        Test/TestPlayer.h \
        Test/UnitTest.h \

    SOURCES += \
        Test/main.cpp \
        Test/TestPlayer.cpp \
        Test/UnitTest.cpp \

} else {
    message(Normal build) #we will just show this message for DEbug/Release build
}