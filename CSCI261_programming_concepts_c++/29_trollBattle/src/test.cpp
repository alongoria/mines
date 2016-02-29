#include "test.h"
#include "troll.h"
#include "battle.h"
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
    test("canInstantiateDefaultTroll()", canInstantiateDefaultTroll());
	test("canInstantiateTrollWithName()", canInstantiateTrollWithName());
	test("trollHasPublicAttributeName()", trollHasPublicAttributeName());
	test("trollHasPublicAttributeHealth()", trollHasPublicAttributeHealth());
	test("trollHasPublicAttributeStrength()", trollHasPublicAttributeStrength());
	test("instantiatedTrollHasPositiveHealthLessThanOneHundredOne()", instantiatedTrollHasPositiveHealthLessThanOneHundredOne());
	test("instantiatedTrollHasPositiveStrengthLessThanEleven()", instantiatedTrollHasPositiveStrengthLessThanEleven());
	test("trollHasMemberFunctionAttack()", trollHasMemberFunctionAttack());
	test("globalFunctionBattleExistsAndAcceptsTwoTrolls()", globalFunctionBattleExistsAndAcceptsTwoTrolls());
	test("globalFunctionDeclareWinnerExistsAndAcceptsTwoTrolls()", globalFunctionDeclareWinnerExistsAndAcceptsTwoTrolls());
	
	return;
}

bool canInstantiateDefaultTroll() {
	Troll t;
	return true;
}

bool trollHasPublicAttributeName() {
	Troll t("Violet");
	t.name;
	return true;
}

bool canInstantiateTrollWithName() {
	Troll t("Violet");
	if (t.name == "Violet") {
		return true;
	} else return false;
}

bool trollHasPublicAttributeHealth() {
	Troll t("Violet");
	t.health;
	return true;
}

bool trollHasPublicAttributeStrength() {
	Troll t("Violet");
	t.strength;
	return true;
}

bool instantiatedTrollHasPositiveHealthLessThanOneHundredOne() {
	for (int i = 0; i < 10; ++i) {
		Troll t("Violet");
		if (t.health < 0 || t.health > 100) {
			return false;
		}
	}
	return true;
}

bool instantiatedTrollHasPositiveStrengthLessThanEleven() {
	for (int i = 0; i < 10; ++i) {
		Troll t("Violet");
		if (t.strength < 0 || t.strength > 10) {
			return false;
		}
	}
	return true;
}

bool trollHasMemberFunctionAttack() {
	Troll t("Violet");
	Troll s("Hamlet");
	t.attack(s);
	return true;
}

bool globalFunctionBattleExistsAndAcceptsTwoTrolls() {
	Troll t("Violet");
	Troll s("Hamlet");
	fight(t, s);
	return true;
}

bool globalFunctionDeclareWinnerExistsAndAcceptsTwoTrolls() {
	Troll t("Violet");
	Troll s("Hamlet");
	declareWinner(t, s);
	return true;
}
