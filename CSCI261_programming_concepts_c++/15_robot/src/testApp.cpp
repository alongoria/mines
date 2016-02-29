#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground (255, 0, 0);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor (0, 0, 0);  //head
	ofCircle (350, 250, 75);
	
	ofSetColor (0, 255, 0); //eye socket
	ofCircle (370, 237, 28); 
	
	ofSetColor (74, 29, 2); //bionic eye
	ofCircle (370, 237, 7); 
	
	ofSetColor (4, 29, 109); //top dot
	ofCircle (384, 200, 4); 
	
	ofSetColor (253, 10, 66); //left dot
	ofCircle (333, 242, 3); 
	
	ofSetColor (250, 255, 0); //right dot 
	ofCircle (404, 254, 5);

	ofSetColor (123, 45, 67); //top line 
	ofLine(370, 180, 432, 76); 

	ofSetColor (102, 0, 237); //right line 
	ofLine(423, 255, 457, 270);

	ofSetColor (255, 255, 63); //left line
	ofLine(311, 189, 291, 180);

	ofSetColor (0, 222, 11); //bottom line 1
	ofLine(350, 325, 350, 450);

	ofSetColor (0, 222, 11); //bottom line 2
	ofLine(340, 323, 340, 450);

	ofSetColor (0, 222, 11); //bottom line 3
	ofLine(360, 323, 360, 450);

	ofSetColor (0, 0, 255); //hover ball mechanism
	ofCircle (330, 625, 50);

	ofSetColor (0, 0, 0); //titanium space body
	ofRect(260, 450, 140, 175);

	ofSetColor (0, 255, 0); //space foil
	ofRect(260, 475, 140, 15);



	




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

