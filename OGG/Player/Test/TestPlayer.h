#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include <QtTest>
#include "player.h"

class TestPlayer: public QObject {
    
    Q_OBJECT

private slots:
    void init();

    void test();
};

#endif //TESTPLAYER_H
