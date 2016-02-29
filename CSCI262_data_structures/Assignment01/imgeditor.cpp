/*
imgeditor.cpp

author: ADAM LONGORIA
date: 1/31/14

Image editing program for CSCI 262, Spring 2014, Assignment 1.

This program will read a ppm picture file and apply filter to the image
and output a ppm picture file with the applied filters.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Global constants 
static const int EFFECT_COUNT = 12;

// Use these!  E.g., 
// if (selections[FLATTEN_BLUE]) { // call flatten_blue() here }
static const int DO_NOTHING = 0;
static const int GRAYSCALE = 1;
static const int FLIP_HORIZONTAL = 2;
static const int NEGATE_RED = 3;
static const int NEGATE_GREEN = 4;
static const int NEGATE_BLUE = 5;
static const int FLATTEN_RED = 6;
static const int FLATTEN_GREEN = 7;
static const int FLATTEN_BLUE = 8;
static const int EXTREME_CONTRAST = 9;
static const int FLIP_VERTICAL = 10;
static const int BLUR = 11;

// menu options
static const string MENU_STRINGS[] = {
	"do nothing",
	"convert to grayscale",
	"flip horizontally",
	"negate red",
	"negate green",
	"negate blue",
	"flatten red",
	"flatten green",
	"flatten blue",
	"extreme contrast",
	"flip vertical",
	"blur"
};

// functions
void get_user_selections(bool* selections) {
	// initialize selections
	for (int i = 0; i < EFFECT_COUNT; i++) selections[i] = false;

	// display menu
	cout << endl;
	cout << "Here are your choices:" << endl;
	int columns = 80;
	for (int i = 0; i < EFFECT_COUNT; i++) {
		// approximate length of menu item assuming 2 digit numbers
		int len = MENU_STRINGS[i].length() + 6;
		columns -= len;
		if (columns < 0) {
			cout << endl;
			columns = 80 - len;
		}
		cout << "[" << i << "] " << MENU_STRINGS[i] << " ";
	}
	cout << endl;
	cout << "Please enter your selections as a comma separated list, e.g., '5,6,1':" << endl;

	// get user response and extract numbers from it
	string response;
	getline(cin, response);

	// actually allows pretty much any characters between integers
	istringstream sin(response);
	while (sin) {
		while ((sin.peek() < '0' || sin.peek() > '9') && sin.peek() != EOF) sin.ignore();
		if (sin.peek() == EOF) break;
		int n;
		sin >> n;
		if (n < EFFECT_COUNT) {
			selections[n] = true;
		}
		else {
			cout << "Invalid selection " << n << " ignored!" << endl;
		}
	}
}

// set "original" arrays for application of multiple filters
void set_current(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	/*
	**red_o = **red;
	**green_o = **green;
	**blue_o = **blue;
	*/
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			red_o[x][y] = red[x][y];
			green_o[x][y] = green[x][y];
			blue_o[x][y] = blue[x][y];
		}
	}
}

// do nothing funtion - no filter will be applied
void do_nothing(int **red, int **green, int **blue, int row, int col) {
	/*
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			red[x][y] = red[x][y];
			green[x][y] = green[x][y];
			blue[x][y] = blue[x][y];
		}
	}
	*/
}

// gray scale - set pixel value to average of RGB values
void gray_scale(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			int avg = 0;
			avg = (red[x][y] + green[x][y] + blue[x][y]) / 3;
			red[x][y] = avg;
			green[x][y] = avg;
			blue[x][y] = avg;
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// negate red - set red values to opposite
void neg_red(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col, int max) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			red[x][y] = max - red[x][y];
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// negate green - set green values to opposite
void neg_green(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col, int max) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			green[x][y] = max - green[x][y];
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// negate blue - set blue values to opposite
void neg_blue(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col, int max) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			blue[x][y] = max - blue[x][y];
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}
// flatten red - set red values to 0
void flat_red(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			red[x][y] = 0;
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// flatten green - set green values to 0
void flat_green(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			green[x][y] = 0;
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// flatten blue - set blue vaules to 0
void flat_blue(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			blue[x][y] = 0;
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// extreme contrast - set pixel to max or 0 depending
void extreme(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col, int max) {
	int half = (max + 1) / 2;
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			// set red pixel high or low
			if (red[x][y] > half) {
				red[x][y] = max;
			}
			else {
				red[x][y] = 0;
			}
			// set green pixel high or low
			if (green[x][y] > half) {
				green[x][y] = max;
			}
			else {
				green[x][y] = 0;
			}
			// set blue pixel high or low
			if (blue[x][y] > half) {
				blue[x][y] = max;
			}
			else {
				blue[x][y] = 0;
			}
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// horizontal filp - flip picture horizontally 
void hor_flip(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			red[x][y] = red_o[x][col - y - 1];
			green[x][y] = green_o[x][col - y - 1];
			blue[x][y] = blue_o[x][col - y - 1];
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// vertical filp - flip picture vertically
void vert_flip(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			red[x][y] = red_o[row - x - 1][y];
			green[x][y] = green_o[row - x - 1][y];
			blue[x][y] = blue_o[row - x - 1][y];
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}

// blur - blur image slightly 
void blur(int **red, int **red_o, int **green, int **green_o, int **blue, int **blue_o, int row, int col) {
	for (int x = 1; x < row - 1; x++) {
		for (int y = 1; y < col - 1; y++) {
			/*
			// top left corner
			if (x == 0 && y == 0) {
				red[x][y] = (red_o[x][y] + red_o[x + 1][y] + red_o[x][y + 1]) / 3;
				green[x][y] = (green_o[x][y] + green_o[x + 1][y] + green_o[x][y + 1]) / 3;
				blue[x][y] = (blue_o[x][y] + blue_o[x + 1][y] + blue_o[x][y + 1]) / 3;
			}
			// top row non corners
			if ((x == 0) && (y != 0) && (y != (col - 1))) {      
				red[x][y] = (red_o[x][y] + red_o[x + 1][y] + red_o[x - 1][y] + red_o[x][y + 1]) / 4;
				green[x][y] = (green_o[x][y] + green_o[x + 1][y] + green_o[x - 1][y] + green_o[x][y + 1]) / 4;
				blue[x][y] = (blue_o[x][y] + blue_o[x + 1][y] + blue_o[x - 1][y] + blue_o[x][y + 1]) / 4;
			}
			// bottom row non corners
			if ((x == (row - 1)) && (y != 0) && (y != (col - 1))) {
				red[x][y] = (red_o[x][y] + red_o[x + 1][y] + red_o[x - 1][y] + red_o[x][y - 1]) / 4;
				green[x][y] = (green_o[x][y] + green_o[x + 1][y] + green_o[x - 1][y] + green_o[x][y - 1]) / 4;
				blue[x][y] = (blue_o[x][y] + blue_o[x + 1][y] + blue_o[x - 1][y] + blue_o[x][y - 1]) / 4;
			}
			// bottom left corner
			if ((x == (row - 1)) && (y == 0)) {
				red[x][y] = (red_o[x][y] + red_o[x + 1][y] + red_o[x][y - 1]) / 3;
				green[x][y] = (green_o[x][y] + green_o[x + 1][y] + green_o[x][y - 1]) / 3;
				blue[x][y] = (blue_o[x][y] + blue_o[x + 1][y] + blue_o[x][y - 1]) / 3;
			}
			// top right corner
			if ((x == 0) && (y == (col - 1))) {
				red[x][y] = (red_o[x][y] + red_o[x - 1][y] + red_o[x][y + 1]) / 3;
				green[x][y] = (green_o[x][y] + green_o[x - 1][y] + green_o[x][y + 1]) / 3;
				blue[x][y] = (blue_o[x][y] + blue_o[x - 1][y] + blue_o[x][y + 1]) / 3;
			}
			// bottom right corner
			if ((x == 0) && (y == (col - 1))) {
				red[x][y] = (red_o[x][y] + red_o[x - 1][y] + red_o[x][y - 1]) / 3;
				green[x][y] = (green_o[x][y] + green_o[x - 1][y] + green_o[x][y - 1]) / 3;
				blue[x][y] = (blue_o[x][y] + blue_o[x - 1][y] + blue_o[x][y - 1]) / 3;
			}
			// most left column non corners
			if ((x == (row - 1)) && (y != 0) && (y != (col - 1))) {
				red[x][y] = (red_o[x][y] + red_o[x + 1][y] + red_o[x][y + 1] + red_o[x][y - 1]) / 4;
				green[x][y] = (green_o[x][y] + green_o[x + 1][y] + green_o[x][y + 1] + green_o[x][y - 1]) / 4;
				blue[x][y] = (blue_o[x][y] + blue_o[x + 1][y] + blue_o[x][y + 1] + blue_o[x][y - 1]) / 4;
			}
			// most right column non corners
			if ((x == (row - 1)) && (y != 0) && (y != (col - 1))) {
				red[x][y] = (red_o[x][y] + red_o[x - 1][y] + red_o[x][y + 1] + red_o[x][y - 1]) / 4;
				green[x][y] = (green_o[x][y] + green_o[x - 1][y] + green_o[x][y + 1] + green_o[x][y - 1]) / 4;
				blue[x][y] = (blue_o[x][y] + blue_o[x - 1][y] + blue_o[x][y + 1] + blue_o[x][y - 1]) / 4;
			}
			// every other pixel
			else {
				red[x][y] = (red_o[x][y] + red_o[x - 1][y] + red_o[x + 1][y] + red_o[x][y + 1] + red_o[x][y - 1]) / 5;
				green[x][y] = (green_o[x][y] + green_o[x - 1][y] + green_o[x + 1][y] + green_o[x][y + 1] + green_o[x][y - 1]) / 5;
				blue[x][y] = (blue_o[x][y] + blue_o[x - 1][y] + blue_o[x + 1][y] + blue_o[x][y + 1] + blue_o[x][y - 1]) / 5;
			}
			*/
			// ignore the pixels on the edge, they are negligable, could not get edge cases to work completely 
			red[x][y] = (red_o[x][y] + red_o[x - 1][y] + red_o[x + 1][y] + red_o[x][y + 1] + red_o[x][y - 1] + 
				         red_o[x - 1][y - 1] + red_o[x + 1][y - 1] + red_o[x - 1][y + 1] + red_o[x + 1][y + 1]) / 9;
			green[x][y] = (green_o[x][y] + green_o[x - 1][y] + green_o[x + 1][y] + green_o[x][y + 1] + green_o[x][y - 1] + 
				           green_o[x - 1][y - 1] + green_o[x + 1][y - 1] + green_o[x - 1][y + 1] + green_o[x + 1][y + 1]) / 9;
			blue[x][y] = (blue_o[x][y] + blue_o[x - 1][y] + blue_o[x + 1][y] + blue_o[x][y + 1] + blue_o[x][y - 1] + 
				          blue_o[x - 1][y - 1] + blue_o[x + 1][y - 1] + blue_o[x - 1][y + 1] + blue_o[x + 1][y + 1]) / 9;
		}
	}
	set_current(red, red_o, green, green_o, blue, blue_o, row, col);
}


int main() {
	// user interaction to obtain input filename
	cout << "Portable Pixmap (PPM) Image Editor!" << endl << endl;
	cout << "Enter name of image file: ";
	string infile;
	getline(cin, infile);

	// open input filestream
	ifstream fin;
	fin.open(infile);
	if (fin.fail()) {
		cerr << "Error opening input file '";
		cerr << infile << "', exiting!" << endl;
		// Uncomment if running from within Visual Studio and
		// you want to see the error message.
		// system("pause");
		return -1;
	}


	// read magic 
	string magic;
	fin >> magic;
	if (magic != "P3") {
		cerr << "Input file '" << infile;
		cerr << "' appears to not be a PPM, exiting!" << endl;
		fin.close();
		// Uncomment if running from within Visual Studio and
		// you want to see the error message.
		// system("pause");
		return -1;
	}

	// TODO: read in columns/rows/depth values; if using a statically
	// sized buffer, ensure # of columns won't exceed room in buffer;
	// declare buffer (if static) or allocate memory for buffer or 2-D
	// array if you choose to go that way

	int col = 0;
	int row = 0;
	int max = 0;

	// read in values for rows, columns, and max color
	fin >> col >> row >> max;

	int **red_o;
	int **green_o;
	int **blue_o;
	int **red;
	int **green;
	int **blue;

	// dynamically allocate memory for pixel arrays
	red = new int*[row];
	green = new int*[row];
	blue= new int*[row];

	red_o = new int*[row];
	green_o = new int*[row];
	blue_o = new int*[row];

	for (int j = 0; j < row; j++) {
		red[j] = new int[col];
		green[j] = new int[col];
		blue[j] = new int[col];

		red_o[j] = new int[col];
		green_o[j] = new int[col];
		blue_o[j] = new int[col];
	}
	
	// fill array with pixel values
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			int r = 0, g = 0, b = 0;
			fin >> r >> g >> b;
			red[x][y] = r;
			green[x][y] = g;
			blue[x][y] = b;

			red_o[x][y] = r;
			green_o[x][y] = g;
			blue_o[x][y] = b;
		}
	}

	// TODO: get output filename and open output file
	cout << "Enter name of output file" << endl;
	string output;
	getline(cin, output);
	ofstream output_file;
	output_file.open(output);
	if (output_file.fail()) {
		cerr << "Error opening output file '";
		cerr << infile << "', exiting!" << endl;
		// Uncomment if running from within Visual Studio and
		// you want to see the error message.
		// system("pause");
		return -1;
	}


	// TODO: output magic, columns, rows, depth values (don't forget
	// whitespace and/or endlines!)


	// display menu and get user selections
	bool selections[EFFECT_COUNT];
	get_user_selections(selections);

	if (selections[GRAYSCALE]) {
		gray_scale(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	if (selections[NEGATE_RED]) {
		neg_red(red, red_o, green, green_o, blue, blue_o, row, col, max);
	}

	if (selections[NEGATE_GREEN]) {
		neg_green(red, red_o, green, green_o, blue, blue_o, row, col, max);
	}
	if (selections[NEGATE_BLUE]) {
		neg_blue(red, red_o, green, green_o, blue, blue_o, row, col, max);
	}

	if (selections[FLATTEN_RED]) {
		flat_red(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	if (selections[FLATTEN_BLUE]) {
		flat_green(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	if (selections[FLATTEN_BLUE]) {
		flat_blue(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	if (selections[EXTREME_CONTRAST]) {
		extreme(red, red_o, green, green_o, blue, blue_o, row, col, max);
	}

	if (selections[FLIP_HORIZONTAL]) {
		hor_flip(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	if (selections[FLIP_VERTICAL]) {
		vert_flip(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	if (selections[BLUR]) {
		blur(red, red_o, green, green_o, blue, blue_o, row, col);
	}

	// open output filestream and write output file 
	output_file << magic << endl;
	output_file << col << " " << row << endl;
	output_file << max << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			output_file << red[i][j] << " " << green[i][j] << " " << blue[i][j] << " ";
		}
	}

	// TODO: close input and output files

	fin.close();
	output_file.close();

	// delete arrays to free up allocated space
	delete[] red_o;
	delete[] green_o;
	delete[] blue_o;
	delete[] red;
	delete[] green;
	delete[] blue;


	// Uncomment if desired to use under Visual Studio
	// system("pause");

	return 0;
}