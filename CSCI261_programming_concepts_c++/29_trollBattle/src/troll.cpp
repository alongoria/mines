#include <cstdlib>
#include <iostream>
#include "troll.h"
using namespace std;

Troll::Troll() {
	name = "Charles";
	health = rand() % 100;
	strength = rand() % 10; 
}

Troll::Troll(string n) {
	name = n;
	health = rand() % 100;
	strength = rand() % 10;
}

void Troll::attack(Troll X) {
	cout << name << " attacks " << X.name << " doing " << strength << " damage!" << endl;
}
	