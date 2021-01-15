/*-------------------------------------------------------
 Dustin Follett  cs-360 implementation
 This is a program that provides a connect four
 terminal based application.
---------------------------------------------------------*/

#include "ConnectFourBoard.h"
#include <iostream>
#include <limits>
using namespace std;

/*-------------------------------------------------------
constructor
---------------------------------------------------------*/

Board::Board(){
  for(int i = 0; i <= 5; i++){
      for(int j = 0; j <= 6; j++){
        place[i][j]= '-';
      }
  }
}

/*-------------------------------------------------------
destructor
---------------------------------------------------------*/

Board::~Board(){
  cout << "Destructor cleaning up" << endl;
}

/*-------------------------------------------------------
handles turn rotation and prints results of game
when all information is passed back to this function.
---------------------------------------------------------*/

const void Board::takeTurns(){
  bool won = false;
  bool valid = false;
  int turn = 1;
  char player1 = 'R';
  char player2 = 'B';
  int chipsDropped = 0;
  displayBoard();
  do{
    if (turn == 1){
      cout << "It is Red's turn." << endl << endl;
      dropChip(player1);
      chipsDropped++;
      displayBoard();
      won = checkWin(player1);

      if (won == true){
        cout<< "~*~*~* Red wins! *~*~*~" << endl << endl;
        break;
      }
      turn = 2;
    }

    if (turn = 2){
      cout << "It is Blacks's turn." << endl << endl;
      dropChip(player2);
      chipsDropped++;
      displayBoard();
      won = checkWin(player2);

      if (won == true){
        cout<< "~*~*~* Black wins! *~*~*~"<< endl << endl;
        break;
      }
      turn = 1;
    }

    if (chipsDropped == 42){
      cout << "~*~*~* The game is a Draw. *~*~*~" << endl << endl;
      reMain();
    }

  } while (won != true);
  reMain();
}

/*-------------------------------------------------------
takes the players chip char as an argument and uses This
to send off to the fall function. This also takes in
and validates the input of column from player.
---------------------------------------------------------*/

const void Board::dropChip(char playerChip){
  int x = -1;
  cout << "Enter column to drop in (0-6): ";
  cin >> x;
  cout << endl;

  while(cin.fail() || x > 6 || x < 0){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "I'm sorry, but that's not a valid choice. Please try again." << endl << endl;
    cout << "Enter column to drop in (0-6): ";
    cin >> x;
    cout << endl;
  }
    fall(x, playerChip);
    x = -1;
}

/*-------------------------------------------------------
itterates through the column provided as a parameter
and looks for either the bottom or a players chip.
Once found it places the current players chip accordingly.
---------------------------------------------------------*/

void Board::fall(int col, char playerChip){
  int retVal = -1;
  int counter = 0;
  for (int i = 0; i <= 6; i++){
    while (place[i][col] == '-'){
      if (place[i][col] == 'R' || place[i][col] == 'B'){
        retVal -= 1;
        counter++;
      }

      else {
        retVal++;
        counter++;
        break;
      }
    }
  }
  if (counter == 0){
    int x = -1;
    cout << "This column is full please pick another (0-6): ";
    cin >> x;
    cout << endl;
    fall(x, playerChip);

    while(cin.fail() || x > 6 || x < 0){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "I'm sorry, but that's not a valid choice. Please try again."<< endl << endl;
      cout << "This column is full please pick another (0-6): ";
      cin >> x;
      cout << endl;
      continue;
    }
  }
  place[retVal][col] = playerChip;
}

/*-------------------------------------------------------
itterates through the whole 2d array called place for each
player chip found it checks multiple winning combinations
based on where it found the chip.
---------------------------------------------------------*/

const bool Board::checkWin(char playerChip){
  for(int i = 0; i <= 6; i++){
    for(int j = 0; j <= 7; j++){
      if (place[i][j] == playerChip){
          bool retval = false;

          // vertical right to left check
          if (place[i + 1][j] == playerChip && place[i + 2][j] == playerChip && place[i + 3][j] == playerChip){
            cout << "vertical" << endl << endl;
            retval = true;
            break;
          }

          //horizontal right to left check
          if (place[i][j + 1] == playerChip && place[i][j + 2] == playerChip && place[i][j + 3] == playerChip){
            cout << "horizontal" << endl << endl;
            retval = true;
          }

          // vertical left to right check
          if (place[i - 1][j] == playerChip && place[i - 2][j] == playerChip && place[i - 3][j] == playerChip){
            cout << "vertical" << endl << endl;
            retval = true;
          }

          //horizontal left to right check
          if (place[i][j - 1] == playerChip && place[i][j - 2] == playerChip && place[i][j - 3] == playerChip){
            cout << "horizontal" << endl << endl;
            retval = true;
          }

          // diagonal up right check
          if (place[i + 1][j - 1] == playerChip && place[i + 2][j - 2] == playerChip && place[i + 3][j - 3] == playerChip){
            cout << "diagonal" << endl << endl;
            retval = true;
          }

          //diagonal up left check
          if (place[i + 1][j + 1] == playerChip && place[i + 2][j + 2] == playerChip && place[i + 3][j + 3] == playerChip){
            cout << "diagonal" << endl << endl;
            retval = true;
          }

          //diagonal down left check
          if (place[i - 1][j - 1] == playerChip && place[i - 2][j - 2] == playerChip && place[i - 3][j - 3] == playerChip){
            cout << "diagonal" << endl << endl;
            retval = true;
          }

          //diagonal down right check
          if (place[i - 1][j + 1] == playerChip && place[i - 2][j + 2] == playerChip && place[i - 3][j + 3] == playerChip){
            retval = true;
          }
          return retval;
      }
    }
  }
}

/*-------------------------------------------------------
reitterates the main function to handle when someone wins,
but wants to play another game.
---------------------------------------------------------*/

const void Board::reMain(){
  bool won = false;
  int x = -1;
  do{
    cout << "1: quit" << endl;
    cout << "2: new game" << endl;
    cout << "Enter choice: ";
    cin >> x;
    cout << endl;

    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "I'm sorry, but that's not a valid choice. Please try again."<< endl << endl;
      cout << "Enter choice: ";
      cin >> x;
      cout << endl;
    }

    if (x == 1){
      cout << "Now exiting..." << endl;
      won = true;
      abort();
    }

    if (x == 2){
      while (won != true){
        Board board;
        board.takeTurns();
        continue;
      }
    }

    else {
      cout << "I'm sorry, but that's not a valid choice. Please try again."<< endl << endl;
    }
  } while (won != true);
}

/*-------------------------------------------------------
displays the place so players can see the current board.
---------------------------------------------------------*/

const void Board::displayBoard(){
  cout << "Current board status: " << endl << endl;
  cout << " 0 1 2 3 4 5 6\n";
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 6; j++){
          cout << ' ';
          cout << place[i][j];
        }
        cout << endl;
    }
}
