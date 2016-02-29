/* CSCI261 Final Project: gameOfLife
 *
 * Author: Grant Walker and Adam Longoria
 *
 * This program simulates Conway's Game of Life.
 */
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"


int main() {

    ofAppGlutWindow window;
	  ofSetupOpenGL(&window, 1000,1000, OF_WINDOW);

	  ofRunApp(new testApp());

}
