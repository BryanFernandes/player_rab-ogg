#include "TestPlayer.h"

void TestPlayer::init()
{

}

void TestPlayer::test()
{
    QVERIFY2(&player != NULL, "check Player exist");
}

QTEST_MAIN(TestPlayer);
