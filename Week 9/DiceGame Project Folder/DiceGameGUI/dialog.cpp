#include "dialog.h"
#include <string>
#include <QString>
#include <iostream>
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)

{
    startButton = new QPushButton(tr("Start"));
    scoreBox    = new QLineEdit();
    text        = new QLabel(tr("Click button to Start"));

    for (int i = 0; i < 3; i++){
        dice[i] = new QPushButton(tr("?"));
    }



    //widgets
    QLabel* gameName  = new QLabel("Three Dice Poker");
    QLabel* scoreText = new QLabel("Score: ");
    QFont font = gameName->font();
    font.setPointSize(24);
    gameName->setFont(font);

    //layouts
    QHBoxLayout* hbox1 = new QHBoxLayout;
    hbox1->addWidget(gameName);
    hbox1->addSpacing(135);

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

    QVBoxLayout* vbox1 = new QVBoxLayout;
    vbox1->addLayout(hbox1);
    vbox1->addLayout(hbox2);
    vbox1->addLayout(hbox3);
    vbox1->addLayout(hbox4);

    setLayout(vbox1);


    setFixedSize(sizeHint());





    connect (startButton, SIGNAL (clicked()),
             this, SLOT(startClicked()));


    connect (dice[0], SIGNAL (clicked()),
             this, SLOT(rollFirstDie()));
    connect (dice[1], SIGNAL (clicked()),
             this, SLOT(rollSecondDie()));
    connect (dice[2], SIGNAL (clicked()),
             this, SLOT(rollThirdDie()));



}

void Dialog::startClicked(){
    pokerGame.rollAll();
    for (int i = 0; i < 3; i++){
    dice[i]->setText(QString::fromStdString(to_string(pokerGame.getDieValue(i+1))));
    }
    startButton->setText(QString::fromStdString("Reroll All!"));
    text->setText(QString::fromStdString("Click the button to reroll all or click die to reroll one"));
    scoreBox->setText(QString::fromStdString(to_string(pokerGame.getScore())));
}



void Dialog::rollFirstDie(){
    pokerGame.rollDie(1);
    dice[0]->setText(QString::fromStdString(to_string(pokerGame.getDieValue(1))));
    scoreBox->setText(QString::fromStdString(to_string(pokerGame.getScore())));
}

void Dialog::rollSecondDie(){
    pokerGame.rollDie(2);
    dice[1]->setText(QString::fromStdString(to_string(pokerGame.getDieValue(2))));
    scoreBox->setText(QString::fromStdString(to_string(pokerGame.getScore())));
}

void Dialog::rollThirdDie(){
    pokerGame.rollDie(3);
    dice[2]->setText(QString::fromStdString(to_string(pokerGame.getDieValue(3))));
    scoreBox->setText(QString::fromStdString(to_string(pokerGame.getScore())));
}










//scoreBox->setText(QString::fromStdString(to_string(pokerGame.getScore())));


