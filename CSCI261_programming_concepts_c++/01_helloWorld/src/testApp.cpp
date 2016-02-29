#include "testApp.h"
#include "constants.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);
	collegeFont.loadFont("colleged.ttf", 32);

	ofSetFrameRate(30);
	ofSetVerticalSync(true);

	glEnable(GL_DEPTH_TEST); //enable depth comparisons and update the depth buffer
	ofDisableArbTex(); //needed for textures to work with gluSphere
	earth.loadImage("earth.jpg");
	
	//prepare quadric for sphere
	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(BANNER_COLOR_RED, BANNER_COLOR_GREEN, BANNER_COLOR_BLUE);
	collegeFont.drawString(NAME + " lives here", LEFT_MARGIN, 50);
	
	ofSetColor(0xFFFFFF);

	//change origin to center
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);

	//rotate sphere over time
	ofRotateY(ofGetFrameNum());
	ofRotateX(-90); //north pole facing up

	//bind and draw texture
	earth.getTextureReference().bind();
	gluSphere(quadric, 200, 100, 100);


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

