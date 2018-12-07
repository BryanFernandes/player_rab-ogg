#include "UnitTest.h"

void UnitTest::run()
{
    TestPlayer testPlayer;
    QTest::qExec(&testPlayer);
}
