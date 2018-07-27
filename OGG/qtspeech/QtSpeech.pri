# QtSpeech -- a small cross-platform library to use TTS
# Copyright (C) 2010-2011 LynxLine.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General
# Public License along with this library; if not, write to the
# Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA

SPEECHSRCDIR = ../qtspeech

#DEPENDPATH += $$PWD
INCLUDEPATH += $$SPEECHSRCDIR

HEADERS += \
    $$SPEECHSRCDIR/QtSpeech \
    $$SPEECHSRCDIR/QtSpeech.h \

macx {
    SOURCES += $$SPEECHSRCDIR/QtSpeech_mac.cpp
#    LIBS *= -framework AppKit
}

win32 {
    HEADERS += $$SPEECHSRCDIR/sapi.hh $$SPEECHSRCDIR/sphelper.hh
    SOURCES += $$SPEECHSRCDIR/QtSpeech_win.cpp guids.c
    LIBS    += -lole32
}

unix:!mac {
    HEADERS += $$SPEECHSRCDIR/QtSpeech_unx.h
    SOURCES += $$SPEECHSRCDIR/QtSpeech_unx.cpp

    INCLUDEPATH += $$SPEECHSRCDIR/festival/speech_tools/include
    INCLUDEPATH += $$SPEECHSRCDIR/festival/festival/src/include
    INCLUDEPATH += /usr/include/festival
    INCLUDEPATH += /usr/include/speech_tools

    LIBS += -lncurses
    LIBS += -L$$SPEECHSRCDIR/festival/festival/src/lib -lFestival
    LIBS += -L$$SPEECHSRCDIR/festival/speech_tools/lib -lestools -lestbase -leststring

    # Linux: use asound 
    LIBS += -lasound
    
    # Mac: use system Frameworks
    #LIBS += -framework CoreAudio -framework AudioUnit -framework AudioToolbox -framework Carbon
}
