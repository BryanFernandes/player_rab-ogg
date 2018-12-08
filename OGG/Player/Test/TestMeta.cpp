#include "TestMeta.h"

void TestMeta::initTestCase() {
    // This function is being executed at the beginning of each test suite
    // That is - before other tests from this class run
    uim = new Ui_meta("violin.ogg");
}

void TestMeta::cleanupTestCase() {
    // Similary to initTestCase(), this function is executed at the end of test suite
}

void TestMeta::init() {
    // This function is executed before each test
}

void TestMeta::cleanup() {
    // This function is executed after each test
}

void TestMeta::test() {
    Q_ASSERT("Create tests");
}

    
