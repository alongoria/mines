/* CSCI261 Homework 22: letterFrequencyConsole
 *
 * Author: ADAM LONGORIA
 *
 * This program prints the frequencies of letters in a data file.
 *
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global variables (constants)

const int LETTERS_IN_ALPHABET = 26;
const int OFFSET = 32;
const string FILENAME = "alice.txt";
int frequencies[LETTERS_IN_ALPHABET] = {0};
char letter;
char ASCII = 'a';
char ascii = 'a';


// Opens a text file and counts the frequency of each alpha character in the file,
// storing the frequencies in an array.
void loadFrequencies(string filename, int frequencies[]) {

	int count;
		
	for (int a = 0; a < LETTERS_IN_ALPHABET; a++) {
		count = 0;
		ifstream data(filename.c_str());

		if (!data) {
			cerr << "Error opening input file";
			exit(1);
		}

		while (data.get(letter)) {
			if(letter == ASCII || letter == char(ASCII - OFFSET)){
				count += 1;
			}
			frequencies[a] = count;
		}
		data.close();
		ASCII += 1;
	}
}


	


// Finds the largest frequency in the array and returns its index
int findMaxIndex(int frequencies[], int arrayLength) {

	int max = frequencies[0];
	int index = 0;

	for (int m = 0; m < LETTERS_IN_ALPHABET; m++) {
		if (frequencies[m] >= max) {
			max = frequencies[m];
			index = m;
		}
	}	
    return index; 
}

// Prints the frequencies stored in the array.
void printFrequencies(int frequencies[], int arrayLength) {

	for (int c = 0; c < LETTERS_IN_ALPHABET; c++) {
		cout << char(ascii + c) << ": " << frequencies[c];
		cout << endl;
	}
}

// Prints the most frequently occuring letter.
void printMaxLetter(int index) {
	
	cout << "Most frequent letter: " << char(ascii + index) << endl;

}

int main() {

	loadFrequencies(FILENAME, frequencies);
	printFrequencies(frequencies, LETTERS_IN_ALPHABET);
	int index = findMaxIndex(frequencies, LETTERS_IN_ALPHABET);
	printMaxLetter(index);

    // Exit program.
    return 0;
}