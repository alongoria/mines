#include <iostream>
#include <string>
#include <cmath>

int least_borders(int x[], int y[], int r[], size_t n,
	int x1, int y1, int x2, int y2) {

	int border = 0;

	for (int k = 0; k < n; k++) {
		int start_in = 0;
		int end_in = 0;
		double q_dist = sqrt(pow((x1 - x[k]), 2) + pow((y1 - y[k]), 2));
		double end_dist = sqrt(pow((x2 - x[k]), 2) + pow((y2 - y[k]), 2));

		if (q_dist < r[k]) {
			start_in = 1;
		}
		if (end_dist < r[k]) {
			end_in = 1;
		}
		if ((start_in + end_in) == 1) {
			border++;
		}
	}

	return border;
}

/*
int main() {
	return 0;
}
*/