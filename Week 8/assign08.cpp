#include <iostream>
using namespace std;


//function declarations
void arrayFiller(char radiationZone[10][10]);
void radiationCheck(char radiationZone[10][10], int startingX, int startingY);
int contaminationCheck(char radiationZone[10][10]);
void safetyCheck(char theArea[10][10]);



int main()
{
    //declare important variables
    int startingX;
    int startingY;
    char theArea[10][10] =
    {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    ,{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    //get the starting locations
    cout << "enter an x and y coordinate for the starting location: ";
    cin >> startingX >> startingY;
    cout << endl;

    //fill the area with walls
    arrayFiller(theArea);

    //check if the radiation can leak
    radiationCheck(theArea, startingX, startingY);

    //checks if the area is safe or not
    safetyCheck(theArea);

    //prints the amount of contaminated squares
    cout << endl << "contaminated area: " << contaminationCheck(theArea) << endl;



    return 0;
}

void arrayFiller(char radiationZone[10][10]){
    int x;
    int y;
    cout << "Please insert coordinates of walls: ";
    for (int i = 0; i < 100; i++){
        cin >> x >> y;
        if (x == 0 && y == 0){
            break;
        }
        else
            radiationZone[x][y] = '#';
    }
}
void radiationCheck(char radiationZone[10][10], int startingX, int startingY){



    if (startingX < 0 || startingY < 0 || startingX > 10 || startingY > 10){
        return;
    }
    if (radiationZone[startingX][startingY] != ' '){
        return;
    }

    radiationZone[startingX][startingY] = '.';

    radiationCheck(radiationZone, startingX + 1 , startingY + 1 );
    radiationCheck(radiationZone, startingX + 1 , startingY - 1 );
    radiationCheck(radiationZone, startingX - 1 , startingY + 1 );
    radiationCheck(radiationZone, startingX - 1 , startingY - 1 );
    radiationCheck(radiationZone, startingX + 1 , startingY );
    radiationCheck(radiationZone, startingX - 1 , startingY );
    radiationCheck(radiationZone, startingX , startingY + 1 );
    radiationCheck(radiationZone, startingX , startingY - 1 );


}
int contaminationCheck(char radiationZone[10][10]){
    int contaminatedSquares = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (radiationZone[i][j] == '.')
                contaminatedSquares += 1;
        }
    }
    return contaminatedSquares;
}
void safetyCheck(char theArea[10][10]){
    for (int i = 0; i < 10; i++){
        if (theArea[0][i] != ' '){
            cout << "Not Safe! ";
            break;
        }
        else if (theArea[i][0] != ' '){
            cout << "Not Safe! ";
            break;
        }
        else if (theArea[9][i] != ' '){
            cout << "Not Safe! ";
            break;
        }
        else if (theArea[i][9] != ' '){
            cout << "Not Safe! ";
            break;
        }
        else {
            cout << "Safe! ";
            break;
        }
    }
}






