#ifndef THREEDICEPOKER_H
#define THREEDICEPOKER_H
#include "Die.h"



class ThreeDicePoker {
private:

    Die dice[3];

public:

    //constructor
    ThreeDicePoker();

    //functions
    int  getDieValue(int dieNumber);
    int  getScore();
    void rollDie(int number);
    void rollAll();
    void setDie(int dieNumber, int value);

};


#endif // THREEDICEPOKER_H
