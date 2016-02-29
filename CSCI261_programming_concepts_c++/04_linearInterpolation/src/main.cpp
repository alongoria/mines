/* CSCI261 Homework 04: linearInterpolation
 *
 * Author: ADAM LONGORIA
 *
 * This is a graphical version of the boring linear interpolation program from
 * our textbook. It uses the OpenFrameworks toolkit and OpenGL. This program must
 * be compiled from within the OpenFrameworks toolkit directory structure.
 *
 * For this assignment, you should only modify testApp.cpp.
 *
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 500, 500, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
