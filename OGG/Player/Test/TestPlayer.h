#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include <QtTest>
#include "player.h"

class TestPlayer: public QObject {
    
    Q_OBJECT

private slots:
    // functions executed by QtTest before and after test suite
    void initTestCase();
    void cleanupTestCase();

    // functions executed by QtTest before and after each test
    void init();
    void cleanup();

    // test functions - all functions prefixed with "test" will be ran as tests
    // this is automatically detected thanks to Qt's meta-information about QObjetcs
    void testSize();

    // this function is not prefixed with "test", so it won't b ran as one
    void evilFunction();

private:
    Player player;
};

#endif //TESTPLAYER_H
