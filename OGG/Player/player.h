#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QShortcut>

#include "soundCTRL.h"

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

public:
	SoundCTRL *soundCTRL;
    
private:
    Ui::Player *ui;
 };

#endif // PLAYER_H
