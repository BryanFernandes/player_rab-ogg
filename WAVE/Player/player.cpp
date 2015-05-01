#include "player.h"
#include "ui_player.h"

Player::Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
}

void
Player::setControl(SoundCTRL *control)
{
	this->soundCTRL = control;

	QKeySequence kSpace(Qt::Key_Space);
	QShortcut *scSpace = new QShortcut(kSpace, this);
	connect(scSpace, SIGNAL(activated()), control, SLOT(playOrPauseCTRL()) );

	QKeySequence kLeft(Qt::Key_Left);
	QShortcut *scLeft = new QShortcut(kLeft, this);
	connect(scLeft, SIGNAL(activated()), control->view, SLOT(prev()) );

	QKeySequence kRight(Qt::Key_Right);
	QShortcut *scRight = new QShortcut(kRight, this);
	connect(scRight, SIGNAL(activated()), control->view, SLOT(next()) );

	QKeySequence kUp(Qt::Key_Up);
	QShortcut *scUp = new QShortcut(kUp, this);
	connect(scUp, SIGNAL(activated()), control->view, SLOT(levelUp()) );	

	QKeySequence kDown(Qt::Key_Down);
	QShortcut *scDown = new QShortcut(kDown, this);
	connect(scDown, SIGNAL(activated()), control->view, SLOT(levelDown()) );
}

Player::~Player()
{
    delete ui;
}
