#ifndef DIALOG_H
#define DIALOG_H
#include "ThreeDicePoker.h"
#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>


class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);

private:
    ThreeDicePoker  pokerGame;
    QPushButton*    dice[3];
    QPushButton*    startButton;
    QLineEdit*      scoreBox;
    QLabel*         text;


signals:


public slots:
    void startClicked();
    void rollFirstDie();
    void rollSecondDie();
    void rollThirdDie();




};

#endif // DIALOG_H
