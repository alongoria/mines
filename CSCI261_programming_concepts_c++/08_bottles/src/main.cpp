/* CSCI261 Homework 08: bottles
 *
 * Author: ADAM LONGORIA
 *
 * This program prints the lyrics to an ever-popular song.
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
		
	int N;

	cout << "Enter a Number: "; 
	cin >> N;

	while (N > 2) {
		cout << N << " bottles of brew on the wall," << endl;
		cout << N << " bottles of brew!" << endl;
		cout << "Take 1 down, pass it around," << endl;
		cout << N-1 << " bottles of brew on the wall!" << endl << endl;
		N--;
	}

		cout << N << " bottles of brew on the wall," << endl;
		cout << N << " bottles of brew!" << endl;
		cout << "Take 1 down, pass it around," << endl;
		cout << N-1 << " bottle of brew on the wall!" << endl << endl;
		N--;

		cout << N << " bottle of brew on the wall," << endl;
		cout << N << " bottle of brew!" << endl;
		cout << "Take 1 down, pass it around," << endl;
		cout << N-1 << " bottles of brew on the wall!" << endl;


	
    // Exit program.
    return 0;

}