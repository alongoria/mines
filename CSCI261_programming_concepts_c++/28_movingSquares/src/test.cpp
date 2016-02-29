#include "test.h"
#include "square.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// A generic test function, that simply prints "PASSED" if result is
// true and otherwise prints false.
void test(string testName, bool result) {
    cout.width(50);
    cout << testName;
    if (result) cout << " PASSED\n";
    else cout << " FAILED\n";
}

// Test suite executor. Calls test() for every unit test.
void runAllTests() {
    test("canInstantiateDefaultSquare()", canInstantiateDefaultSquare());
	test("canInstantiateSquareWithParameterizedConstructor()",
		  canInstantiateSquareWithParameterizedConstructor());
	test("hasAppropriateGetters()", hasAppropriateGetters());
	test("parameterizedConstructorAssignsValuesToMemberVariables()",
		  parameterizedConstructorAssignsValuesToMemberVariables());
	test("hasMemberFunctionMove()", hasMemberFunctionMove());
	test("squareMoveFunctionShouldUseSinForMotion()", squareMoveFunctionShouldUseSinForMotion());
	return;
}

// Because this program only uses the Square's parameterized constructor,
// we merely test for the ability to instantiate a default square.
// The default constructor does not have to do anything (unconventional).
bool canInstantiateDefaultSquare() {
	Square s;
	return true;
}

// The non-default constructor should accept six parameters:
// - int length
// - int r (red)
// - int g (green)
// - int b (blue)
// - int initX
// - int initY
// It should assign these values to private member variables sideLength,
// red, green, blue, x and y. (tested separately below)
// It should also assign initY to private member variable initialVerticalPosition.
bool canInstantiateSquareWithParameterizedConstructor() {
	Square s(100, 10, 20, 30, 2, 4);
	return true;
}

// Squares should move vertically via a move function.
// move() should accept one double parameter.
// The implementation for this method is provided.
bool hasMemberFunctionMove() {
	Square s(100, 10, 20, 30, 2, 4);
	s.move(0.0);
	return true;
}

// A Square should have the getters called below.
// All getters return ints (tested separately below).
bool hasAppropriateGetters() {
	Square s(100, 10, 20, 30, 2, 4);
	s.getSideLength();
	s.getRed();
	s.getGreen();
	s.getBlue();
	s.getX();
	s.getY();
	s.getInitialVerticalPosition();
	return true;
}

// The square's parameterized constructor should assign each of the six
// values to well-named member variables. Member variables are accessed
// via appropriate getters.
bool parameterizedConstructorAssignsValuesToMemberVariables() {
	Square s(100, 10, 20, 30, 2, 4);
	if (s.getSideLength() == 100 &&
		s.getRed() == 10 &&
		s.getGreen() == 20 &&
		s.getBlue() == 30 &&
		s.getX() == 2 &&
		s.getY() == 4 &&
		s.getInitialVerticalPosition() == 4) {
		return true;
	} else return false;
}

// The move function should use sin to generate sequences of positive
// and negative numbers. When move is called, it should assign a new
// value to the vertical position y.
// The value assigned to y should be the initialVerticalPosition plus
// sin of an angle passed to move(), times a "fun factor" of 34.
bool squareMoveFunctionShouldUseSinForMotion() {
	Square s(100, 10, 20, 30, 2, 250);
	s.move(20.0);
	if ( s.getY() == int(34 * sin(20.0) + s.getInitialVerticalPosition())) {
		return true;
	} else return false;
}