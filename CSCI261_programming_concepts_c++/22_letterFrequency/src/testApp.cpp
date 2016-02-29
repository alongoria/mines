#include "testApp.h"

// Declare global variables here. We recommend:
// - a const int called SCREEN_HEIGHT, initialized to 600.
// - a const int called LETTERS_IN_ALPHABET, initialized to 26
// - a const int called ASCII_OFFSET, initialized to ?
// - a const string called FILENAME, initialized to "data\\alice.txt"
// - an integer array called frequencies, that holds LETTERS_IN_ALPHABET values
//   all initialized to zero (there's an easy way to do this!)
// - an int called mostFrequentLetterIndex
// - an int called scale

const int SCREEN_HEIGHT = 600;
const int LETTERS_IN_ALPHABET = 26;
const int OFFSET = 32;
const string FILENAME = "data\\alice.txt";
int frequencies[LETTERS_IN_ALPHABET] = {0};
int mostFrequentLetterIndex;
int scale;
int letter;


// Opens a text file and counts the frequency of each alpha character in the file,
// storing the frequencies in an array. Occurances of upper and lower case characters
// are treated the same ('a' and 'A' increment the value in frequencies[0])
void loadFrequencies() {

	ifstream data(FILENAME.c_str());

	if (!data) {
		cerr << "Error opening input file";
		exit(1);
	}

	while (data >> frequencies[letter]) {
		int count;
		char ASCII = 'a';
		for(int a = 0; a > 0; a++) {
			count = 0;
			for(int b = 0; b < LETTERS_IN_ALPHABET; b++) {
				if(letter == ASCII|| letter == ASCII + OFFSET){
					count += 1;
				}
				frequencies[b] = count;
			}
		}
	}
	cout << frequencies;
  
}

// This function conducts a sanity check of your frequencies array.
// It prints the values of each letter's frequency to the console (see the console)
// window to verify your sanity.
void testFrequencies() {

	
  
}

// Finds the largest frequency in the array and records the index,
// assigning to mostFrequentLetterIndex.
void determinMax() {
  
}

// Uses the maximum frequency to determine a "scale" to be used when drawing
// the bars of the bar graph. Assigns a value to global variable 'scale'.
void determineScale() {
  
}

// This function should load the frequencies into the array, (optionally) conduct
// a sanity test to verify the array has some sane values, determines the letter with
// the maximum frequency, and determines the "scale" of the bars in the bar graph.
// Lastly, it sets the background color to something fun.
void testApp::setup() {

}

// This function draws a bar graph consisting of LETTERS_IN_ALPHABET bars.
// See the assignment description for what this should look like.
void testApp::draw() {

}

//--------------------------------------------------------------

void testApp::update() {

}

void testApp::keyPressed(int key) {

}

void testApp::keyReleased(int key) {

}

void testApp::mouseMoved(int x, int y ) {

}

void testApp::mouseDragged(int x, int y, int button) {

}

void testApp::mousePressed(int x, int y, int button) {

}

void testApp::mouseReleased(int x, int y, int button) {

}

void testApp::windowResized(int w, int h) {

}

