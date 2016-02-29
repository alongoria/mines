/* CSCI261 Homework 20: colorSquares
 *
 * Author: ADAM	LONGORIA
 *
 * This is a graphical program that uses OpenFrameworks to draw a
 * pattern of squares on the screen. It uses arrays to store color
 * values.
 *
 * For this assignment, you should only modify testApp.cpp.
 *
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

int main() {

    ofAppGlutWindow window;
	  ofSetupOpenGL(&window, 800, 800, OF_WINDOW);

  	ofRunApp( new testApp());

}
