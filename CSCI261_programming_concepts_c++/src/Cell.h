#pragma once 
using namespace std;

class Cell {
	public:
		Cell();
		Cell(int a, int b);
		int red;
		int green;
		int blue;
		double rad;
		int x;
		int y;
		bool status;
		void setStatus();
};