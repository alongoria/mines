/* CSCI261 Final Project: gameOfLife
 *
 * Author: ADAM LONGORIA & GRANT WALKER  
 *
 * This program ...  is Awesome!!!
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

int main() {

    ofAppGlutWindow window;
	  ofSetupOpenGL(&window, 1000,768, OF_WINDOW);

	  ofRunApp(new testApp());

}
