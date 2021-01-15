/*------------------------------------------------------------------------------
 *
 * File: Orc.h
 * Description: Orc class provides constructor and prototyped virtual
 * functions for the Orc object.
 *
 -----------------------------------------------------------------------------*/

#ifndef Orc_H
#define Orc_H

#include "Enemy.h"

class Orc : public Enemy{
  public:
    Orc(int hp, int str, int con, int xPos, int yPos);
    const void update();
    const void attack();
    const void injure(int rand);
    const void print();

    bool isAlive;

};

#endif
