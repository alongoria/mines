#include <iostream>
#include <string>

using namespace std;

int need(int marks[], size_t sz) {
	double sum = 0, average = 0, needed = 0;

	// calculate sum of the scores
	for (int j = 0; j < sz; j++) {
		sum += marks[j];
	}

	// this way worked too, online graded did not like :(
	/*
	average = sum / sz;
	while (average != 9.5) {
		sum += 10;
		sz++;
		average = sum / sz;
		needed += 1;
	}
	*/

	// solved the following constraint equation using TI - nSpire CAS
	//		9.5 = (sum + 10 * needed) / (sz + needed)

	needed = 19 * (sz - sum * .10523615789474);

	// cast number into an int type to truncate digits right of the radix point
	needed = int(needed);

	// equation will return negative numbers, those will just be set to zero
	if (needed < 0) {
		needed = 0;
	}

	return needed;
}


/*
int main() {

int g[] = {8,9};
need(g, 2);
return 0;
}
*/