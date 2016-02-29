/* CSCI261 Homework 03: aircraft
 *
 * Author: ADAM LONGORIA
 *
 * Below you will find the program listing from section 2.8, page 81. This program
 * computes the new velocity and acceleration of a UDF-powered aircraft after a change
 * in power level.
 * 
 * First, READ THE PROGRAM and be sure you understand how it works. Consult the text
 * and your lecture notes for help. 
 *
 * Modify the program according to the homework instructions and rubric.
 * 
*/
#include <iostream>  // Provides us with cin and cout.
#include <iomanip>   // Provides us with setprecision().
#include <cmath>     // Provides us pow().
using namespace std;

int main() {

	// Variable declarations
	double time_min, time_sec, velocity, acceleration, meters_to_feet;
	double a, b, c, d, e; 
	a = 0.00001;
	b = 0.00488;
	c = 0.75795;
	d = 181.3566; 
	e = 0.000062;
	// conversion: 1m = 3.280839ft
	meters_to_feet = 3.280839;

	// Get the time value from the keyboard.
	cout << "This program calculates the velocity and acceleration of UDF-powered aircraft" << endl;
	cout << "after a change in power level." << endl;
	cout << "Enter the new time value in MINUTES: \n";
	cin >> time_min;
	time_sec = time_min*60;
	 
	

	// Compute velocity and acceleration.
	// Velocity: a * time_sec^3 - b * time_sec^2 + c * time_sec + d
	// Acceleration: 3 - d * velocity^2
	velocity = (a * pow(time_sec, 3) - b * pow(time_sec, 2) + c * time_sec + d);
	acceleration = (3 - e * pow(velocity, 2));

	velocity = velocity * meters_to_feet;
	acceleration = acceleration * meters_to_feet;

	// Print the velocity and acceleration.
	cout << fixed << setprecision(3); // Print numbers with a fixed-point precision of 3 decimal places.
	cout << "Velocity = " << velocity << " ft/s" << endl;
	cout << "Acceleration = " << acceleration << " ft/s^2" << endl;

    // Exit program.
    return 0;

}