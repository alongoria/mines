#include "testApp.h"
#include "cell.h"

//Establishes running and setup states, to tell compiler when mousepresses are allowed, and also the number of cells.
bool running = false;
const int CELLS_ON_SIDE = 100;
const int CELL_SIZE = 9;
const int SPACE_SIZE = 1;

//Establishes the grids that will be drawn before and during the game's run
Cell initialGrid[CELLS_ON_SIDE][CELLS_ON_SIDE];
Cell updatedGrid[CELLS_ON_SIDE][CELLS_ON_SIDE];

//The function that begins running the 'Game of Life'
void theGame( Cell grid[CELLS_ON_SIDE][CELLS_ON_SIDE] ) {
	for (int i = 0; i < CELLS_ON_SIDE; i++) {
		for (int j = 0; j < CELLS_ON_SIDE; j++) {
			int livingCells = 0;
			bool topCell = false;
			bool bottomCell = false;
			bool rightCell = false;
			bool leftCell = false;
			updatedGrid[i][j].setCellState(false);

			//Tells the game whether or not the current cell is a corner or side cell
			if (j == 0) {
				topCell = true;
			} else if (j == (CELLS_ON_SIDE - 1) ) {
				bottomCell = true;
			}

			if (i == 0) {
				leftCell = true;
			} else if (i == (CELLS_ON_SIDE - 1) ) {
				rightCell = true;
			}


		//Actual game implementation, checking surrounding cells
			//Checks top and left
			if (!topCell && !leftCell) {
				if (grid[i-1][j-1].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks bottom and right
			if (!bottomCell && !rightCell) {
				if (grid[i+1][j+1].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks top and right
			if (!topCell && !rightCell) {
				if (grid[i+1][j-1].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks bottom and left
			if (!bottomCell && !leftCell) {
				if (grid[i-1][j+1].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks top
			if (!topCell) {
				if (grid[i][j-1].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks bottom
			if (!bottomCell) {
				if (grid[i][j+1].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks left
			if (!leftCell) {
				if (grid[i-1][j].getCellState() == true) {
					livingCells++;
				}
			}
			//Checks right
			if (!rightCell) {
				if (grid[i+1][j].getCellState() == true) {
					livingCells++;
				}
			}

		//Actual game implementation, given number of living cells
			//Rules for an unpopulated cell
			if (grid[i][j].getCellState() == false) {
				if (livingCells == 3) {
					updatedGrid[i][j].setCellState(true);
				}
			}
			//Rules for a populated cell
			else if (grid[i][j].getCellState() == true) {
				if (livingCells == 1 || livingCells == 0) {
					updatedGrid[i][j].setCellState(false);
				}
				if (livingCells >= 4) {
					updatedGrid[i][j].setCellState(false);
				}
				if (livingCells == 2 || livingCells == 3) {
					updatedGrid[i][j].setCellState(true);
				}
			}

			}
		
		}
		for (int m = 0; m < CELLS_ON_SIDE; m++) {
					for (int n = 0; n < CELLS_ON_SIDE; n++) {
						grid[m][n].setCellState(updatedGrid[m][n].getCellState());
		}

	}
}


//Clears the grid (implemented when r is pressed)
void clearGrid( Cell grid[CELLS_ON_SIDE][CELLS_ON_SIDE] ) {
	for (int i = 0; i < CELLS_ON_SIDE; i++) {
		for (int j = 0; j < CELLS_ON_SIDE; j++) {
			grid[i][j].setCellState(false);
		}
	}
}

void testApp::setup() {
	ofBackground(0,0,0);
	ofSetFrameRate(15);
}


void testApp::update() {
	if (running == true) {
		theGame(initialGrid);
		clearGrid(updatedGrid);
	}
}

//Draws a grid, and updates based on which cells are clicked (including on/off)
void testApp::draw() {
	for (int i = 0; i < CELLS_ON_SIDE; i++) {
		for (int j = 0; j < CELLS_ON_SIDE; j++) {
			if (initialGrid[i][j].getCellState() == true) {
				ofSetColor(255, 0, 0);
				ofRect( i*(CELL_SIZE + SPACE_SIZE), j*(CELL_SIZE + SPACE_SIZE), CELL_SIZE, CELL_SIZE);
			} else {
				ofSetColor(100, 100, 100); 
				ofRect( i*(CELL_SIZE + SPACE_SIZE), j*(CELL_SIZE + SPACE_SIZE), CELL_SIZE, CELL_SIZE);
			}
		}
	}
}

//Moves the game between running and setup states, and clears the grid if appropriate
void testApp::keyPressed(int key) {
	if (key == 'g') {
		if (running == true) {
			running = false;
		} else {
		running = true;
		} 
	}
		if (key == 'r') {
		clearGrid(initialGrid);
		running = false;
		}	
}



void testApp::keyReleased(int key) {

}


void testApp::mouseMoved(int x, int y ) {

}


void testApp::mouseDragged(int x, int y, int button) {

}

//Turns the cell on or off depending on what the cell's current state is (when the mouse is clicked)
void testApp::mousePressed(int x, int y, int button) {
	int cellX = x/(CELL_SIZE + SPACE_SIZE);
	int cellY = y/(CELL_SIZE + SPACE_SIZE);

	if (running == false) {
		if (initialGrid[cellX][cellY].getCellState() == false) {
			initialGrid[cellX][cellY].setCellState(true);
		} else {
			initialGrid[cellX][cellY].setCellState(false);
		}
	}
}



void testApp::mouseReleased(int x, int y, int button) {

}


void testApp::windowResized(int w, int h) {

}

