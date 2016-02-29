/* CSCI261 Homework 10: numberGuessing
 *
 * Author: ADAM LONGORIA
 *
 * A number guessing game.
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	int number = rand() % 101;
	int guess;
	int tries = 0;
	
	cout << "Play the number guessing game!!" << endl;
	
	while (true) {
		cout << "Enter a number between 0 and 100: ";
		cin >> guess;
		if (guess > 0 && guess < 100) {
			if (guess < number - 20) {
				cout << "Too low, not even close!!!!! hahahaha" << endl;
				tries++;
			}
			if (guess > number + 20) {
				cout << "Too high, not even close!!!!! hahahaha" << endl;
				tries++;
			}

			if (guess >= number - 2 && guess < number ) {
				cout << "Too low, you're close!!!!!" << endl;
				tries++;
			}
			if (guess <= number + 2 && guess > number ) {
				cout << "Too high, you're close!!!!!" << endl;
				tries++;
			}

			if (guess >= number - 20 && guess < number - 2) {
				cout << "Too low" << endl;
				tries++;
			}
			if (guess <= number + 20 && guess > number + 2) {
				cout << "Too high" << endl;
				tries++;
			}
			if (guess == number) {
				tries++;
				cout << "You are correct, You won in " << tries << " tries!" << endl;
				break;
			}
		
		
		} else {
			cout << "Between 0 and 100." << endl;
		}
	
	
	
	
	
	}





    // Exit program.
    return 0;

}