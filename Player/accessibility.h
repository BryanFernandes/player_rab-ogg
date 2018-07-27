#ifndef ACCESSIBILITY_H
#define ACCESSIBILITY_H

#include <QObject>
#include <QIcon>
#include <QPushButton>
#include <QtSpeech>
#include <iostream>

#include "ui_player.h"

using namespace std;

class Accessibility : public QObject, public Ui_Player
{
	 Q_OBJECT
	 
public slots:
	
    void screenContrast();
		
signals:
	
public:
	Accessibility();
	
public:
	int defaultContrast;
	
private:
	
};


#endif
