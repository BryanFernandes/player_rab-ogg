#include "TestPlayer.h"

void TestPlayer::initTestCase() {
    // This function is being executed at the beginning of each test suite
    // That is - before other tests from this class run
}

void TestPlayer::cleanupTestCase() {
    // Similary to initTestCase(), this function is executed at the end of test suite
}

void TestPlayer::init() {
    // This function is executed before each test
}

void TestPlayer::cleanup() {
    // This function is executed after each test
}

void TestPlayer::testSize() {
    QVERIFY2(player.size().isValid(), "Width and height windows is not equal to or greater than 0");
}

void TestPlayer::evilFunction() {
    Q_ASSERT("This functions is evil, so it shouldn't be ran");
}
