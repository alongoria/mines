#pragma once

class Square {
	public:
		Square();
		Square(int length, int r, int g, int b, int initX, int initY);
		int getRed();
		int getGreen();
		int getBlue();
		int getX();
		int getY();
		int getSideLength();
		int getInitialVerticalPosition();
		void move(double angle);

	private:
		int sideLength;
		int red;
		int green;
		int blue;
		int x;
		int y;
		int initialVerticalPosition;

};

