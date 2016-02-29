/* CSCI261 Homework 22: letterFrequency
 *
 * Author: ADAM LONGORIA
 *
 * This program counts the frequency of letters in Alice in Wonderland
 * and displays a bar graph of each letter's frequency.
 *
 * For this assignment, you should only modify testApp.cpp.
 *
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

int main() {

    ofAppGlutWindow window;
	  ofSetupOpenGL(&window, 800, 600, OF_WINDOW);

  	ofRunApp( new testApp());

}
