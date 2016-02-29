#include "testApp.h"
#include "Cell.h"

vector<Cell> c;

void testApp::setup() {
	ofBackground(0,0,0);
}

void testApp::update() {

}


void testApp::draw() {
	ofSetColor(255,255,255);
	for (int c = 10; c < 1000; c += 10) {
		ofRect(c,0,1,1000);
		ofRect(0,c,1000,1);
	}

	for ( int i = 0; i < c.size(); i++) {
		ofSetColor(c.at(i).red,c.at(i).green,c.at(i).blue);
		ofCircle(c.at(i).x,c.at(i).y,c.at(i).rad);
	}
}


void testApp::keyPressed(int key) {

}


void testApp::keyReleased(int key) {

}


void testApp::mouseMoved(int x, int y ) {

}


void testApp::mouseDragged(int x, int y, int button) {

}


void testApp::mousePressed(int x, int y, int button) {
	for (int t = 0; t < 1000; t += 10) { 
		if (x >= t && x <= t + 10) {
			x = t + 6;
		}
		if (y >= t && y <= t + 10) {
			y = t + 6;
		}
	}
	Cell test(x,y);
	/*if (test.status = true) {
		test.status = false;
		test.red = 0;
		test.green = 0;
		test.blue = 0;
	} else if (test.status == false) {
		test.status = true;
	}*/
	c.push_back(test);

	/*for(int n = 0; n < 1000; n += 10) {
		if ((x >= n && x <= n + 10) && (y >= n && y <= n + 10) && c.at(n).status == true) {
			c.at(n).status = false;
			c.at(n).red = 0;
			c.at(n).green = 0;
			c.at(n).blue = 0;
		}
	}*/

}


void testApp::mouseReleased(int x, int y, int button) {
	
}


void testApp::windowResized(int w, int h) {

}

