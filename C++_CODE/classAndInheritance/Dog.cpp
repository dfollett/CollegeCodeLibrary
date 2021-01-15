#include <iostream>
#include<unistd.h>
#include "Dog.h"
#include "Bone.h"

using namespace std;

	//default constructor
	Dog::Dog(){
		newWeight = 0.0;
		newNumLegs = 0;
	}

	//parameterized constructor
	Dog::Dog(string name){
		newName = name;
		cout<<name<<" is being born!!"<<endl;
	}

	//destructor
	Dog::~Dog(){
			cout<<newName<< " has gone in search of new friend."<<endl;
	}

	//accessors
////////////////////////////////////////////////////////////////////////////////////
	string Dog::getName() const{
		return newName;
	}

	void Dog::setName(string name){
		newName = name;
	}

	string Dog::getEyeColor() const{
		return newEyeColor;

	}

	void Dog::setEyeColor(string eyeColor){
		newEyeColor = eyeColor;
		cout<<newName<< " has "<<newEyeColor<<" colored eyes."<<endl;
	}

	string Dog::getFurColor() const{
		return newFurColor;
	}

	void Dog::setFurColor(string furColor){
		newFurColor = furColor;
		cout<<newName<< " has "<<newFurColor<<" colored hair."<<endl;
	}

	int Dog::getNumberOfLegs() const{
		return newNumLegs;
	}

	void Dog::setNumberOfLegs(int numLegs){
		newNumLegs = numLegs;
	}
	
	double Dog::getWeight() const{
		return newWeight;
	}

	void Dog::setWeight(double weight){
		newWeight = weight;
	}

	bool Dog::getHappiness() const{
		return newHappiness;
	}
////////////////////////////////////////////////////////////////////////////////

	// function for running takes in how fast and how far to run
	void Dog::run (int howFar, int howFast){
		if (newNumLegs<3){
			return;
		}
		if (newNumLegs==3){
			howFast -= (howFast * .25);
		}
		if (newNumLegs>4){
			newNumLegs = 4;
		}
		if (howFast>1000 || howFast<0){
			howFast = 0;
		}

		cout<<"Hello, I'm "<<newName<<", and I am chasing wabbits... Sleep Value: "<<howFast<<endl;

		if (0<=howFar && howFar<=100){
			if (0<=howFast && howFast<=1000){
				for(int i = 0; i<howFar;i++){
						usleep(howFast*1000);
						cout<<"# "<<flush;
				}
			
			}
		}
		else{}	
		cout<<"\n"<<newName<<" is tired now. My tail is dragging."<<endl;	
	}

	// function for barking will vary based on weight of dog
	void Dog::bark (int numTimes){
		newNumTimesBark = numTimes;
		cout <<"my name is "<<newName<<" hear me roar!!"<<endl;
		if(newHappiness == true){
			for(int i = 0; i<newNumTimesBark;i++){
				if (newWeight<100){
					cout<<"yap!!! "<<endl;
				}
				else{
					cout<<"WOOF!!!"<<endl;
				}
			}
		}
	}

	// function takes in numTimes & how fast displays wag as \ / \ /
	void Dog::wag (int numTimes,int howFast){
		if (numTimes>1000 || numTimes<0){
			return;
		}

		if (howFast>1000 || howFast<0){
			howFast = 0;
		}

		if (0<=numTimes && numTimes<=1000){
			if(0<=howFast && howFast<=1000){
				if(newHappiness == true){
					cout<<"I'm "<<newName<<", and I am happy. I'm wagging my tail... Sleep Value: "<< howFast<<endl;
					int left = (numTimes/2);
					int right = (numTimes-left);
					while (left + right != 0){
						if(left>0){
							cout<<"\\"<<flush;
							cout<<" ";
							left--;
							usleep(howFast*1000);
						}
						if(right>0){
							cout<<"/"<<flush;
							cout<<" ";
							right--;
							usleep(howFast*1000);
						}
						else{
						}
					}
				cout<<"\nI'm "<<newName<<", and I'm done being happy."<<endl;
				if (newHappiness == true){
					delete bone;
				}
				else{}
				}
			}	
		}
	}

	
	// calls class bone to dynamically create a bone and sets happiness to true
	void Dog::addBone(){
		bone = new Bone();
		newHappiness = true;
	}

