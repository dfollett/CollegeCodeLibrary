/*------------------------------------------------------------------------------
 *
 * File: Troll.cpp
 * Description: class implementation for Troll decides how Troll acts.
 * very similar to the goblin class, but differs in subtle ways.
 *
 -----------------------------------------------------------------------------*/

#include "Troll.h"

Troll::Troll(int hp, int str, int con, int xPos, int yPos){
  setHp(hp);
  setMaxHp(getHp());
  setStr(str);
  setCon(con);
  setXPos(xPos);
  setYPos(yPos);
  isAlive = true;
  setEnemyId(getUniqueEnemyId() + rand() % 2 + 10);
  print();
}

const void Troll::update(){
  int coin = rand() % 2 + 1;  //decides if it goes positive or negative
  int myRandomxPos = rand() % 3 + 7;//random number
  int myRandomxNeg = rand() % -3 - 10;//random number
  if (coin == 1){
    setXPos(getXPos() + myRandomxPos);
  }
  else if (coin == 2){
    setXPos(getXPos() + myRandomxNeg);
  }
  cout << "Troll " << getEnemyId() << " regenerates " << getCon() << " health" << endl;
  if ((getHp() + getCon()) > getMaxHp()){ //trolls regenerate health
    setHp(getMaxHp());
  }
  else{
    setHp(getHp() + getCon());
  }
}

const void Troll::attack(){
  int myRandomAttack = rand() % 8 + 1;
  int attackPoints = myRandomAttack + getStr();
  cout << "Troll " << getEnemyId() << " attacks random passerby for " << attackPoints << " damage!" << endl;
}

const void Troll::injure(int rand){
  int dmgRedux = -(getCon()*1.5) ;
  if ((dmgRedux + rand) <= 0){
    cout << "The passerby tries to attack Troll " << getEnemyId() << ", but is not very effective..." << endl << endl;
  }
  else if ((getHp() - (rand + dmgRedux)) > 0 ){
    setHp(getHp()-(rand + dmgRedux)) ;
    cout << "Troll " << getEnemyId() << " takes " << (rand + dmgRedux) << " damage! current hp = " << getHp() << endl << endl;
  }
  else{
    cout << "Troll " << getEnemyId() << " has been slain!" << endl << endl;
    setHp(0);
  }
}

const void Troll::print(){
  cout << "Troll " << getEnemyId() << " (" << getXPos() << " , " << getYPos() << ")" << " hp = " << getHp() << endl;
}
