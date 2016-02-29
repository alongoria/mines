#include <iostream>
#include <string>

using namespace std;

int last_box(int carrots[], size_t num_boxes, int amount) {
	
	int last_box_eaten = 0;

	for (int ii = 0; ii < amount; ii++) {
		int max_box = 0;
		int max_box_size = 0;

		for (int jj = 0; jj < num_boxes; jj++) {
			if (carrots[jj] > max_box_size) {
				max_box = jj;
				max_box_size = carrots[jj];
			}
		}

		carrots[max_box]--;
		last_box_eaten = max_box;
	}
	system("pause");
	return last_box_eaten;
}

/*

int main() {
	const int num_boxes = 2;
	int amount = 4;
	int c[num_boxes] = {5, 8};

	last_box(c, num_boxes, amount);
	return 0;
}

*/