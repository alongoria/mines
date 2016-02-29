/* CSCI261 Homework 18: factorial
 *
 * Author: ADAM LONGORIA
 *
 * This program uses a recursive function to calculate the factorial of a number.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void prompt(string message);
int captureInt(string message);
int factorial(int number);


int main() {
	int input;
	int output;
	prompt("Factorial! Factorial! I like to shout factorial!\n");
	input = captureInt("Enter an integer: ");
	output = factorial(input);
	
	cout << "The factorial of " << input << " is " << output << ".\n";

    // Exit program.
    return 0;

}

void prompt(string message) {
	cout << message;
}

int captureInt(string message) {
	int integer;
	prompt(message);
	cin >> integer;
	cin.ignore();
	return integer;
}

int factorial(int number) {
	int answer;
	if (number == 0) {
		return 1;
	}
	else if(number > 0) {
		answer = number * factorial(number - 1);
		return answer;	
	}
	else {
		prompt("NoO0oO0oO0. Cannot calculate the factorial of a negative integer :)\n");
		exit(1);
	}
}

	