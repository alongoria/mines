/* CSCI261 Homework 09: bottles
 *
 * Author: ADAM LONGORIA
 *
 * This program prints the lyrics to an ever-popular song.
*/
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {

	
	// x=total#, y=taken/time
	int x,y;
	string product; 

	cout << "I am SongMachine v2.6, I will generate music for you.\n";
	cout << "Enter desired product: ";
	getline (cin,product);

	while (true) {
		cout << "Enter a number of bottles, between 0 and 1000: ";
		cin >> x;
		if (x > 0 && x < 1000) {
			break;
		} else {
			cout << "Can you read! (0 - 1000) only.\n";
		}
    
	}

	while (true) {
		cout << "Enter a number taken at a time, between 0 and 10: ";
		cin >> y;
		if (y > 0 && y < 10) {
			break;
		} else {
			cout << "Can you read! (0 - 10) only.\n";
		}
    
	}


 	for (x; x>0 && x>=y; x-=y) {
		cout << x << " bottles of " << product << " on the wall," << endl;
		cout << x << " bottles of " << product << "!" << endl;
		
		if(y>1) {
			cout << "Take " << y << " down, pass them around," << endl;
		} else {
			cout << "Take " << y << " down, pass it around," << endl;
		}
		

		if(x-y==1) {
			cout << x-y << " bottle of " << product << " on the wall!" << endl << endl;
			cout << 1 << " bottle of " << product << " on the wall," << endl;
			cout << 1 << " bottle of " << product << "!" << endl;
			cout << "Take 1 down, pass it around," << endl;
			cout << "0 bottles of " << product << " on the wall!!!" << endl << endl;

		} else {
			cout << x-y << " bottles of " << product << " on the wall!" << endl << endl;
		}

	}

	for (x; x>0 && x<y; x--) {
		if(x>1) {
			cout << x << " bottles of " << product << " on the wall," << endl;
			cout << x << " bottles of " << product << "!" << endl;
		} else {
			cout << x << " bottle of " << product << " on the wall," << endl;
			cout << x << " bottle of " << product << "!" << endl;
		}
		cout << "Take 1 down, pass it around," << endl;
		if(x-1==1) {
			cout << x-1 << " bottle of " << product << " on the wall!!!" << endl << endl;
		} else {
			cout << x-1 << " bottles of " << product << " on the wall!!!" << endl << endl;
		}

	}	
		
	


    // Exit program.
    return 0;

}