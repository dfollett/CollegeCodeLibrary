/////////////////////////////////////////////////////////////////////////////////////////
// Dustin Follett  cs-221 dog object
// This is a program that creates an object dog with specific attributes including: run,
// walk, name, number of legs and wag.
/////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Dog.h"

int main( ) { 

   Dog dog1("Fido");
   dog1.setEyeColor("blue");
   dog1.setFurColor("black");
   dog1.setWeight(20.0); 
   dog1.bark(5);
   dog1.setNumberOfLegs(4); 
   dog1.run(10,450);
   dog1.addBone();
   dog1.wag(10,550);

}
