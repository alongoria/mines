/* CSCI261 Homework 05: booleanExpressions
 *
 * Author: ADAM LONGORIA
 *
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	bool a; 
	bool b;
	bool c;
	bool x;

	cout << "Enter values for three boolean variables ( enter 1 or 0 )." << endl;
	cout << "a. "; cin >> a;
	cout << "b. "; cin >> b; 
	cout << "c. "; cin >> c; 
	x = !(a && b && c) && !(a || b || c);
	cout << "The expression !(a && b && c) && !(a || b || c)" << endl << "when a=" << a << " b=" << b << " c=" << c << " yields " << x << endl; 

	// Exit program.
    return 0;
}