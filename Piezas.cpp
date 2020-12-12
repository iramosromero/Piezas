#include "Piezas.h"
#include <vector>
#include <iostream>

using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    board.resize(3, vector<Piece> (4));
    for (int i = 0; i < (int)board.size(); i++) {
        for (int j = 0; j < (int)board[i].size(); j++) {
            board[i][j] = Blank;
        }
    }
    turn = X;

}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board[i][j] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{

    if (column > 3 || column < 0) {
        if (turn == O) {
            turn = X;
        }
        if (turn == X) {
            turn = O;
        }
        return Invalid;
    }

    for(int i = 2; i >= 0; i--)
    {
        if(turn == X)
        {
            if(board[i][column] == Blank)
            {
                board[i][column] = turn;
                turn = O;
                return X;
            }
        }

        if(turn == O)
        {
            if(board[i][column] == Blank)
            {
                board[i][column] = turn;
                turn = X;
                return O;
            }
        }
    }

    if(turn == X){
        turn = O;
    } else
    {
        turn = X;
    }

    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if (board[row][column] == X) {
        return X;
    }
    else if (board[row][column] == O) {
        return O;
    }
    else if (row > 2 || row < 0) {
        return Invalid;
    }
    else if (column > 3 || column < 0) {
        return Invalid;
    }
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{

    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == Blank) {
                return Invalid;
            }
        }
    }


    int Xrow1 = 0;
    int Xrow2 = 0;
    int Xrow3 = 0;
    int Orow1 = 0;
    int Orow2 = 0;
    int Orow3 = 0;

    int XrowSum = 0;
    int OrowSum = 0;

    for (int j = 0; j < 4; j++) {
        if (board[2][j] == X) {
            Xrow1++;
        }
        if (board[2][j] == O) {
            Orow1++;
        }
        if (board[1][j] == X) {
            Xrow2++;
        }
        if (board[1][j] == O) {
            Orow2++;
        }
        if (board[0][j] == X) {
            Xrow3++;
        }
        if (board[0][j] == O) {
            Orow3++;
        }
    }

    if (Xrow1 >= Xrow2 && Xrow1 >= Xrow3) {
        XrowSum = Xrow1;
    }
    if (Xrow2 >= Xrow1 && Xrow2 >= Xrow3 ) {
        XrowSum = Xrow2;
    }
    if (Xrow3 >= Xrow1 && Xrow3 >= Xrow2) {
        XrowSum = Xrow3;
    }
    if (Orow1 >= Orow2 && Orow1 >= Orow3) {
        OrowSum = Orow1;
    }
    if (Orow2 >= Orow1 && Orow2 >= Orow3) {
        OrowSum = Orow2;
    }
    if (Orow3 >= Orow1 && Orow3 >= Orow2){
        OrowSum = Orow3;
    }
    if ((Xrow1 == Xrow2) && (Xrow2 == Xrow3)) {
        XrowSum = Xrow1;
    }
    if ((Orow1 == Orow2) && (Orow2 == Orow3)) {
        OrowSum = Orow1;
    }

    int Xcol1 = 0;
    int Xcol2 = 0;
    int Xcol3 = 0;
    int Xcol4 = 0;

    int Ocol1 = 0;
    int Ocol2 = 0;
    int Ocol3 = 0;
    int Ocol4 = 0;

    int XcolSum = 0;
    int OcolSum = 0;

    for (int j = 0; j < 3; j++) {
        if (board[j][0] == X) {
            Xcol1++;
        }
        if (board[j][0] == O) {
            Ocol1++;
        }
        if (board[j][1] == X) {
            Xcol2++;
        }
        if (board[j][1] == O) {
            Ocol2++;
        }
        if (board[j][2] == X) {
            Xcol3++;
        }
        if (board[j][2] == O) {
            Ocol3++;
        }
        if (board[j][3] == X) {
            Xcol4++;
        }
        if (board[j][3] == O) {
            Ocol4++;
        }
    }


    if (Xcol3 <= Xcol1 && Xcol1 >= Xcol2) {
        if (Xcol1 >= Xcol4) {
            XcolSum = Xcol1;
        }
    }
    if (Ocol3 <= Ocol1 && Ocol1 >= Ocol2) {
        if (Ocol1 >= Ocol4) {
            OcolSum = Ocol1;
        }
    }
    if (Xcol3 <= Xcol2 && Xcol2 >= Xcol1) {
        if (Xcol2 >= Xcol4) {
            XcolSum = Xcol2;
        }
    }
    if (Ocol3 <= Ocol2 && Ocol2 >= Ocol1) {
        if (Ocol2 >= Ocol4) {
            OcolSum = Ocol2;
        }
    }
    if (Xcol1 <= Xcol3 && Xcol3 >= Xcol2) {
        if (Xcol3 >= Xcol4) {
            XcolSum = Xcol3;
        }
    }
    if (Ocol1 <= Ocol4 && Ocol4 >= Ocol2) {
        if (Ocol4 >= Ocol3) {
            OcolSum = Ocol4;
        }
    }


    int win_X = 0;
    int win_O = 0;

    if (XrowSum > XcolSum) {
        win_X = XrowSum;
    }
    if (XcolSum > XrowSum) {
        win_X = XcolSum;
    }
    if(XrowSum == XcolSum) {
        win_X = XrowSum;
    }
    if (OrowSum > OcolSum) {
        win_O = OrowSum;
    }
    if (OcolSum > OrowSum) {
        win_O = OcolSum;
    }
    if (OrowSum == OcolSum) {
        win_O = OrowSum;
    }


    if (win_X > win_O) {
        return X;
    }
    if (win_O > win_X) {
        return O;
    }

    return Blank;
}
