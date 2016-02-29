#include "Cell.h"
#include <cstdlib>

Cell::Cell() {
	red = 250;
	green = 0;
	blue = 0;
	rad = 4.5;
	x = 56;
	y = 56;
}

Cell::Cell(int a, int b) {
	x = a; y = b;
	red = 250;
	green = 0;
	blue = 0;
	rad = 4.5;
	status = true;
}


/*void Cell::setStatus() {
	if (status == true) {
		status = alive;
	}
	else {
		false;
	}
}

*/

		
