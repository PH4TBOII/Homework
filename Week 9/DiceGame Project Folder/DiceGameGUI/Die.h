#ifndef DIE_H
#define DIE_H
#include <cstdlib>
#include <ctime>




class Die {
private:

    int numSides;
    int value;

public:

    //constructors
    Die();
    Die(int sides);


    //functions
    void roll();
    void setValue(int forcedValue);
    int  getValue();


};



#endif // DIE_H
