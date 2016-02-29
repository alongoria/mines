#include "square.h"
#include <cmath>

Square::Square() {
}

Square::Square(int length, int r, int g, int b, int initX, int initY) {
	sideLength = length;
	red = r;
	green = g;
	blue = b;
	x = initX;
	y = initY;
	initialVerticalPosition = initY;
}

int Square::getRed() {
	return red;
}

int Square::getGreen() {
	return green;
}

int Square::getBlue() {
	return blue;
}

int Square::getX() {
	return x;
}

int Square::getY() {
	return y;
}

int Square::getSideLength() {
	return sideLength;
}

int Square::getInitialVerticalPosition() {
	return initialVerticalPosition;
}
void Square::move(double angle) {
	y = 34 * sin(angle) + initialVerticalPosition;
}

