#include "TicTacToe.h"
#include <iostream>
using namespace std;
//test
void TicTacToe::print(){
    system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

char TicTacToe::getCurrentPlayer(){
    return currentPlayer;
}

bool TicTacToe::isDone(){
    int unusedSpaces = 0;
    int completeRow = 0;
    for (int i = 0; i < 3; i++){ // checks for unused spaces
        for (int j = 0; j < 3; j++){
            if (board[i][j] == '-'){
                unusedSpaces++;
            }
        }
    }
    for (int i = 0; i < 3; i++){ // checks for complete rows/columns
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            completeRow++;
            break;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            completeRow++;
            break;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        completeRow++;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        completeRow++;
    if (unusedSpaces > 0 && completeRow == 0)
        return false;
    if (completeRow == 1)
        return true;
    if (unusedSpaces == 0)
        return true;
}

char TicTacToe::getWinner(){
    if (isDone()){
        int unusedSpaces = 0;
        for (int i = 0; i < 3; i++){ // checks for complete rows/columns
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                return board[i][0];
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                return board[0][i];
            }
        }
        for (int i = 0; i < 3; i++){ // checks for unused spaces
            for (int j = 0; j < 3; j++){
                if (board[i][j] == '-'){
                    unusedSpaces++;
                }
            }
        }
        if (unusedSpaces == 0)
            return '-';
        if (currentPlayer == 'x')
            return 'o';
        else
            return 'x';
    }
}

bool TicTacToe::isValidMove(int row, int col){
    if (row <= 3 && col <= 3) {
        if ( board[row-1][col-1] == '-' ) {
            return true;
        }else
            return false;
    }
}

void TicTacToe::makeMove(int row, int col){
    if ( isValidMove(row,col) ) {
        board[row-1][col-1] = getCurrentPlayer();
        if (currentPlayer == 'x')
            currentPlayer = 'o';
        else
            currentPlayer = 'x';
    }
    else cout << "not a valid move";
}
