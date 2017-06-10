#include "ThreeDicePoker.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
using std::sort;





//constructor
ThreeDicePoker::ThreeDicePoker(){
    srand ((unsigned)time(0));
}

//functions
int   ThreeDicePoker::getDieValue(int dieNumber){
    return dice[dieNumber-1].getValue();
}



int   ThreeDicePoker::getScore(){  //finish me!!!!!!!!!!!!!!!!!
    int   tempDice[3];

    for (int i = 0; i < 3; i++){
        tempDice[i] = this->dice[i].getValue();
    }
    sort(tempDice,tempDice + 3);

    int similarities = 0;
    int similarityIndex;
    for (int i = 1; i < 3; i++){
        if (tempDice[i] == tempDice[i-1]){
            similarities += 1;
            similarityIndex = i;
        }
    }
    if (similarities == 1)
        return (tempDice[similarityIndex] * 40);
    else if (similarities == 2)
        return (1000);
    else if (tempDice[0]+1 == tempDice[1] && tempDice[1]+1 == tempDice[2])
        return (400);
    else{
        int highest = 0;
        for (int i = 0 ; i < 3 ; i++){
            if (tempDice[i] > highest)
                highest = tempDice[i];
        }
        return (highest * 10);
    }}

void  ThreeDicePoker::rollDie(int number){
    this->dice[number-1].roll();
}
void  ThreeDicePoker::rollAll(){
    for (int i = 0; i < 3; i++){
        this->rollDie(i);
    }
}
void  ThreeDicePoker::setDie(int dieNumber, int value){
    this->dice[dieNumber].setValue(value);
}


