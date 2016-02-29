#include <string>
#include "constants.h"

using namespace std;

// The name to display in the banner. Personalize this with your first name (or nickname).
const string NAME = "Adam";

/* Certainly you've heard of the acronym "RGB?"
 * That stands for Red, Green and Blue. A computer can "mix" different kinds of reds,
 * greens and blues together to create any color. The amount of red, green or blue is
 * based on a scale from 0 to 255 (256 or 2^8 possible values).
 * Therefore, black consists of RGB values 0, 0 and 0; white is 255, 255, 255.
 * Make the banner a cool color besides white.
*/
const int BANNER_COLOR_RED = 255;
const int BANNER_COLOR_GREEN = 0;
const int BANNER_COLOR_BLUE = 0;

// Where the left side of the banner should start, in pixels. This distance is measured
// from the left side of the window. Adjust this so the banner is centered.
const int LEFT_MARGIN = 250;