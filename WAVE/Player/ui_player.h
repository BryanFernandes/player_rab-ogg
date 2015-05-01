/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionSave_As_2;
    QAction *actionRecent_Files;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionThis_Player;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *staticTitleLabel;
    QLabel *titleLabel;
    QLabel *staticAutorLabel;
    QLabel *authorLabel;
    QLabel *staticLanguageLabel;
    QLabel *languageLabel;
    QLabel *staticPublisherLabel;
    QLabel *publisherLabel;
    QLabel *staticAddressLabel;
    QLabel *addressLabel;
    QLabel *staticPagesLabel;
    QLabel *pagesLabel;
    QLabel *staticYearLabel;
    QLabel *yearLabel;
    QLabel *levelLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *fastrewindButton;
    QPushButton *rewindButton;
    QPushButton *playOrPauseButton;
    QPushButton *forwardButton;
    QPushButton *fastforwardButton;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *upLevelButton;
    QPushButton *downLevelButton;
    QLabel *markLabel;
    QLabel *subMarkLabel;
    QGridLayout *gridLayout;
    QSlider *songSlider;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Player)
    {
        if (Player->objectName().isEmpty())
            Player->setObjectName(QString::fromUtf8("Player"));
        Player->resize(428, 445);
        actionOpen = new QAction(Player);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(Player);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(Player);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_As_2 = new QAction(Player);
        actionSave_As_2->setObjectName(QString::fromUtf8("actionSave_As_2"));
        actionRecent_Files = new QAction(Player);
        actionRecent_Files->setObjectName(QString::fromUtf8("actionRecent_Files"));
        actionCopy = new QAction(Player);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(Player);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionThis_Player = new QAction(Player);
        actionThis_Player->setObjectName(QString::fromUtf8("actionThis_Player"));
        centralWidget = new QWidget(Player);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        staticTitleLabel = new QLabel(centralWidget);
        staticTitleLabel->setObjectName(QString::fromUtf8("staticTitleLabel"));
        staticTitleLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, staticTitleLabel);

        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, titleLabel);

        staticAutorLabel = new QLabel(centralWidget);
        staticAutorLabel->setObjectName(QString::fromUtf8("staticAutorLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, staticAutorLabel);

        authorLabel = new QLabel(centralWidget);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, authorLabel);

        staticLanguageLabel = new QLabel(centralWidget);
        staticLanguageLabel->setObjectName(QString::fromUtf8("staticLanguageLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, staticLanguageLabel);

        languageLabel = new QLabel(centralWidget);
        languageLabel->setObjectName(QString::fromUtf8("languageLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, languageLabel);

        staticPublisherLabel = new QLabel(centralWidget);
        staticPublisherLabel->setObjectName(QString::fromUtf8("staticPublisherLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, staticPublisherLabel);

        publisherLabel = new QLabel(centralWidget);
        publisherLabel->setObjectName(QString::fromUtf8("publisherLabel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, publisherLabel);

        staticAddressLabel = new QLabel(centralWidget);
        staticAddressLabel->setObjectName(QString::fromUtf8("staticAddressLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, staticAddressLabel);

        addressLabel = new QLabel(centralWidget);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        formLayout->setWidget(4, QFormLayout::FieldRole, addressLabel);

        staticPagesLabel = new QLabel(centralWidget);
        staticPagesLabel->setObjectName(QString::fromUtf8("staticPagesLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, staticPagesLabel);

        pagesLabel = new QLabel(centralWidget);
        pagesLabel->setObjectName(QString::fromUtf8("pagesLabel"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pagesLabel);

        staticYearLabel = new QLabel(centralWidget);
        staticYearLabel->setObjectName(QString::fromUtf8("staticYearLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, staticYearLabel);

        yearLabel = new QLabel(centralWidget);
        yearLabel->setObjectName(QString::fromUtf8("yearLabel"));

        formLayout->setWidget(6, QFormLayout::FieldRole, yearLabel);


        verticalLayout->addLayout(formLayout);

        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));

        verticalLayout->addWidget(levelLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fastrewindButton = new QPushButton(centralWidget);
        fastrewindButton->setObjectName(QString::fromUtf8("fastrewindButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/seek-backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        fastrewindButton->setIcon(icon);
        fastrewindButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(fastrewindButton);

        rewindButton = new QPushButton(centralWidget);
        rewindButton->setObjectName(QString::fromUtf8("rewindButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        rewindButton->setIcon(icon1);
        rewindButton->setIconSize(QSize(46, 46));

        horizontalLayout->addWidget(rewindButton);

        playOrPauseButton = new QPushButton(centralWidget);
        playOrPauseButton->setObjectName(QString::fromUtf8("playOrPauseButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        playOrPauseButton->setIcon(icon2);
        playOrPauseButton->setIconSize(QSize(69, 69));

        horizontalLayout->addWidget(playOrPauseButton);

        forwardButton = new QPushButton(centralWidget);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon3);
        forwardButton->setIconSize(QSize(46, 46));

        horizontalLayout->addWidget(forwardButton);

        fastforwardButton = new QPushButton(centralWidget);
        fastforwardButton->setObjectName(QString::fromUtf8("fastforwardButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/seek-forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        fastforwardButton->setIcon(icon4);
        fastforwardButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(fastforwardButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        upLevelButton = new QPushButton(centralWidget);
        upLevelButton->setObjectName(QString::fromUtf8("upLevelButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upLevelButton->setIcon(icon5);

        horizontalLayout_2->addWidget(upLevelButton);

        downLevelButton = new QPushButton(centralWidget);
        downLevelButton->setObjectName(QString::fromUtf8("downLevelButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        downLevelButton->setIcon(icon6);

        horizontalLayout_2->addWidget(downLevelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        markLabel = new QLabel(centralWidget);
        markLabel->setObjectName(QString::fromUtf8("markLabel"));

        verticalLayout_2->addWidget(markLabel);

        subMarkLabel = new QLabel(centralWidget);
        subMarkLabel->setObjectName(QString::fromUtf8("subMarkLabel"));

        verticalLayout_2->addWidget(subMarkLabel);


        verticalLayout->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        songSlider = new QSlider(centralWidget);
        songSlider->setObjectName(QString::fromUtf8("songSlider"));
        songSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(songSlider, 0, 2, 1, 1);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        Player->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Player);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 428, 20));
        Player->setMenuBar(menuBar);
        statusBar = new QStatusBar(Player);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Player->setStatusBar(statusBar);
        toolBar = new QToolBar(Player);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Player->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Player);

        QMetaObject::connectSlotsByName(Player);
    } // setupUi

    void retranslateUi(QMainWindow *Player)
    {
        Player->setWindowTitle(QApplication::translate("Player", "Player", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("Player", "Open File", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("Player", "Close", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("Player", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As_2->setText(QApplication::translate("Player", "Save As...", 0, QApplication::UnicodeUTF8));
        actionRecent_Files->setText(QApplication::translate("Player", "Recent Files", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("Player", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("Player", "Paste", 0, QApplication::UnicodeUTF8));
        actionThis_Player->setText(QApplication::translate("Player", "This Player", 0, QApplication::UnicodeUTF8));
        staticTitleLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">Title:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("Player", "<html><head/><body><p>TitleLabel</p></body></html>", 0, QApplication::UnicodeUTF8));
        staticAutorLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Author:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        authorLabel->setText(QApplication::translate("Player", "AuthorLabel", 0, QApplication::UnicodeUTF8));
        staticLanguageLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Language:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        languageLabel->setText(QApplication::translate("Player", "LanguageLabel", 0, QApplication::UnicodeUTF8));
        staticPublisherLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Publisher:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        publisherLabel->setText(QApplication::translate("Player", "PublisherLabel", 0, QApplication::UnicodeUTF8));
        staticAddressLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Address:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        addressLabel->setText(QApplication::translate("Player", "AddressLabel", 0, QApplication::UnicodeUTF8));
        staticPagesLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Pages:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pagesLabel->setText(QApplication::translate("Player", "PagesLabel", 0, QApplication::UnicodeUTF8));
        staticYearLabel->setText(QApplication::translate("Player", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Year:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        yearLabel->setText(QApplication::translate("Player", "YearLabel", 0, QApplication::UnicodeUTF8));
        levelLabel->setText(QApplication::translate("Player", "<html><head/><body><p align=\"center\">Level</p></body></html>", 0, QApplication::UnicodeUTF8));
        fastrewindButton->setText(QString());
        rewindButton->setText(QString());
        playOrPauseButton->setText(QString());
        forwardButton->setText(QString());
        fastforwardButton->setText(QString());
        upLevelButton->setText(QString());
        downLevelButton->setText(QString());
        markLabel->setText(QApplication::translate("Player", "<html><head/><body><p align=\"center\">Mark</p></body></html>", 0, QApplication::UnicodeUTF8));
        subMarkLabel->setText(QApplication::translate("Player", "<html><head/><body><p align=\"center\">SubMark</p></body></html>", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Player", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Player: public Ui_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
