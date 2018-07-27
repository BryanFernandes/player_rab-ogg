#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QShortcut>

#include "soundCTRL.h"
#include "accessibility.h"

namespace Ui {
class Player;
}

class Player : public QMainWindow
{
    Q_OBJECT

        public:
    explicit Player(QWidget *parent = 0);
    ~Player();
    void setControl(SoundCTRL *control);
    void setAccessibilitySupport(Accessibility *accessibility);
public:
	SoundCTRL *soundCTRL;
    Accessibility *accessibilitySupport;

private:
    Ui::Player *ui;
 };

#endif // PLAYER_H
