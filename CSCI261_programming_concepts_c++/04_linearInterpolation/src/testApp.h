#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class testApp : public ofBaseApp{

	public:

		int xLeft, yLeft, xRight, yRight, xSnap, ySnap;
		double mouseX;
		double interpolatedValue;
		ofTrueTypeFont diPedFont;
		ofTrueTypeFont arialFont;

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		void drawReticle(int x, int y);
		double interpolate(double a, double fA, double C, double fC, double b); 

};

#endif
