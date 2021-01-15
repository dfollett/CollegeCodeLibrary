/*------------------------------------------------------------------------------
 *
 * File: Enemy.cpp
 * Description: Abstract Base Class Enemy's implementation
 *
 -----------------------------------------------------------------------------*/

#include "Enemy.h"

/*------------------------------------------------------------------------------
 * Description: isAlive is a function accesable by all derived classes
 * through inheritance.
 -----------------------------------------------------------------------------*/
  bool Enemy::isAlive(){
    print();
    if (getHp() <= 0){
      return false;
    }
    else{
      return true;
    }
  }

/*------------------------------------------------------------------------------
* Unique ID Explination: this function is called by each object and it returns
* a random number anywhere from -1000 to 1000. When the object recieves this
* random number it then adds a random number to that just incase this function
* returned the same thing twice. Thus it will always be a random id thus unique.
* I wanted to increment a counter everytime something was constructed, but
* I wassnt able to get it to work.
------------------------------------------------------------------------------*/
  int Enemy::getUniqueEnemyId(){
    counter = rand() % 2000 + -1000;;
    return counter;
  }

  /*------------------------------------------------------------------------------
   * Description: getters and setters accessable to all objects derived from this.
   -----------------------------------------------------------------------------*/
  int Enemy::getEnemyId() const{
    return enemyId;
  }
  void Enemy::setEnemyId(int enemyId){
    this->enemyId = enemyId;
  }
  int Enemy::getHp() const{
    return hp;
  }
  void Enemy::setHp(int hp){
    this->hp = hp;
  }
  int Enemy::getMaxHp() const{
    return maxHp;
  }
  void Enemy::setMaxHp(int maxHp){
    this->maxHp = maxHp;
  }
  int Enemy::getStr() const{
    return str;
  }
  void Enemy::setStr(int str){
    this->str = str;
  }
  int Enemy::getCon() const{
    return con;
  }
  void Enemy::setCon(int con){
    this->con = con;
  }
  int Enemy::getXPos() const{
    return xPos;
  }
  void Enemy::setXPos(int xPos){
    this->xPos = xPos;
  }
  int Enemy::getYPos() const{
    return yPos;
  }
  void Enemy::setYPos(int yPos){
    this->yPos = yPos;
  }
