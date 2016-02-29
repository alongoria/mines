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
using namespace std;

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
        /*++x;
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
    */



    const string FILE = "number_file.txt";
    const string OUT = "number_out.txt";

    ifstream in( FIlE.c_str() );
    ofstream out( OUT.c_str() );

    if (!in) {
        cerr << "Errors";
        exit(1);
        }


    if (!out) {
        cerr << "Errors";
        exit(1);
        }

    

       
    // Exit program.
    return 0;

}
