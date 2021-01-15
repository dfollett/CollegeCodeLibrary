/*-------------------------------------------------------
 Dustin Follett  cs-360 definitions
 This provides the ConnectFourBoards class definitions.
---------------------------------------------------------*/

class Board{
  public:
  Board();    // constructor
  ~Board();         // destructor
  const void takeTurns();
  const void dropChip(char playerChip);
  const bool checkWin(char playerChip);
  const void displayBoard();
  void fall(int col, char playerChip);
  const void reMain();
  char place[6][7]; // makes the board public
                    // its called place to avoid
                    // confusion with the constructor

  private:
    char playerChip;
    int col;
};
