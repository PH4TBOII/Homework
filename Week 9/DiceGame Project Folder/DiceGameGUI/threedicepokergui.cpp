#include "threedicepokergui.h"
using namespace std;

ThreeDicePokerGUI::ThreeDicePokerGUI(QObject *parent) : QObject(parent)
{
    startButton = new QPushButton(tr("Start"));
    scoreBox    = new QLineEdit(tr("Hello"));
    text        = new QLabel(tr("Press start to roll."));

    for (int i = 0; i < 3; i++){
        dice[i] = new QPushButton(tr("?"));
    }



    //widgets
    QLabel* gameName  = new QLabel("Three Dice Poker");
    QLabel* scoreText = new QLabel("Score: ");

    //layouts
    QHBoxLayout* hbox1 = new QHBoxLayout;
    hbox1->addWidget(gameName);
    hbox1->addStretch();

    QHBoxLayout* hbox2 = new QHBoxLayout;
    for (int i = 0; i < 3; i++){
        hbox2->addWidget(dice[i]);
        dice[i]->setMinimumSize(60,60);
        dice[i]->setMaximumSize(60,60);
    }

    QHBoxLayout* hbox3 = new QHBoxLayout;
    hbox3->addWidget(text);
    hbox3->addStretch();

    QHBoxLayout* hbox4 = new QHBoxLayout;
    hbox4->addWidget(startButton);
    hbox4->addStretch();
    hbox4->addWidget(scoreText);
    hbox4->addWidget(scoreBox);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(hbox1);
    mainLayout->addLayout(hbox2);
    mainLayout->addLayout(hbox3);
    mainLayout->addLayout(hbox4);

    setLayout(mainLayout);






























}












