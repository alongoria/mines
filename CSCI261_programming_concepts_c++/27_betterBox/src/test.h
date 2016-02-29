#pragma once

void test(bool result);
void runAllTests();
bool canInstantiateDefaultBox();
bool hasAppropriateGetters();
bool defaultBoxHasCorrectDefaultHeightWidthDepth();
bool canInstantiateBoxProvidingHeightWidthDepth();
bool canNotInstantiateBoxWithInvalidDimensions();
bool canNotInstantiateBoxWithInvalidHeight(); 
bool canNotInstantiateBoxWithInvalidWidth();
bool canNotInstantiateBoxWithInvalidDepth();
bool classHasCorrectStaticConstDEFAULT_DIMENSION();
bool instantiatingWithInvalidDimensionUsesDefault();
bool hasAppropriateSetters();
bool settingInvalidHeightUsesDefault();
bool settingInvalidWidthUsesDefault();
bool settingInvalidDepthUsesDefault();
bool boxShouldHaveCorrectVolume();
