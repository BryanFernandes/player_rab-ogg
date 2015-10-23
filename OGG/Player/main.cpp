#include <iostream>
#include <thread>

#include <SDL/SDL.h>
#include <QApplication>
#include <QtSpeech>
#include <QCursor>
#include <QtCore>

#include "sounddevice.h"
//#include "sound.h"
#include "player.h"
#include "ui_meta.h"

using namespace std;

void asyn_speech(QString msg)
{
    QtSpeech speech;
    speech.say(msg);
}

void test()
{
    cerr << "first speech";
    QtSpeech speech;
    speech.say("Testing Player with speech");
}

void test2()
{
    cerr << "second speech";
    QtSpeech speech;
    speech.say("Now, I believe I can fly");
}

int SDL_main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " {rab_file.rab}\n";
		return -1;
	}
	
	char *path = argv[1];

	QApplication app(argc, argv);
	Player w;
	w.setFixedSize(w.size());
	
	 Ui_meta *uim = new Ui_meta(path);
	 uim->setupUi(&w);
	 uim->setMetaLabels(path);
	 uim->setMarksLabels();
	 uim->initLCDDisplay();
	 uim->initSlider();
	 uim->connections();
     uim->setEventFilter();

	//----------------------------------------------------
	SoundCTRL *control = new SoundCTRL();
	control->setView(uim);

	Sound *sound = new Sound;
	SoundDevice *device = new SoundDevice;
	
	device->open(sound);
	uim->setFormat( device->openWAV(path) );
	device->audioConverter();
	device->setSound(sound);
	
	control->setSound(sound);

	//------------------------------------
	w.setControl(control);

	//------------------------------------
	w.show();

    qDebug() << QCursor::pos();

    //QtSpeech s;
    //s.tell("Running  speech no use thread");

    //thread t1(asyn_speech, "Testing Player with speech");
    //thread t2(asyn_speech, "Now, I believe I can fly");

    //t1.join();
    //t2.join();
    
    //thread t1(test);
    //thread t2(test2);
    //t1.join();
    //t2.join();

	return app.exec();
}
