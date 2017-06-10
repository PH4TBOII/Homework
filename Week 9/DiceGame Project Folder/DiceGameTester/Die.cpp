#include "Die.h"
#include <cstdlib>
#include <ctime>


//constructors
Die::Die(){
    numSides = 6;
    srand(time(NULL));
    value = (rand() % numSides) + 1;
}
Die::Die(int sides){
    this->numSides = sides;
    value = (rand() % numSides) + 1;
}

//functions
void Die::roll(){
    this->value = (rand() % numSides) + 1;
}
void Die::setValue(int forcedValue){
   this->value = forcedValue;
}
int  Die::getValue(){
    return this->value;
}






