######################################################################
# Automatically generated by qmake (2.01a) sex nov 22 22:12:57 2013
######################################################################
TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . ../core/include /Library/Frameworks/SDL.framework/Headers
LIBS += -L../core -lcore -framework Cocoa -framework SDL -framework QtGui -logg -lvorbis -lvorbisenc -lvorbisfile

# Input
OBJECTIVE_SOURCES += SDLMain.m
HEADERS += player.h soundCTRL.h sounddevice.h ui_meta.h SDLMain.h
FORMS += player.ui
SOURCES += main.cpp player.cpp soundCTRL.cpp sounddevice.cpp ui_meta.cpp
RESOURCES += resource.qrc
