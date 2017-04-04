#include "Accessibility.h"

Accessibility::Accessibility()
{
	defaultContrast = 1;
}

void 
Accessibility::screenContrast()
{
    QMainWindow * win = (QMainWindow *) qApp->activeWindow();

    cout << "screenContrast" << endl;

    if(defaultContrast == 1)
    {
        defaultContrast--;
	        
        win->setStyleSheet("background-color:black;");
        playOrPauseButton->setStyleSheet("border:1px solid #ffffff;");
        fastrewindButton->setStyleSheet("border:1px solid #ffffff;");
        rewindButton->setStyleSheet("border:1px solid #ffffff;");
        playOrPauseButton->setStyleSheet("border:1px solid #ffffff;");
        forwardButton->setStyleSheet("border:1px solid #ffffff;");
        fastforwardButton->setStyleSheet("border:1px solid #ffffff;");
        upLevelButton->setStyleSheet("border:1px solid #ffffff;");
        downLevelButton->setStyleSheet("border:1px solid #ffffff;");
        
        levelLabel->setStyleSheet("color:yellow;");
        staticPublisherLabel->setStyleSheet("color:yellow;");
        titleLabel->setStyleSheet("color:yellow;");
        authorLabel->setStyleSheet("color:yellow;");
        addressLabel->setStyleSheet("color:yellow;");
        staticAutorLabel->setStyleSheet("color:yellow;");
        staticPagesLabel->setStyleSheet("color:yellow;");
        yearLabel->setStyleSheet("color:yellow;");
        pagesLabel->setStyleSheet("color:yellow;");
        staticLanguageLabel->setStyleSheet("color:yellow;");
        staticTitleLabel->setStyleSheet("color:yellow;");
        languageLabel->setStyleSheet("color:yellow;");
        publisherLabel->setStyleSheet("color:yellow;");
        staticAddressLabel->setStyleSheet("color:yellow;");
        staticYearLabel->setStyleSheet("color:yellow;");
        markLabel->setStyleSheet("color:yellow;");
        subMarkLabel->setStyleSheet("color:yellow;");  
        
       // songSlider->setStyleSheet("background-color:yellow;");
        lcdNumber->setStyleSheet("color:yellow;");
    } else {

        defaultContrast++;

        win->setStyleSheet("background-color:white;");
        fastrewindButton->setStyleSheet("border:1px solid #000000;");
        rewindButton->setStyleSheet("border:1px solid #000000;");
        playOrPauseButton->setStyleSheet("border:1px solid #000000;");
        forwardButton->setStyleSheet("border:1px solid #000000;");
        fastforwardButton->setStyleSheet("border:1px solid #000000;");
        upLevelButton->setStyleSheet("border:1px solid #000000;");
        downLevelButton->setStyleSheet("border:1px solid #000000;");

        levelLabel->setStyleSheet("color:black;");
        staticPublisherLabel->setStyleSheet("color:black;");
        titleLabel->setStyleSheet("color:black;");
        authorLabel->setStyleSheet("color:black;");
        addressLabel->setStyleSheet("color:black;");
        staticAutorLabel->setStyleSheet("color:black;");
        staticPagesLabel->setStyleSheet("color:black;");
        yearLabel->setStyleSheet("color:black;");
        pagesLabel->setStyleSheet("color:black;");
        staticLanguageLabel->setStyleSheet("color:black;");
        staticTitleLabel->setStyleSheet("color:black;");
        languageLabel->setStyleSheet("color:black;");
        publisherLabel->setStyleSheet("color:black;");
        staticAddressLabel->setStyleSheet("color:black;");
        staticYearLabel->setStyleSheet("color:black;");
        markLabel->setStyleSheet("color:black;");
        subMarkLabel->setStyleSheet("color:black;");
    }
}




