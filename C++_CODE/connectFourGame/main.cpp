/*-------------------------------------------------------
 Dustin Follett  cs-360 main
 This is the main function that calls the class
 definitions to provide a game of connect four.
---------------------------------------------------------*/

#include <iostream>
#include "ConnectFourBoard.h"
#include <limits>
using namespace std;

/*-------------------------------------------------------
Main function that handles the first input to get the game
going.
---------------------------------------------------------*/

int main(){
  cout << "~*~*~* Welcome to Connect Four! *~*~*~" << endl<<endl;
  bool won = false;
  int x = -1;
  do{
    cout << "1: quit" << endl;
    cout << "2: new game" << endl;
    cout << "Enter choice: ";
    cin >> x;
    cout<<endl;

      if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "I'm sorry, but that's not a valid choice. Please try again."<< endl;
        cout << "Enter choice: ";
        cin>>x;
        cout << endl;
      }

    if (x == 1){
      cout << "Now exiting..." << endl;
      won = true;
      break;
    }

    if (x == 2){
      while (won != true){
        Board board;
        board.takeTurns();
        continue;
      }
    }

    else {
      cout << "I'm sorry, but that's not a valid choice. Please try again."<< endl;
    }
  } while (won != true);
}
