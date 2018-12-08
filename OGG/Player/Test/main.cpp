#include "TestPlayer.h"
#include "TestMeta.h"
#include "TestAccessibility.h"
#include "TestSoundCTRL.h"
#include "TestSoundDevice.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TestPlayer testPlayer;
    TestMeta testMeta;
    TestAccessibility testAccessibility;
    TestSoundCTRL testSoundCTRL;
    TestSoundDevice testSoundDevice;

    return QTest::qExec(&testPlayer, argc, argv) |
           QTest::qExec(&testMeta, argc, argv) |
           QTest::qExec(&testAccessibility, argc, argv) |
           QTest::qExec(&testSoundCTRL, argc, argv) | 
           QTest::qExec(&testSoundDevice, argc, argv);
}
