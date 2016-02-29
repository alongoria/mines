#include "testApp.h"
#include "walker.h"
#include <vector>
using namespace std;

// declare a const integer to represent the number of walkers

const int NUMBER_OF_WALKERS = 666;

// declare a vector of walkers

vector<Walker> w;

// This function should pushes some number of Walker objects onto the vector.
void testApp::setup() {
	ofBackground (0, 0, 0);
	for (int i = 0; i < NUMBER_OF_WALKERS; i++) {
		Walker rand;
		w.push_back(rand); 
	}
}

// This function causes each Walker object in the vector to walk (take one step).
void testApp::update() {
	for (int x = 0; x < NUMBER_OF_WALKERS; x++) {
		w.at(x).walk();
	}
}

// This function draws each Walker in the vector at its respective x/y position.
// It draws each walker as a 10x10 square, using the particular Walker object's color.
void testApp::draw() {
	for (int z = 0; z < NUMBER_OF_WALKERS; z++) {
		ofSetColor(w.at(z).red, w.at(z).green, w.at(z).blue);
		ofRect(w.at(z).x, w.at(z).y, 10, 10);
	}
}


// ---------------------------------------------------

void testApp::keyPressed(int key) {

}


void testApp::keyReleased(int key) {

}


void testApp::mouseMoved(int x, int y ) {

}


void testApp::mouseDragged(int x, int y, int button) {

}


void testApp::mousePressed(int x, int y, int button) {

}


void testApp::mouseReleased(int x, int y, int button) {

}


void testApp::windowResized(int w, int h) {

}

