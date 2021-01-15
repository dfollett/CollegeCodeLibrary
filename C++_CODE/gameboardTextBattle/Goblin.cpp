/*------------------------------------------------------------------------------
 *
 * File: Goblin.cpp
 * Description: class implementation for Goblin decides how goblin acts.
 *
 -----------------------------------------------------------------------------*/

#include "Goblin.h"

  Goblin::Goblin(int health, int str, int con, int xPosition, int yPosition): Enemy(health, str, con, xPosition, yPosition){ //constructor
    isAlive();
    id = rand()%100 + 1;
    print();
  }

/*------------------------------------------------------------------------------
 * Description: update function is used to update the x,y coordinates
 * after an enemy moves.
 -----------------------------------------------------------------------------*/
  void Goblin::update(){
    int myRandomX = rand() % 6 + -3;//random number -3-3
    int myRandomY = rand() % 4 + -2;//random number -2-­2
    xPosition = (getX() + myRandomX);
    yPosition = (getY() + myRandomY);
  }

/*------------------------------------------------------------------------------
 * Description: attack is the function that shows how much damage the enemy
 * does to an innocent passerby
 -----------------------------------------------------------------------------*/
  void Goblin::attack()const{
    int myRandomAttack = rand() % 4 + 1;
    int attackPoints = myRandomAttack + getStr();
    cout << "Goblin " << getId() << " attacks random passerby for " << attackPoints << " damage!" << endl;
  }

/*------------------------------------------------------------------------------
 * Description: injure is a function that lets the innocent passerby
 * get his revenge if he is lucky enough.
 -----------------------------------------------------------------------------*/
  void Goblin::injure(int rand){
    int dmgRedux = -(getCon()/2) ;
    if ((dmgRedux + rand) <= 0){
      cout << "The passerby tries to attack Goblin " << getId() << ", but is not very effective..." << endl << endl;
    }
    else if ((getHealth() - (rand + dmgRedux)) > 0 ){
      health = (getHealth() - (rand + dmgRedux));
      cout << "Goblin " << getId() << " takes " << (rand + dmgRedux) << " damage! current hp = " << getHealth() << endl << endl;
    }
    else{
      cout << "Goblin " << getId() << " has been slain!" << endl << endl;
      health = 0;
    }
  }

/*------------------------------------------------------------------------------
 * Description: prints the enemy name, id, position (x,y), and hp.
 -----------------------------------------------------------------------------*/
  void Goblin::print()const{
    cout << "Goblin " << getId() << " (" << getX() << " , " << getY() << ")" << " hp = " << getHealth() << endl;
  }

  /*------------------------------------------------------------------------------
   * Description: function to return G for alive and g for dead.
   -----------------------------------------------------------------------------*/
  const char Goblin::getDisplayChar() const{
    if (isAlive()){
      return 'G';
    }
    else
      return 'g';
  }
