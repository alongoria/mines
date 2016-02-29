#include "box.h"

Box::Box() {
	height = 1;
	width = 1;
	depth = 1;
}

Box::Box(int h, int w, int d) {
	if (h > 0) {
		height = h;
	}
	else {
		height = DEFAULT_DIMENSION;
	}
	if (w > 0) {
		width = w;
	}
	else {
		width = DEFAULT_DIMENSION;
	}
	if (d > 0) {
		depth = d;
	}
	else {
		depth = DEFAULT_DIMENSION;
	}
}

int Box::getHeight() {
	return height;
}

int Box::getWidth() {
	return width;
}

int Box::getDepth() {
	return depth;
}

void Box::setHeight(int h) {
	if (h > 0) {
		height = h;
	}
	else {
		height = DEFAULT_DIMENSION;
	}
}

void Box::setWidth(int w) {
	if (w > 0) {
		width = w;
	}
	else {
		width = DEFAULT_DIMENSION;
	}
}

void Box::setDepth(int d) {
	if (d > 0) {
		depth = d;
	}
	else {
		depth = DEFAULT_DIMENSION;
	}
}

int Box::volume() {
	return height*width*depth;
}
	

