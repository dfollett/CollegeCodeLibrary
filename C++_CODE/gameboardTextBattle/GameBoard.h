/*------------------------------------------------------------------------------
 *
 * File: GameBoard.h
 * Description: function prototypes and variables for Gameboard.
 *
 -----------------------------------------------------------------------------*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Enemy.h"//gives access to enemy methods w/o worrie of virtual functions

#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

class GameBoard{
  protected:
    //friend class Enemy;
    int x;
    int y;
    vector<Enemy*>enemyVector; //vector of enemy pointers declaration
    char place[500][500]; //overestimate to prevent segmentationfaults

	public:
    GameBoard(int x, int y);
    const void addGamePiece(Enemy *ptr);
    const void printBoard();
    const void resetBoard();

}; //end of class

#endif
