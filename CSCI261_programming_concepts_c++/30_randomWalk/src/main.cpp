/* CSCI261 Homework 30: randomWalk
 *
 * Author: ADAM LONGORIA
 *
 * This program draws the results of implementing the classic Random Walk
 * formalization of a trajectory determined by a series of random steps.
*/
#include <cstdlib>
#include <ctime>
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

int main() {

	srand(time(NULL));

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 800, 800, OF_WINDOW);

	ofRunApp(new testApp());

}
