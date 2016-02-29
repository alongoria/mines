/* CSCI261 Homework 14: volumeFunction
 *
 * Author: ADAM LONGORIA
 *
 * This program uses a function to calculate the volume of a sphere.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

// this returns volume of radius r.
double sphereVolume(int r) {
	return ((4.0/3.0)*(PI)*(pow(r,3.0)));
}

int main() {
	int r;
	cout << "Hello, I will calculate the volume of a sphere if you tell me the radius." << endl;
	cout << "Enter the radius of a sphere: ";
	cin >> r;
	cout << "The volume of a sphere with radius " << r << " is " << sphereVolume(r) << " units cubed." << endl;
	cout << "WHOA YEAH!!" << endl;
	
    // Exit program.
    return 0;

}