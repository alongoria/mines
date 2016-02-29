/* CSCI261 Homework 29: trollBattle
 *
 * Author: ADAM LONGORIA
 *
 * This program simulates a simple battle between two Trolls.
 * 
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "troll.h"
#include "battle.h"
#include "test.h"
using namespace std;

int main() {
	srand(time(NULL));

	Troll A("John");
	Troll B("Jane");

	cout << A.name << "(health: " << A.health << ", strength: " << A.strength << ")" << endl;
	cout << B.name << "(health: " << B.health << ", strength: " << B.strength << ")" << endl;

	fight(A, B);
	
	cout << A.name << "(health: " << A.health << ", strength: " << A.strength << ")" << endl;
	cout << B.name << "(health: " << B.health << ", strength: " << B.strength << ")" << endl;

	declareWinner(A, B);

	// The test suite executor. Once passing, you should comment out the next line.
	//runAllTests();


    // Exit program.
    return 0;
}