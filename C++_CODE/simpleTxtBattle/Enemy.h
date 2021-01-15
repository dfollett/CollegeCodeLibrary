/*------------------------------------------------------------------------------
 *
 * CS 360 Spring 2017 Assignment #2
 * File: Enemy.h
 * Author: Dustin Follett
 * Last Edit: 04/19/2017
 * Description: Abstract Base Class used to set up all the members
 * of each object like health strength constitution position and id.
 *
 -----------------------------------------------------------------------------*/

#ifndef Enemy_H //include gaurd
#define Enemy_H

#include <iostream>
using namespace std;

/*------------------------------------------------------------------------------
 * Description: Base Class definition for Enemy provides all the getters and setters
 * for the derived classes.
 -----------------------------------------------------------------------------*/
class Enemy {
public:
  bool isAlive();

  virtual const void update() = 0;  //must be implemented by derivations
  virtual const void attack() = 0;  //must be implemented by derivations
  virtual const void injure(int rand) = 0;  //must be implemented by derivations
  virtual const void print() = 0;  //must be implemented by derivations

  int getUniqueEnemyId();

  int getEnemyId() const;
  void setEnemyId(int enemyId);
  int getHp() const;
  void setHp(int hp);
  int getMaxHp() const;
  void setMaxHp(int maxHp);
  int getStr() const;
  void setStr(int str);
  int getCon() const;
  void setCon(int con);
  int getXPos() const;
  void setXPos(int xPos);
  int getYPos() const;
  void setYPos(int yPos);

private:
  int counter;
  int enemyId;
  int hp;
  int maxHp;
  int str;
  int con;
  int xPos;
  int yPos;

};

#endif
