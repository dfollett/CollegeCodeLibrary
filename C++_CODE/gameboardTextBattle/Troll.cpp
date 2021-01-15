/*------------------------------------------------------------------------------
 *
 * File: Troll.cpp
 * Description: class implementation for Troll decides how Troll acts.
 * very similar to the goblin class, but differs in subtle ways.
 *
 -----------------------------------------------------------------------------*/

#include "Troll.h"


  Troll::Troll(int health, int str, int con, int xPosition, int yPosition): Enemy(health, str, con, xPosition, yPosition){ //constructor
    isAlive();
    maxHealth = health;
    id = rand()%100 + 1;
    print();
  }

  void Troll::update(){
    int coin = rand() % 2 + 1;  //decides if it goes positive or negative
    int myRandomxPos = rand() % 3 + 7;//random number
    int myRandomxNeg = rand() % -3 - 10;//random number
    if (coin == 1){
      xPosition = (getX() + myRandomxPos);
    }
    else if (coin == 2){
      xPosition = (getX() + myRandomxNeg);
    }
    cout << "Troll " << getId() << " regenerates " << getCon() << " health" << endl;
    if ((health + con) > maxHealth){ //trolls regenerate health
      health = maxHealth;
    }
    else{
      health = (health + con);
    }
  }

  void Troll::attack()const{
    int myRandomAttack = rand() % 8 + 1;
    int attackPoints = myRandomAttack + str;
    cout << "Troll " << getId() << " attacks random passerby for " << attackPoints << " damage!" << endl;
  }

  void Troll::injure(int rand){
    int dmgRedux = -(getCon()*1.5);
    if ((dmgRedux + rand) <= 0){
      cout << "The passerby tries to attack Troll " << getId() << ", but is not very effective..." << endl << endl;
    }
    else if ((getHealth() - (rand + dmgRedux)) > 0 ){
      health = (getHealth() - (rand + dmgRedux)) ;
      cout << "Troll " << getId() << " takes " << (rand + dmgRedux) << " damage! current hp = " << getHealth() << endl << endl;
    }
    else{
      cout << "Troll " << getId() << " has been slain!" << endl << endl;
      health = 0;
    }
  }

  void Troll::print()const{
    cout << "Troll " << getId() << " (" << getX() << " , " << getY() << ")" << " hp = " << getHealth() << endl;
  }

  const char Troll::getDisplayChar() const{
    if (isAlive()){
      return 'T';
    }
    else
      return 't';
  }
