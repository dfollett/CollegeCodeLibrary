/*------------------------------------------------------------------------------
 *
 * File: Troll.h
 * Description: Troll class provides constructor and prototyped virtual
 * functions for the Troll object.
 *
 -----------------------------------------------------------------------------*/

#ifndef Troll_H
#define Troll_H

#include "Enemy.h"

class Troll : public Enemy{
  public:
    Troll(int hp, int str, int con, int xPos, int yPos);
    const void update();
    const void attack();
    const void injure(int rand);
    const void print();

    bool isAlive;

};

#endif
