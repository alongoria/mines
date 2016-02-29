/* CSCI261 Homework 28: movingSquares
 *
 * Author: ADAM LONGORIA	
 *
 * This program is an object-oriented implementation of animating
 * eight colored squares whose movement is determined by the output
 * of a sin() function.
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "test.h"

int main () {

	runAllTests();

	ofAppGlutWindow window;
    ofSetupOpenGL(&window, 800, 600, OF_WINDOW);

    ofRunApp(new testApp());

}
