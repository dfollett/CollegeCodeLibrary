/*------------------------------------------------------------------------------
 *
 * File: Goblin.h
 * Description: Goblin class provides constructor and prototyped virtual
 * functions for the Goblin object.
 *
 -----------------------------------------------------------------------------*/

#ifndef Goblin_H  //include gaurd
#define Goblin_H

#include "Enemy.h"

class Goblin : public Enemy{  //inherates from Enemy
  public:
    Goblin(int hp, int str, int con, int xPos, int yPos); //constructor
    const void update();
    const void attack();
    const void injure(int rand);
    const void print();

    bool isAlive;

};

#endif
