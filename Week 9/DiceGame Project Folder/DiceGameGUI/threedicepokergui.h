#ifndef THREEDICEPOKERGUI_H
#define THREEDICEPOKERGUI_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class ThreeDicePokerGUI : public QObject
{
    Q_OBJECT
public:
    explicit ThreeDicePokerGUI(QObject *parent = 0);

private:
    QPushButton*    dice[3]; //set to setMaximumSize(60,60) / setMinimumSize(60,60)
    QPushButton*    startButton;
    QLineEdit*      scoreBox;
    QLabel*         text;


signals:

public slots:





};

#endif // THREEDICEPOKERGUI_H
