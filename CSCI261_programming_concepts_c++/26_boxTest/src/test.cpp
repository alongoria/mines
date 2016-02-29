#include "test.h"
#include "box.h"
#include <iostream>
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
    test("canInstantiateDefaultBox()", canInstantiateDefaultBox());
    test("defaultBoxHasCorrectDefaultHeightWidthDepth()",
	     defaultBoxHasCorrectDefaultHeightWidthDepth());
	test("canInstantiateBoxProvidingHeightWidthDepth()",
		  canInstantiateBoxProvidingHeightWidthDepth());
	return;
}

bool canInstantiateDefaultBox() {
	Box box;
	return true;
}

// A default box should have a height, width and depth of 1, respectively.
bool defaultBoxHasCorrectDefaultHeightWidthDepth() {
	Box box;
	if (box.height == 1 && box.width == 1 && box.depth == 1) {
		return true;
	} else {
		return false;
	}
}

bool canInstantiateBoxProvidingHeightWidthDepth() {
	Box box(20, 30, 40);
	if (box.height == 20 && box.width == 30 && box.depth == 40) {
		return true;
	} else {
		return false;
	}
}