#include <iostream>
#include <string>
#include <vector>


using namespace std;

const char WALL = 'X';
const char OPEN = '.';
const char BREAD = '!';
const char START = 'R';
const char END = 'C';
const char NONE = ' ';
char mazed[16][16];
int net = 0;
int start_x, start_y, end_x, end_y;

void print_maze() {
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			cout << mazed[x][y];
		}
		cout << endl;
	}
}

void path(int x, int y, int width, int height) {

	// print out maze
	print_maze();


	// check if at the end
	if (x == end_x && y == end_y) net++;

	// lay down breadcrumb at current loaction 
	mazed[x][y] = BREAD;


	// recursively search for end

	// west
	if (x > 0 && mazed[x - 1][y] != WALL && (x > end_x)) {
		path(x - 1, y, width, height);
	}
	// east
	if (x < (width - 1) && mazed[x + 1][y] != WALL && (x < end_x)) {
		path(x + 1, y, width, height);
	}
	// south
	if (y < (height - 1) && mazed[x][y + 1] != WALL && (y < end_y)) {
		path(x, y + 1, width, height);
	}
	// north
	if (y > 0 && mazed[x][y - 1] != WALL && (y > end_y)) {
		path(x, y - 1, width, height);
	}

	// clean up breadcrumbs
	mazed[x][y] = OPEN;

}

int num_routes(vector<string> maze) {

	const int width = maze[0].size();
	const int height = maze.size();
	net = 0;

	// find starting and ending postition 
	for (int j = 0; j < height; j++) {
		string current = maze[j];
		for (int i = 0; i < width; i++) {

			mazed[i][j] = current[i];
			if (current[i] == START) {
				start_x = i;
				start_y = j;
			}
			if (current[i] == END) {
				end_x = i;
				end_y = j;
			}
		}

	}
	
	path(start_x, start_y, width, height);

	return net;
}




/*
int main() {
	vector<string> themaze = {	".R...",
								"..X..",
								"....X",
								"X.X.X",
								"...C."};
	vector<string> themaze2 = {
		".R...",
		"..X..",
		"....X",
		"X.X.X",
		"...C." };
	num_routes(themaze2);
	cout << "The number of routes is " << net << endl;
	system("Pause");
	return 0;
}
*/
