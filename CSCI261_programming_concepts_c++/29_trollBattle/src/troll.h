#pragma once
#include <string>
using namespace std;

class Troll {
	public:
		Troll();
		Troll(string n);
		string name;
		int health;
		int strength;
		void attack(Troll X);

};

	
