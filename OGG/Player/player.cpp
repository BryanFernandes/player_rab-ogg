#include "player.h"
#include "ui_player.h"

Player::Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);

    cerr << endl << "Usando prints para marcar entrada e saida dos metodos abaixo:" << endl;
	cerr << "\t* ui_meta.cpp -> Ui_meta" << endl;
	cerr << "\t* ui_meta.cpp -> playOrPause" << endl;
	cerr << "\t* sounddevice.cpp -> open" << endl;
	cerr << "\t* sounddevice.cpp -> openWAV" << endl;
	cerr << "\t* sounddevice.cpp -> audioConverter" << endl;
	cerr << "\t* sounddevice.cpp -> setSound" << endl;
	cerr << "\t* soundCTRL.cpp -> playOrPauseCTRL" << endl << endl;
	cerr << "debugging now..." << endl << endl;
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

    QKeySequence kH(Qt::Key_H);
    QShortcut *scH = new QShortcut(kH, this);
    connect(scH, SIGNAL(activated()), control->view, SLOT(openHelperWindow()) );


    //QKeySequence kC(Qt::Key_C);
    //QShortcut *scC = new QShortcut(kC, this);
    //connect(scC, SIGNAL(activated()), control, SLOT(toggleContrast()) );
}

void
Player::setAccessibilitySupport(Accessibility *accessibility)
{
    this->accessibilitySupport = accessibility;

    QKeySequence kC(Qt::Key_C);
    QShortcut *scC = new QShortcut(kC, this);
    connect(scC, SIGNAL(activated()), accessibility, SLOT(screenContrast()) );
}

Player::~Player()
{
    delete ui;
}
