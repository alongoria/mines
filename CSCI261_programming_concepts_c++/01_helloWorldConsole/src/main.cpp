/* CSCI261 Homework 01: helloWorldConsole
 *
 * Author: ADAM LONGORIA
 *
 * Below you will find the example program presented in class, to help you get started.
 *
 * First, READ THE PROGRAM and be sure you understand how it works. Consult your lecture notes for help.
 *
 * Second, YES, REALLY, READ THE PROGRAM.
 *
 * Modify the program below, such that the program prints your name and the correct
 * approximate value of pi.
 *
*/
#include <cstdlib>   // "Computer, include the standard library so my program isn't boring."
#include <iostream>  // "Computer, include the iostream library so I can use cin and cout."
#include <string>    // "Computer, include the string library so I can use text longer than one character."
#include <fstream>
#include <cmath>
using namespace std;

int mult(int x, int y);
int mult(int x, int y);

void Uncle(int x);

void uncle(int x);

void uNcle(int x);

int main() {

	/*

    const string NAME = "You";
	const double PI = 1.234;

    cout << "Hello " << NAME << ", it's so very nice to meet you." << endl;
	cout << "Did you know that the constant pi is approximately " << PI << "?" << endl;
	cout << "Hmm... what's that smell?" << endl << endl;

    int x = -10;
    int y = 10;
    while(x<y) {
        ++x;
        y += x % 2;
        cout << x << " " << y << endl;
        }

    int a;
    a = -9 % 2;
    cout << a;


    int x;
    cout << "enter positive integer: ";
    while(true) {
        cin >> x;
        if (x >= 0) {
            break;
        }
        else {
            cout << "positive integers only: ";
        }
    }
    
	

  int x;
  char y;

  const string in = "number_file.txt";
  const string out = "number_out.txt";

  ifstream IN(in.c_str());
  ofstream OUT(out.c_str());

  if(!IN) {
	  cerr << "Error with input file";
	  exit(1);
  }
  if(!OUT) {
	  cerr << "Error with output file";
	  exit(1);
  }

  while(IN >> x >> y) {
	  if((y >= 'a' && y < 'z') || (y >= 'A' && y < 'Z')) {
		  y += 1;
	  } 
	  else if (y == 'z') {
		  y = 'a';
	  }
	  else if (y == 'Z') {
		  y = 'A';
	  }
	  OUT << x << " " << y << endl;
  }
  IN.close();
  OUT.close();

  int num;
 
  cout << "enter + number: ";
  cin >> num;

  while(num < 0) {
	  cout << "Positive!!!!: ";
	  cin >> num;
  }



	
	int asd = mult(-2,-9);
	cout << asd;
	int x = 5;

	int c = 0;
	while(x > 0) {
		if(c < x) {
			cout << "Uncle!! ";
			c++;
		}else{
			cout << "\n";
			x--;
			continue;
		}
	
	}
	
    // Exit program.

	*/

	Uncle(3);
	uncle(3);
	uNcle(3);

	

	int z = mult(123862,-192);
	cout << z;
	cout << "\n";

	int p = 0;
	bool corn, watery, brown;

	cout << "Does your dirt bike not work?: ";
	cin >> corn;

	cout << "Is it a Honda?: ";
	cin >> watery;

	cout << "Are you adrian?: ";
	cin >> brown;

	if(corn) {
		p += 1;
	}

	if(watery) {
		p += 1;
	}

	if(brown) {
		p += 1;
	}

	if(p == 3) {
		cout << "shouldve got a yamaha!!!";
	}
    return 0;

}

int mult (int left, int right) {
	int answer = 0;
	bool b = 0;

	if (left < 0) {
		b = 1;
		left /= -1;
	}

	for(int i = 0; i < left ; i++) {
		answer += right;
	}
	if (b) {
		answer /= -1;
	}
	return answer;

}


void Uncle(int x) {
	
	while(x > 0) {
		int c = 0;
		
		while(c < x) {
			cout << "Nigga please!! ";
			c++;
		}
		cout << "\n";
		x--;
	}
}

void uncle(int x) {
	for (x; x > 0; x--){
		for(int y = 0; y < x; y++) {
			cout << "a; l k sjdf  lajd!! ";
		}
		cout << "\n";
	}
}

void uNcle(int x) {
	if(x <= 0) {
		return;
	}
	for(int i = x; i > 0; i--) {
		cout << "Niggas be trippin!! ";
	}
	cout << "\n";
	uNcle(x-1);
}

int Mult(int left, int right) {
	int answer = 0;
	bool t = 0;

	if(left < 0) {
		t = 1;
		left /= -1;
	}

	for(left; left > 0; left--) {
		answer += right;
	}
	if(t) {
		answer /= -1;
	}
	return answer;
	
}

