#include "walker.h"
#include <cstdlib>

Walker::Walker() {
	x = 395;
	y = 395;
	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;
}


void Walker::walk() {
	if (rand() % 2 == 1) { 
		if (rand() % 2 == 1) { 
			x += 1;
		}
		else {
			x-= 1;
		}
	} else {
		if (rand() % 2 == 1) { 
			y += 1;
		}
		else {
			y-= 1;
		}
	}
}


