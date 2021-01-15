/*------------------------------------------------------------------------------
 *
 * File: Enemy.cpp
 * Description: Abstract Base Class Enemy's implementation
 *
 -----------------------------------------------------------------------------*/

#include "Enemy.h"

  Enemy::Enemy(int health, int str, int con, int xPosition, int yPosition){
    this->health = health;
    this->str = str;
    this->con = con;
    setX(xPosition);
    setY(yPosition);
  }

/*------------------------------------------------------------------------------
 * Description: isAlive is a function accesable by all derived classes
 * through inheritance.
 -----------------------------------------------------------------------------*/
  bool Enemy::isAlive() const{
    if (getHealth() <= 0){
      return false;
    }
    else{
      return true;
    }
  }
  void Enemy::setX(int x){
    xPosition = x;
  }
  void Enemy::setY(int y){
    yPosition = y;
  }

  int Enemy::getId() const{
    return id;
  }
  int Enemy::getHealth() const{
    return health;
  }
  int Enemy::getStr() const{
    return str;
  }
  int Enemy::getCon() const{
    return con;
  }
  int Enemy::getX() const{
    return xPosition;
  }
  int Enemy::getY() const{
    return yPosition;
  }
