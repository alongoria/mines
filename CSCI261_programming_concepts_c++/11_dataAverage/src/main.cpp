/* CSCI261 Homework 11: dataAverage
 *
 * Author: ADAM LONGORIA
 *
 * This program reads in population numbers from a text file and prints the average.
 *
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	int pop;
	int tpop = 0;
	int cities = 0;
	double avg;
	const string POPULATIONS = "populations.txt";

	ifstream populations(POPULATIONS.c_str());

	if (!populations) {
		cerr << "Error opening input file";
		exit(1);
		}
	
	while (populations >> pop) {
		tpop += pop;
		cities++;
		}
	
	populations.close();

	avg  = (double(tpop)/cities);

	cout << "The average population of America's " << cities << " cities is " << avg << "." << endl;

    // Exit program.
    return 0;

}