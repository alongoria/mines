#pragma once

class Cell {
	bool alive;	
public:
	Cell();
	int red, green, blue;
	void setCellState(bool b);
	bool getCellState();
};