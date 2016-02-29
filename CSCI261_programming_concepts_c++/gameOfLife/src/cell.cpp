#include "cell.h"
#include <cstdlib>

Cell::Cell() {
	alive = false;
	red = rand() % 255;
	green =  rand() % 255;
	blue = rand() % 255;
}

void Cell::setCellState(bool b) {
	alive = b;
}

bool Cell::getCellState() {
	return alive;
}