/* CSCI261 Homework 19: meetArray
 *
 * Author: ADAM LONGORIA
 *
 * This program collects five numbers from the user, stores them in an array, and then
 * prints the maximum number entered.
*/
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int max(int values[], int size);

int main() {

	int const ARRAY_SIZE = 5;
	int list[ARRAY_SIZE]; 

	cout << "Hey! Witness my first array mojo!" << endl;
	cout << "Enter " << ARRAY_SIZE << " numbers and I will tell you which is the largest." << endl;
	for(int i = 0; i < ARRAY_SIZE; i++) {
		int number;
		cout << "Number " << i + 1 << ": ";
		cin >> number;
		list[i] = number;
	}

	cout << "So awesome!" << endl;
	int MAX = max(list,ARRAY_SIZE);
	cout << "The largest number was " << MAX << "." << endl;

    // Exit program.
    return 0;
}

int max(int values[], int size) {

	int max_val;

	

	for(int i = 0; values[i] > max_val; i++) {
		max_val = values[0];
		if(values[i] > max_val) {
			max_val = values[i];
		}
	}
	return max_val;
}


	
	/*
	int max_val = 0;
	
	for(int x = 0; x < size; x++) {
		if(values[x] > 0) {
			break;
		}
		else if(values[x] < 0) {
			max_val = values[x];
			if(values[x] > max_val) {
				max_val = values[x];
			}
		}
	}

	for(int y = 0; y < size; y++) {
		if(values[y] > max_val) {
			max_val = values[y];
		}
	}
	
	return max_val;
}
*/