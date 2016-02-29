#include <iostream>
#include <string>
#include <vector>
#include <queue>
//#include <windows.h>
using namespace std;

const char WALL = '#';
const char OPEN = '.';
const char BREAD = '!';
const char START = 'o';
const char END = '*';
const char NONE = ' ';
//char** maze_ray;
char maze_ray[16][16];

void path(int x, int y, int width, int height, bool &solved) {

	// print out maze
	///*
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			char m = maze_ray[i][j];	
			cout << m;
		}
		cout << endl;
	}
	//*/


	// check if at the end
	if (maze_ray[x][y] == END) solved = true;
	
	// lay down breadcrumb at current loaction 
	maze_ray[x][y] = BREAD;

	
	// recursively search for end
	/*	
	// west
	if (x > 0 && maze_ray[x - 1][y] != WALL && maze_ray[x - 1][y] != BREAD && maze_ray[x - 1][y] != NONE && path(x - 1, y, width, height, solved)) {
		return true;
	}
	// east 
	if (x < (width - 1) && maze_ray[x + 1][y] != WALL && maze_ray[x + 1][y] != BREAD && maze_ray[x + 1][y] != NONE && path(x + 1, y, width, height, solved)) {
		return true;
	}
	// south 
	if (y < (height - 1) && maze_ray[x][y + 1] != WALL && maze_ray[x][y + 1] != BREAD && maze_ray[x][y + 1] != NONE && path(x , y + 1, width, height, solved)) {
		return true;
	}
	// north
	if (y > 0 && maze_ray[x][y - 1] != WALL && maze_ray[x][y - 1] != BREAD && maze_ray[x][y - 1] != NONE && path(x, y - 1, width, height, solved)) {
		return true;
	}
	*/
	
	// west
	if (x > 0 && maze_ray[x - 1][y] != WALL && maze_ray[x - 1][y] != BREAD && maze_ray[x - 1][y] != NONE) {
		if (solved == false) path(x - 1, y, width, height, solved);
	}
	// south 
	if (y < (height - 1) && maze_ray[x][y + 1] != WALL && maze_ray[x][y + 1] != BREAD && maze_ray[x][y + 1] != NONE) {
		if (solved == false) path(x , y + 1, width, height, solved);
	}

	// east 
	if (x < (width - 1) && maze_ray[x + 1][y] != WALL && maze_ray[x + 1][y] != BREAD && maze_ray[x + 1][y] != NONE) {
		if (solved == false) path(x + 1, y, width, height, solved);
	}
	// north
	if (y > 0 && maze_ray[x][y - 1] != WALL && maze_ray[x][y - 1] != BREAD && maze_ray[x][y - 1] != NONE) {
		if (solved == false) path(x, y - 1, width, height, solved);
	}

	
	// clean up breadcrumbs
	maze_ray[x][y] = OPEN;
}

bool has_solution(vector<string> maze) {

	int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
	const int width = maze[0].size();
	const int height = maze.size();
	bool solved = false;
	/*
	maze_ray = new char*[height];
	for (int i = 0; i < height; i++) {
		maze_ray[i] = new char[width];
	}
	*/

	// find starting and ending postition 
	for (int j = 0; j < height; j++) {
		string current = maze[j];
		for (int i = 0; i < width; i++) {
			maze_ray[j][i] = current[i];
			if (current[i] == START) {
				start_x = j;
				start_y = i;
			}
			else if (current[i] == END) {
				end_x = j;
				end_y = i;
			}
		}

	}
	/*
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			cout << maze_ray[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << maze_ray[1][6] << endl;
	cout << maze_ray[5][1] << endl;
	cout << start_x << " " << start_y << " " << end_x << " " << end_y << " " << endl;


	path(start_x, start_y, width, height, solved); 

	//return path(start_x,start_y, end_x, end_y, width, height);
	cout << "Solved equals: " << solved << endl;
	if (solved == true) return true;
	return false;
}



void print_maze_vector(vector<string> maze) {
	for (int i = 0; i < maze.size(); i++) {
		cout << maze[i] << endl;
	}
	cout << endl;
}

/*
int main() {
	vector<string> corn, stuff; 
	corn.push_back("########");
	corn.push_back("#.##..*#");
	corn.push_back("#.##.###");
	corn.push_back("#o...#.#");
	corn.push_back("########");
	print_maze_vector(corn);
	//cout << has_solution(corn) << endl;

	stuff.push_back("########");
	stuff.push_back("#.##..*#");
	stuff.push_back("#.##.###");
	stuff.push_back("#o#..###");
	stuff.push_back("#.##...#");
	cout << has_solution(stuff) << endl;


	return 0;
}
*/
