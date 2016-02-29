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
	test("hasAppropriateGetters()", hasAppropriateGetters());
	test("classHasCorrectStaticConstDEFAULT_DIMENSION()",
		 classHasCorrectStaticConstDEFAULT_DIMENSION());
    test("defaultBoxHasCorrectDefaultHeightWidthDepth()",
	     defaultBoxHasCorrectDefaultHeightWidthDepth());
	test("canInstantiateBoxProvidingHeightWidthDepth()",
		  canInstantiateBoxProvidingHeightWidthDepth());
	test("canNotInstantiateBoxWithInvalidDimensions()",
		 canNotInstantiateBoxWithInvalidDimensions());
	test("instantiatingWithInvalidDimensionUsesDefault()",
		 instantiatingWithInvalidDimensionUsesDefault());
	test("canNotInstantiateBoxWithInvalidHeight()",
		 canNotInstantiateBoxWithInvalidHeight());
	test("canNotInstantiateBoxWithInvalidWidth()",
		 canNotInstantiateBoxWithInvalidWidth());
	test("canNotInstantiateBoxWithInvalidDepth()",
		 canNotInstantiateBoxWithInvalidDepth());
	test("hasAppropriateSetters()", hasAppropriateSetters());
	test("settingInvalidHeightUsesDefault()",
		 settingInvalidHeightUsesDefault());
	test("settingInvalidWidthUsesDefault()",
		 settingInvalidHeightUsesDefault());
	test("settingInvalidDepthUsesDefault()",
		 settingInvalidHeightUsesDefault());
	test("boxShouldHaveCorrectVolume()",
		 boxShouldHaveCorrectVolume());
	return;
}

bool canInstantiateDefaultBox() {
	Box box;
	return true;
}

bool hasAppropriateGetters() {
	int h = 1;
	int w = 1;
	int d = 1;
	// Instantiate four boxes and check their dimensions.
	while (h < 5) {
		Box b(h, w, d);
		if (b.getHeight() != h && b.getWidth() != w && b.getDepth() != d) {
			return false;
		}
		++h; ++w; ++d;
	}
	return true;
}

bool classHasCorrectStaticConstDEFAULT_DIMENSION() {
	if (Box::DEFAULT_DIMENSION == 1) {
		return true;
	} else {
		return false;
	}
}

// A default box should have a height, width and depth of 1, respectively.
bool defaultBoxHasCorrectDefaultHeightWidthDepth() {
	Box box;
	if (box.getHeight() == Box::DEFAULT_DIMENSION &&
		box.getWidth() == Box::DEFAULT_DIMENSION &&
		box.getDepth() == Box::DEFAULT_DIMENSION) {
		return true;
	} else {
		return false;
	}
}

bool canInstantiateBoxProvidingHeightWidthDepth() {
	Box box(20, 30, 40);
	if (box.getHeight() == 20 && box.getWidth() == 30 && box.getDepth() == 40) {
		return true;
	} else {
		return false;
	}
}

bool canNotInstantiateBoxWithInvalidDimensions() {
	Box box(-20, -10, 0);
	if (box.getHeight() <=0 || box.getWidth() <= 0 || box.getDepth() <= 0) {
		return false;
	} else {
		return true;
	}
}

bool canNotInstantiateBoxWithInvalidHeight() {
	Box box(-20, 10, 10);
	if (box.getHeight() <=0) {
		return false;
	} else if (box.getWidth() == 10 && box.getDepth() == 10) {
		return true;
	} else return false;
}

bool canNotInstantiateBoxWithInvalidWidth() {
	Box box(10, -20, 10);
	if (box.getWidth() <=0) {
		return false;
	} else if (box.getHeight() == 10 && box.getDepth() == 10) {
		return true;
	} else return false;
}

bool canNotInstantiateBoxWithInvalidDepth() {
	Box box(10, 10, -20);
	if (box.getDepth() <= 0) {
		return false;
	} else if (box.getHeight() == 10 && box.getWidth() == 10) {
		return true;
	} else return false;
}

bool instantiatingWithInvalidDimensionUsesDefault() {
	Box box(-20, -10, 0);
	if (box.getHeight() == Box::DEFAULT_DIMENSION &&
		box.getWidth() == Box::DEFAULT_DIMENSION &&
		box.getDepth() == Box::DEFAULT_DIMENSION) {
		return true;
	} else {
		return false;
	}
}

bool hasAppropriateSetters() {
	Box b;
	int h = 1;
	int w = 1;
	int d = 1;
	while (h < 5) {
		b.setHeight(h);
		b.setWidth(w);
		b.setDepth(d);
		if (b.getHeight() != h && b.getWidth() != w && b.getDepth() != d) {
			return false;
		}
		++h; ++w; ++d;
	}
	return true;
}

bool settingInvalidHeightUsesDefault() {
	Box box(10, 10, 10);
	for (int i = -5; i <= 0; ++i) {
		box.setHeight(i);
		if (box.getHeight() != Box::DEFAULT_DIMENSION) {
			return false;
		}
	}
	return true;
}

bool settingInvalidWidthUsesDefault() {
	Box box(10, 10, 10);
	for (int i = -5; i <= 0; ++i) {
		box.setWidth(i);
		if (box.getWidth() != Box::DEFAULT_DIMENSION) {
			return false;
		}
	}
	return true;
}

bool settingInvalidDepthUsesDefault() {
	Box box(10, 10, 10);
	for (int i = -5; i <= 0; ++i) {
		box.setDepth(i);
		if (box.getDepth() != Box::DEFAULT_DIMENSION) {
			return false;
		}
	}
	return true;
}

bool boxShouldHaveCorrectVolume() {
	Box b;
	int h = 1;
	int w = 1;
	int d = 1;
	while (h < 5) {
		b.setHeight(h);
		b.setWidth(w);
		b.setDepth(d);
		if (b.getHeight() * b.getWidth() * b.getDepth() != b.volume()) {
			return false;
		}
		++h; ++w; ++d;
	}
	return true;
}