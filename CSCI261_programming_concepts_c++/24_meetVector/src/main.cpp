/* CSCI261 Homework 24: meetVector
 *
 * Author: ADAM LONGORIA
 *
 * This program introduces the use of vectors.
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	char in = ' ';
	vector<char> letter; 

	cout << "Witness my exciting first use of vectors!" << endl;
	cout << "Enter as many letters as you like, or ! to quit. Mmmkay?" << endl;

	while (in != '!') {
		cout << "Enter a letter: ";
		cin >> in;
		if (in != '!') {
			letter.push_back(in);
		}
	}

	int size = letter.size();

	cout << "Great. You entered: ";

	for(int i = 0; i < size; i++) {
		cout << letter[i];
	}

	cout << endl;

	cout << "The first character you entered was: " << letter.front() << endl; 
	cout << "The last character you entered was: " << letter.back() << endl;





    // Exit program.
    return 0;
}