/*------------------------------------------------------------------------------
 *
 * File: GameBoard.cpp
 * Description: class implementation for GameBoard decides how the GameBoard acts.
 *
 -----------------------------------------------------------------------------*/
#include "GameBoard.h"

GameBoard::GameBoard(int x, int y){ //constructor for gameboard.
  this->x = x+1;
  this->y = y+1;
}

/*------------------------------------------------------------------------------
 * Description: loads the vector with pointer to enemy.
 -----------------------------------------------------------------------------*/
const void GameBoard::addGamePiece(Enemy *ptr){
      enemyVector.push_back(ptr);
      cout << "Adding " << ptr->getDisplayChar() << ptr->getId() << " at (" << ptr->getX() << "," << ptr->getY()<<")" << endl << endl;
}

/*------------------------------------------------------------------------------
 * Description: basically does all the work. first stores a board using
 * nested for loop. Then checks if a piece is off the board changes
 * x or y to max of its quadrant.Also checks if two pieces are on top of
 * eachother, and moves them to another spot.
 -----------------------------------------------------------------------------*/
const void GameBoard::printBoard(){
  cout << "Current board status: " << endl << endl;
    for(int i = 0; i < x; i++){//storing board
      for(int j = 0; j < y; j++){
        if(j == (x/2) && i!=(x/2)){
          place[i][j] = '|';
        }
        else if(i == (x/2)){
          place[i][j] = '_';
        }
        else {
          place[i][j] = '-';
        }
      }
    }

    for (int k = 0; k < enemyVector.size(); k++){
      int ex = enemyVector[k]->getX();
      int ey = enemyVector[k]->getY();
      cout<<"old: "<<"("<<ex<<","<<ey<<")"<<endl;
      int randNum = rand()%2+1;

      if (ex>(x/2)){//x it too big
        ex = (x/2);
      }
      if (ex<-(x/2)){//x is too small
        ex = -(x/2);
      }
      if (ey>(y/2)){//y is too big
        ey = (x/2);
      }
      if (ey<-(y/2)){//y is too small
        ey = -(x/2);
      }

      if (place[(y/2)-ey][(x/2)+ex] == 'G'||place[(y/2)-ey][(x/2)+ex] == 'T'||place[(y/2)-ey][(x/2)+ex] == 'O'||place[(y/2)-ey][(x/2)+ex] == 'g'||place[(y/2)-ey][(x/2)+ex] == 't'||place[(y/2)-ey][(x/2)+ex] == 'o'){
          ex -= randNum;
          ey -= randNum;
      }

      if (ex>(x/2)){//x it too big
        ex = (x/2);
      }
      if (ex<-(x/2)){//x is too small
        ex = -(x/2);
      }
      if (ey>(y/2)){//y is too big
        ey = (x/2);
      }
      if (ey<-(y/2)){//y is too small
        ey = -(x/2);
      }

        place[(y/2)-ey][(x/2)+ex] = enemyVector[k]->getDisplayChar();
        cout<<"new: "<<"("<<ex<<","<<ey<<")"<<endl<<endl;

    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
          cout<<' '<<place[i][j];
        }
        cout<<endl;
    }
}

/*------------------------------------------------------------------------------
 * Description: resets board and vector beteen each print.
 -----------------------------------------------------------------------------*/
const void GameBoard::resetBoard(){
  enemyVector.clear();
  for(int i = 0; i < x; i++){//clear board
    for(int j = 0; j < y; j++){
      if(j == (x/2) && i!=(x/2)){
        place[i][j] = '|';
      }
      else if(i == (x/2)){
        place[i][j] = '_';
      }
      else {
        place[i][j] = '-';
      }
    }
  }
}
