/*------------------------------------------------------------------------------
 *
 * File: Troll.cpp
 * Description: class implementation for Orc decides how Orc acts.
 * very similar to the goblin and Troll classes, but differs in subtle ways.
 *
 -----------------------------------------------------------------------------*/

#include "Orc.h"


Orc::Orc(int hp, int str, int con, int xPos, int yPos){
  setHp(hp);
  setStr(str);
  setCon(con);
  setXPos(xPos);
  setYPos(yPos);
  isAlive = true;
  setEnemyId(getUniqueEnemyId() + rand() % 2);
  print();
}

const void Orc::update(){
  int myRandom = rand() % 10 + -5;  //random number -3-3
  setXPos(getXPos() + myRandom);  //moves same ammount x and y
  setYPos(getYPos() + myRandom);
}

const void Orc::attack(){
  int myRandomAttack = rand() % 6 + 1;
  int attackPoints = myRandomAttack + getStr();
  cout << "Orc " << getEnemyId() << " attacks random passerby for " << attackPoints << " damage!" << endl;
}

const void Orc::injure(int rand){
  int dmgRedux = -(getCon());
  if ((dmgRedux + rand) <= 0){
    cout << "The passerby tries to attack orc " << getEnemyId() << ", but is not very effective..." << endl << endl;
  }
  else if ((getHp() - (rand + dmgRedux)) > 0 ){
    setHp(getHp()-(rand + dmgRedux));
    cout << "Orc " << getEnemyId() << " takes " << (rand + dmgRedux) << " damage! current hp = " << getHp() << endl << endl;
  }
  else{
    cout << "Orc " << getEnemyId() << " has been slain!" << endl << endl;
    setHp(0);
  }
}

const void Orc::print(){
  cout << "Orc " << getEnemyId() << " (" << getXPos() << " , " << getYPos() << ")" << " hp = " << getHp() << endl;
}
