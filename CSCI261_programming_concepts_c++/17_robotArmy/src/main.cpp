/* CSCI261 Homework 17: robotArmy
 *
 * Author: ADAM LONGORIA
 *
 * This is a graphical program that uses OpenFrameworks to draw a
 * ton of robots on the screen.
 *
 * For this assignment, you should only modify testApp.cpp.
 *
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main() {

    ofAppGlutWindow window;
	  ofSetupOpenGL(&window, 800, 800, OF_WINDOW);			// <-------- setup the GL context

  	// this kicks off the running of my app
  	// can be OF_WINDOW or OF_FULLSCREEN
  	// pass in width and height too:
  	ofRunApp( new testApp() );

}
