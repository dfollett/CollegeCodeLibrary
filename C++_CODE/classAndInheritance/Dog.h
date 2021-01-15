
#include <string>

using namespace std;

class Bone;	//forward declaration
class Dog {
	public:

		Dog(); //default constructor

		Dog(string); // overloaded constructor

		~Dog(); // destructor

		//accessor functions
//////////////////////////////////////////////////////////
		string getName() const;

		void setName(string);

		string getFurColor() const;

		void setFurColor(string);

		string getEyeColor() const;

		void setEyeColor(string);


		int getNumberOfLegs() const;

		void setNumberOfLegs(int);		

		double getWeight() const;

		void setWeight(double);

		bool getHappiness() const;

		void setHappiness(bool);


		void run(int, int);
		void bark(int);
		void wag(int,int);

		Bone *bone;	// pointer to object bone

		void addBone();
//////////////////////////////////////////////////////////

	private:

	// instance variables
		double newWeight;
		int newNumLegs;
		bool newHappiness;

		string newName;
		string newEyeColor;
		string newFurColor;


		int newHowFarRun;
		int newHowFastRun;

		int newNumTimesBark;

		int newNumTimesWag;
		int newHowFastWag;

		Bone *newBone;
};



