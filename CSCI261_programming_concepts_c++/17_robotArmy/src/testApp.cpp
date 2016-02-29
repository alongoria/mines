#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

// This function draws a simple robot on the screen relative to
// baseX and baseY, which are x and y coordinates.
void drawRobot(int baseX, int baseY) {
	 ofSetColor(rand() % 255, rand() % 255, rand() % 255);
     ofCircle(baseX, baseY, 30);
	 ofSetColor(rand() % 255, rand() % 255, rand() % 255);
	 ofRect(baseX - 24, baseY + 18, 50, 100);
	 ofSetColor(0, 0, 0);
	 ofCircle(baseX - 10, baseY - 8, 3);
	 ofCircle(baseX + 10, baseY - 8, 3);
	
  
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int x = 15; x < 800; x += 50) {
		for (int y = -20; y < 800; y += 100) {
			drawRobot(x, y);
		}
	}
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

