#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include <QtTest>
#include "player.h"

class TestPlayer: public QObject {
    Q_OBJECT

public:
    TestPlayer();

private slots:
    void testInit();

};

#endif //TESTPLAYER_H
