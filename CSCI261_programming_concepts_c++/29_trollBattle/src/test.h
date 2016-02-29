#pragma once

void test(bool result);
void runAllTests();
bool canInstantiateDefaultTroll();
bool canInstantiateTrollWithName();
bool trollHasPublicAttributeName();
bool trollHasPublicAttributeHealth();
bool trollHasPublicAttributeStrength();
bool instantiatedTrollHasPositiveHealthLessThanOneHundredOne();
bool instantiatedTrollHasPositiveStrengthLessThanEleven();
bool trollHasMemberFunctionAttack();
bool globalFunctionBattleExistsAndAcceptsTwoTrolls();
bool globalFunctionDeclareWinnerExistsAndAcceptsTwoTrolls();