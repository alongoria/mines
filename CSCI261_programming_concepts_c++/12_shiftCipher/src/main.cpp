/* CSCI261 Homework 12: shiftCipher
 *
 * Author: ADAM LONGORIA
 *
 * This program accepts a "ciphered" file as input, and writes the deciphered version to a new file.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    char c;
	ifstream secret("secret_message.txt");
    ofstream deciphered("deciphered_message.txt");

    if (!secret) {
        cerr << "Error opening input file";
        exit(1);
    }
	if (!deciphered) {
        cerr << "Error opening output file";
        exit(1);
    }

    while (secret.get(c)) {
        if (c == '\n') {
            deciphered << endl;
        }
        else if (c == '~') {
            deciphered << ' ';
        }
        else {
            deciphered << char(c + 1);
        }
    }

	secret.close();
    deciphered.close();

    // Exit program.
    return 0;

}
