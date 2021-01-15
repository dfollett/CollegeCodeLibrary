/*------------------------------------------------------------------------------
 *
 * File: Troll.cpp
 * Description: class implementation for Orc decides how Orc acts.
 * very similar to the goblin and Troll classes, but differs in subtle ways.
 *
 -----------------------------------------------------------------------------*/

#include "Orc.h"


  Orc::Orc(int health, int str, int con, int xPosition, int yPosition): Enemy(health, str, con, xPosition, yPosition){ //constructor
    isAlive();
    id = rand()%100 + 1;
    print();
  }

  void Orc::update(){
    int myRandom = rand() % 10 + -5;  //random number -3-3
    xPosition = (getX() + myRandom);  //moves same ammount x and y
    yPosition = (getY() + myRandom);
  }

  void Orc::attack()const{
    int myRandomAttack = rand() % 6 + 1;
    int attackPoints = myRandomAttack + getStr();
    cout << "Orc " << getId() << " attacks random passerby for " << attackPoints << " damage!" << endl;
  }

  void Orc::injure(int rand){
    int dmgRedux = -(getCon());
    if ((dmgRedux + rand) <= 0){
      cout << "The passerby tries to attack orc " << getId() << ", but is not very effective..." << endl << endl;
    }
    else if ((getHealth() - (rand + dmgRedux)) > 0 ){
      health = (getHealth() - (rand + dmgRedux));
      cout << "Orc " << getId() << " takes " << (rand + dmgRedux) << " damage! current hp = " << getHealth() << endl << endl;
    }
    else{
      cout << "Orc " << getId() << " has been slain!" << endl << endl;
      health = 0;
    }
  }

  void Orc::print() const{
    cout << "Orc " << getId() << " (" << getX() << " , " << getY() << ")" << " hp = " << getHealth() << endl;
  }


  const char Orc::getDisplayChar() const{
    if (isAlive()){
      return 'O';
    }
    else
      return 'o';
  }
