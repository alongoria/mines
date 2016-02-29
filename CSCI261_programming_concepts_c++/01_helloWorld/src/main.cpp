/* CSCI261 Homework 01: helloWorld
 *
 * Author: ADAM LONGORIA
 *
 * This is a version of the canonical "Hello World" program, but brought forward into
 * the 21st century. It uses the OpenFrameworks toolkit and OpenGL. This program must
 * be compiled from within the OpenFrameworks toolkit directory structure.
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "constants.h"

int main() {

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);
	ofRunApp( new testApp());
	return 0;

}