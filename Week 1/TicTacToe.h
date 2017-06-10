#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QObject>

#include "TicTacToe.h"
///
/// \brief provides all of the functions/variables necessary
/// to play a game of tictactoe
///
class TicTacToe {
private:
    char currentPlayer = 'x';
    char board[3][3] = {{'-','-','-'}
                       ,{'-','-','-'}
                       ,{'-','-','-'}};

public:
    ///
    /// \brief prints the TTT board
    ///
    void print();

    ///
    /// \brief gets the current player
    /// \return letter that represents the current player
    ///
    char getCurrentPlayer();

    ///
    /// \brief determines if the game is over or not
    /// \return true for over
    /// \return false for not over
    ///
    bool isDone();

    ///
    /// \brief determines the winner of the game
    /// \return 'x' , 'o' , or '-'(draw)
    ///
    char getWinner();

    ///
    /// \brief determines if the move the user is attempting to make is valid or not
    /// \param row
    /// \param col
    /// \return true if valid / false if not valid
    ///
    bool isValidMove(int row, int col);

    ///
    /// \brief inputs the user's move with the correct letter and changes
    /// currentPlayer to the other player's letter
    /// \param row
    /// \param col
    ///
    void makeMove(int row, int col);
};


#endif // TICTACTOE_H
