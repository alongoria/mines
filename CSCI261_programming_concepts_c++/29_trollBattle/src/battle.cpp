#include "battle.h"
#include <iostream>
using namespace std;

void fight(Troll &A, Troll &B) {
	cout << A.name << " is fighting " << B.name << "!" << endl;

	while (A.health > 0 || B.health > 0) {
		if (A.health > 0) {
			A.attack(B);
			B.health -= A.strength;
		}
		else {
			break;
		}

		if (B.health > 0) {
			B.attack(A);
			A.health -= B.strength;
		}
		else {
			break;
		}
	}
}

void declareWinner(Troll A, Troll B) {
	if (A.health > 0) {
		cout << A.name << " is the victor!" << endl;
	}
	else {
		cout << B.name << " is the victor!" << endl;
	}
}



