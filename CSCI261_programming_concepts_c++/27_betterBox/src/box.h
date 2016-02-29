#pragma once

class Box {
	public:
		Box();
		Box(int h, int w, int d);
		int getHeight();
		int getWidth();
		int getDepth();
		void setHeight(int h);
		void setWidth(int w);
		void setDepth(int d);
		int volume();
		static const int DEFAULT_DIMENSION = 1;

	private:
		int height;
		int width;
		int depth;


};


