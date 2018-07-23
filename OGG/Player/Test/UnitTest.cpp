#include "UnitTest.h"

UnitTest::UnitTest()
{

}

void UnitTest::run()
{
    TestPlayer testPlayer;
    QTest::qExec(&testPlayer);
}
