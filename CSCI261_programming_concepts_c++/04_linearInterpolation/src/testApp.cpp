#include "testApp.h"
#include <sstream>
#include <string>
#include <iostream>

/* This function takes five parameters. The "x and y" values
 * for two points of data, and the "x" value of the desired point,
 * whose "y" value you will calculate.
 * 
 * We haven't covered C++ functions yet, so you can ignore everything you see
 * except the line that says "return 0."
 *
 * Change the "0" to the expression for linear interpolation, using the formula in
 * your textbook, page 65.
 *
 * We are "giving" you five variables: a, fA, c, fC and b.
 * Why didn't we use variable names f(a) and f(c) like they are in the book?
 *
*/
double testApp::interpolate(double a, double fA, double c, double fC, double b) {
	return (fA + ((b - a)/(c - a))*(fC - fA));
}


//--------------------------------------------------------------
void testApp::setup(){
	xLeft = 0;
	yLeft = 423;
	xRight = 500;
	yRight = 39;
	xSnap = 0;
	ySnap = 0;
	diPedFont.loadFont("dipedthick.ttf", 32);
	arialFont.loadFont("arial.ttf", 9);
	ofEnableSmoothing();
	// Do not modify the following line.
	std::cout << "TEST: " << interpolate(0.0, 500.0 - 423.0, 500.0, 500.0 - 39.0, 250.0) << endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(33, 33, 33);
	
	ofSetColor(0x9DB3C0);
	diPedFont.drawString("Function Value: " + ofToString(interpolatedValue, 2), 10, 30);

	ofSetColor(0x486C52);
	arialFont.drawString("(" + ofToString(xLeft) + "," + ofToString(500 - yLeft) + ")", 10, yLeft);
	arialFont.drawString("(" + ofToString(xRight) + "," + ofToString(500 - yRight) + ")", xRight - 60, yRight);

	ofSetColor(0xB05b32);
	ofSetLineWidth(5);
	ofLine(xLeft, yLeft, xRight, yRight);
	
	ofSetColor(0xECAE73);
	ofSetLineWidth(0.5);
	ofLine(mouseX, 500, mouseX, 0);
	arialFont.drawString(ofToString(mouseX, 1), mouseX + 10, 400);

	drawReticle(xSnap, 500 - ySnap);
}

void testApp::drawReticle(int x, int y) {
	ofSetColor(0x9DB3C0);
	ofCircle(x, y, 6);
	ofSetColor(55,55,55);
	ofCircle(x - 2, y - 2, 1);
	ofCircle(x + 2, y - 2, 1);
	ofLine(x - 2, y + 2, x + 2, y + 2);
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	mouseX = (double)x;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	double x1 = (double)xLeft;
	double y1 = (double)(500-yLeft);
	double x2 = (double)xRight;
	double y2 = (double)(500-yRight);
	double mouseX = (double)x;
	ySnap = interpolatedValue = interpolate(x1, y1, x2, y2, mouseX);
	xSnap = mouseX;
	// std::cout << "Test: " << mouseX << "," << interpolatedValue << endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

