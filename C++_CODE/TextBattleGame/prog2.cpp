////////////////////////////////////////////////////////////////////////////////
//	Dustin Follett		cs-221
//	10/20/18
//	text battle program with an output file (battleResults) summerizing the battle and 		requires an input file (characterInfo) to format the names spell and min and max attack 	values
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <chrono> 
#include <iosfwd>
#include <fstream>
#include <cctype>

//function to create a random number for attacking
int attack(int max,int min){
	unsigned randomNumber = rand()%(max-min + 1)+ min;
	return randomNumber;
	}
//function for creating a random number for spell
int ability(int max,int min){
	int randomNumber = rand()%(max-min + 1)+ min;
	return randomNumber;
	}
//function for creating a random number for health potion returns 0 if 3 potions were used 
int potion(int max,int min, int count){
	if (count<3){
		int randomNumber = rand()%(max-min + 1) + min;
		return randomNumber;
		}
	else{
		return	0;
		}
	}

int main(){
//creates a structure to hold variables for manipulation 
struct Mod {
	char name1[25];
	char name2[25];
	int health1 = 0;
	int health2 = 0;
	char ability1[25];
	char ability2[25];
	int minAttack =0;
	int maxAttack =0;
	int minAbility =0;
	int maxAbility =0;
	int minPotion =0;
	int maxPotion =0;
	int potionCount1 =0;
	int potionCount2 =0;	
	
};

	using namespace std;

	//constructs the structure
	struct Mod mod;

	//opens file for manipulating
	ifstream input_file("/home/dustin/Documents/cs-221/characterInfo.txt",ifstream::in);

	// if not found returns error
	if (!input_file) {
   		cerr << "Unable to open file characterinfo.txt\n"; // prints error
   		exit(1);  //stops program
		}
	int temp = 0;
	//tokenizes and assigns all variables in characterinfo page
	while (temp == 0){
		input_file>> mod.name1 >> mod.health1 >> mod.ability1 >> mod.name2 >> mod.health2 			>> mod.ability2 >> mod.minAttack >> mod.maxAttack >> mod.minAbility >> 			mod.maxAbility >> mod.minPotion >> mod.maxPotion;
		temp = 1;
		}

	input_file.close();

	int x = 0;
	int damageTaken;
	int regen;
	int compareHealth1 = mod.health1;
	int compareHealth2 = mod.health2;
	
	//opens output file 
	ofstream output_file("/home/dustin/Documents/cs-221/battleResults.txt",ifstream::out);

	if (!output_file) {
   		cerr << "Unable to open file characterinfo.txt\n"; // prints error
   		exit(1);  //stops program
		}

	cout<<mod.name1<<" ("<<mod.health1<<" HP) will battle "<<mod.name2<<" ("<<mod.health2<<" HP)"<<endl<<endl;

	//outputs to battleresults
	output_file<<mod.name1<<" ("<<mod.health1<<" HP) will battle "<<mod.name2<<" ("<<mod.health2<<" HP)"<<endl;

	//do while loop controlls switches breaks when someone dies
	do
	{
	if (mod.health2<0){
		output_file<<mod.name1<<"IS TRIUMPHANT!!!";
		break;
		}
	if (mod.health1<0){
		output_file<<mod.name2<<"IS TRIUMPHANT!!!";
		break;
		}
	cout << "it's " << mod.name1 << "'s turn. Current HP = "<< mod.health1<< endl; 
	cout << "1: Attack" << endl;
	cout << "2: use "<< mod.ability1 << endl;
	cout << "3: use a potion" << endl;
	cout << "Enter action: ";
	cin >> x;

	//switch loop for the good guys turn
	switch (x) 
  	{ 
		//attack 
		case 1: damageTaken = attack(mod.maxAttack, mod.minAttack);
			mod.health2 = mod.health2 - damageTaken; 
			cout<<endl<<mod.name1<<" takes a swing! "<<mod.name2<<" takes "<<damageTaken<< " damage. New HP = "<<mod.health2<<endl<<endl;
			output_file<<endl<<mod.name1<<" takes a swing! "<<mod.name2<<" takes "<<damageTaken<< " damage. New HP = "<<mod.health2<<endl;
			break;
		//spell/ability	 
		case 2: damageTaken = ability(mod.maxAbility, mod.minAbility);
			mod.health2 = mod.health2 - damageTaken; 
			cout<<endl<<mod.name1<<" uses "<<mod.ability1<<" on "<<mod.name2<<". "<<mod.name2<< " takes "<<damageTaken<< " damage. New HP = "<<mod.health2<<endl<<endl;
			output_file<<endl<<mod.name1<<" uses "<<mod.ability1<<" on "<<mod.name2<<". "<<mod.name2<< " takes "<<damageTaken<< " damage. New HP = "<<mod.health2<<endl;
			break;
 
                //potion also checks if 3 have been used if so another chance is given	 
       		case 3: if (mod.potionCount1==3){
				cout<<endl<<"You reach for potions but find only empty flask's. Make a move before your opponent does!"<<endl<<endl;
				continue;	
				}

			else{
				regen = potion(mod.maxPotion, mod.minAttack, 					mod.potionCount1);
				mod.health1 += regen;
				mod.potionCount1 += 1;
				if (mod.health1>compareHealth1){
					mod.health1 = compareHealth1;
					}
				cout<<endl<<mod.name1<<" engulfs health potion and regenerates "<<regen<<"! New HP = "<<mod.health1<<endl<<endl;
				output_file<<endl<<mod.name1<<" engulfs health potion and regenerates "<<regen<<"! New HP = "<<mod.health1<<endl;
				break; 
			}
               	
		//default value if something other than 1-3 is entered if not another chance is given 
       		default: printf("\nYour clumbsiness almost cost you a turn! please enter int between 1 and 3.\n\n"); 
		continue;
       	//checks if someone is dead if so output to battleresults file indicates the winner 
   	}
	if (mod.health1<0){
		output_file<<mod.name2<<"IS TRIUMPHANT!!!";
		break;
		}
	if (mod.health2<0){
		output_file<<mod.name1<<"IS TRIUMPHANT!!!";
		break;
		}

	//beginning of next turn mirrior image of first players options ect.
	cout << "it's " << mod.name2 << "'s turn. Current HP = "<< mod.health2<< endl; 
	cout << "1: Attack" << endl;
	cout << "2: use "<< mod.ability2 << endl;
	cout << "3: use a potion" << endl;
	cout << "Enter action: ";
	cin >> x;

	switch (x) 
  	{ 
		case 1: damageTaken = attack(mod.maxAttack, mod.minAttack);
			mod.health1 = mod.health1 - damageTaken; 
			cout<<endl<<mod.name2<<" takes a swing! "<<mod.name1<<" takes "<<damageTaken<< " damage. New HP = "<<mod.health1<<endl<<endl;
			output_file<<endl<<mod.name2<<" takes a swing! "<<mod.name1<<" takes "<<damageTaken<< " damage. New HP = "<<mod.health1<<endl;
			break;	 
		case 2: damageTaken = ability(mod.maxAbility, mod.minAbility);
			mod.health1 = mod.health1 - damageTaken; 
			cout<<endl<<mod.name2<<" uses "<<mod.ability2<<" on "<<mod.name1<<". "<<mod.name1<< " takes "<<damageTaken<< " damage. New HP = "<<mod.health1<<endl<<endl;
			output_file<<endl<<mod.name2<<" uses "<<mod.ability2<<" on "<<mod.name1<<". "<<mod.name1<< " takes "<<damageTaken<< " damage. New HP = "<<mod.health1<<endl;
			break;
 
                	 
       		case 3: if (mod.potionCount2==3){
				cout<<endl<<"You reach for potions but find only empty flask's. Since your evil you loose a turn!"<<endl<<endl;
				continue;
				}

			else{
				regen = potion(mod.maxPotion, mod.minAttack, 					mod.potionCount2);
				mod.health2 += regen;
				mod.potionCount2 += 1;
				if (mod.health1>compareHealth2){
					mod.health1 = compareHealth2;
					}
				cout<<endl<<mod.name2<<" engulfs health potion and regenerates "<<regen<<"! New HP = "<<mod.health2<<endl<<endl;
				output_file<<endl<<mod.name2<<" engulfs health potion and regenerates "<<regen<<"! New HP = "<<mod.health2<<endl;
				break;  
			}
               		 
       		default: printf("\nYour clumbsiness cost you a turn because your evil! please enter int between 1 and 3.\n\n"); 
		break;
		continue;
                	   
   	}
   	}while (mod.health2>0 || mod.health1>0); 

		output_file.close();

}
