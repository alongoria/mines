#include <iostream>
#include <fstream>
#include <cmath>
#include "testApp.h"
#include "square.h"


const string CONFIG_FILENAME = "data\\colors.cfg.txt";
const int SIDE_LENGTH = 100;
const int INITIAL_VERTICAL_POSITION = 250;
int numberOfSquares = 0;
vector<Square> squares;
double angle = 0;

void generateSquares() {
	ifstream colors(CONFIG_FILENAME);

	if (!colors) {
		cout << "There was a problem opening the color config file.\n";
		return;
	}

	int r, g, b;

	while (colors >> r >> g >> b) {
		Square s(SIDE_LENGTH, r, g, b, numberOfSquares * SIDE_LENGTH, INITIAL_VERTICAL_POSITION);
		squares.push_back(s);
		++numberOfSquares;
	}

	colors.close();
}

void moveSquares() {
	for (int i = 0; i < numberOfSquares; ++i) {
		squares.at(i).move(angle);
	}
}

void updateMovementAmount() {
	angle += 0.1;
}

void drawSquares() {
	for (int i = 0; i < numberOfSquares; ++i) {
		ofSetColor(squares.at(i).getRed(), squares.at(i).getGreen(), squares.at(i).getBlue());
		ofRect(squares.at(i).getX(), squares.at(i).getY(), 100, 100);
	}
}

void testApp::setup() {
	generateSquares();
}

void testApp::update() {
	moveSquares();
	updateMovementAmount();
}

void testApp::draw() {
	drawSquares();
}

//--------------------------------------------------------------

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

