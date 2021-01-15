/*------------------------------------------------------------------------------
 *
 * File: Goblin.cpp
 * Description: class implementation for Goblin decides how goblin acts.
 *
 -----------------------------------------------------------------------------*/

#include "Goblin.h"

Goblin::Goblin(int hp, int str, int con, int xPos, int yPos){ //constructor
  setHp(hp);
  setStr(str);
  setCon(con);
  setXPos(xPos);
  setYPos(yPos);
  isAlive = true;
  setEnemyId(getUniqueEnemyId() + rand() % 2);
  print();
}

/*------------------------------------------------------------------------------
 * Description: update function is used to update the x,y coordinates
 * after an enemy moves.
 -----------------------------------------------------------------------------*/
const void Goblin::update(){
  int myRandomX = rand() % 6 + -3;//random number -3-3
  int myRandomY = rand() % 4 + -2;//random number -2-­2
  setXPos(getXPos() + myRandomX);
  setXPos(getXPos() + myRandomY);
}

/*------------------------------------------------------------------------------
 * Description: attack is the function that shows how much damage the enemy
 * does to an innocent passerby
 -----------------------------------------------------------------------------*/
const void Goblin::attack(){
  int myRandomAttack = rand() % 4 + 1;
  int attackPoints = myRandomAttack + getStr();
  cout << "Goblin " << getEnemyId() << " attacks random passerby for " << attackPoints << " damage!" << endl;
}

/*------------------------------------------------------------------------------
 * Description: injure is a function that lets the innocent passerby
 * get his revenge if he is lucky enough.
 -----------------------------------------------------------------------------*/
const void Goblin::injure(int rand){
  int dmgRedux = -(getCon()/2) ;
  if ((dmgRedux + rand) <= 0){
    cout << "The passerby tries to attack Goblin " << getEnemyId() << ", but is not very effective..." << endl << endl;
  }
  else if ((getHp() - (rand + dmgRedux)) > 0 ){
    setHp(getHp() - (rand + dmgRedux));
    cout << "Goblin " << getEnemyId() << " takes " << (rand + dmgRedux) << " damage! current hp = " << getHp() << endl << endl;
  }
  else{
    cout << "Goblin " << getEnemyId() << " has been slain!" << endl << endl;
    setHp(0);
  }
}

/*------------------------------------------------------------------------------
 * Description: prints the enemy name, id, position (x,y), and hp.
 -----------------------------------------------------------------------------*/
const void Goblin::print(){
  cout << "Goblin " << getEnemyId() << " (" << getXPos() << " , " << getYPos() << ")" << " hp = " << getHp() << endl;
}
