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

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " {ogg_file.ogg}\n";
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
    //Accessibility *accessibility = new Accessibility();
    //accessibility->setupUi(&w);
    //w.setAccessibilitySupport(accessibility);

	//------------------------------------
	w.show();

    qDebug() << QCursor::pos();

	return app.exec();
}
