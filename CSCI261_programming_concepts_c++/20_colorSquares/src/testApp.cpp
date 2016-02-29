#include "testApp.h"


// Declare your global variables here. You should declare:
// - a const integer called NUMBER_OF_SQUARES
// - three int arrays of size NUMBER_OF_SQUARES, called reds, greens and blues

const int NUMBER_OF_SQUARES = 8;
int reds[NUMBER_OF_SQUARES];
int greens[NUMBER_OF_SQUARES];
int blues[NUMBER_OF_SQUARES];


// Define a function called initializeColors here.

void initializeColors() {
	for(int a = 0; a < NUMBER_OF_SQUARES; a++) {
		reds[a] = rand() % 256;
		greens[a] = rand() % 256;
		blues[a] = rand() % 256;
	}
}





// setup() is automatically called one time, when the application starts.
// Your implementation should set the background color (we recommend black)
// and call initializeColors according to the project instructions.
void testApp::setup() {
	ofBackground(0,0,0);
	initializeColors();
}

// draw() is automatically called over and over again. Each time
// it is called, it draws something to the screen.
// Your implementation should draw NUIMBER_OF_SQUARES squares according
// to the project instructions.
void testApp::draw() {
	int x = 100;
	for(int c = 0; c < NUMBER_OF_SQUARES; c++) {
		ofSetColor(reds[c],greens[c],blues[c]);
		ofRect(x*c,350,100,100);
	}
}

//--------------------------------------------------------------
void testApp::update() {

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

