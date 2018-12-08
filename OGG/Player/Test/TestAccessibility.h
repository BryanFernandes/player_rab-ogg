#ifndef TESTACCESSIBILITY_H
#define TESTACCESSIBILITY_H

#include <QtTest>
#include "accessibility.h"

class TestAccessibility: public QObject {
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
    void test();

private:
    Accessibility *accessibility;
};

#endif //TESTACCESSIBILITY_H
