/* CSCI261 Homework 02: sphereVolume
 *
 * Author: ADAM LONGORIA		
 *
 * Below you will find the example program presented in class, to help you get started.
 * 
 * First, READ THE PROGRAM and be sure you understand how it works. Consult your lecture notes for help. 
 *
 * Second, YES, REALLY, READ THE PROGRAM.
 *
 * Modify the program below, such that it prompts the user for a radius, and prints
 * the volume of a sphere with that radius. BE SURE to consult the rubric (twice!) before
 * submitting this assignment.
*/
#include <cstdlib>   // "Computer, include the standard library so my program isn't boring."
#include <iostream>  // "Computer, include the iostream library so I can use cin and cout."
using namespace std;

int main() {

    double radius;   // "Computer, allocate enough memory to store a yet-to-be-determined decimal number. Call it length."
    double volume;
	const double pi = 3.14159265;


    cout << "Enter a radius: ";
	cin >> radius;

    /* Volume of a sphere is ((4/3)piR^3). */
    volume = ((4.0/3.0)*(pi)*(radius*radius*radius));

    /* Print the volume. */
    cout << "The volume is " << volume;
    cout << " units cubed!" << endl;

    // Exit program.
    return 0;

}