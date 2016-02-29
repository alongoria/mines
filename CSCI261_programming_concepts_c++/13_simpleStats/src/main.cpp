/* CSCI261 Homework 13: simpleStats
 *
 * Author: ADAM LONGORIA	
 *
 * This program reads a variety of population data from a file as input and writes some
 * simple stats about the data to a new file.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	int pop;
	int counter = 0;
	int maxpop = 0, minpop = 0;
	int p_range;
	double tpop = 0;
	double area;
	double density;
	double p_avg, a_avg, d_avg;
	double tarea = 0;
	double tdensity = 0;
	double a_range, d_range;
	double maxarea = 0, minarea = 0, maxdensity = 0, mindensity = 0; 
	const string POPULATIONS = "populations.txt";

	ifstream populations(POPULATIONS.c_str());
	ofstream stats("population_stats.txt");

	if (!populations) {
		cerr << "Error opening input file";
		exit(1);
		}
	if (!stats) {
		cerr << "Error opening output file";
		exit(1);
		}
		
	
	while (populations >> pop >> area >> density) {
		counter++;
		tpop += pop;
		tarea += area;
		tdensity += density;
		if (pop >= maxpop) {
			maxpop = pop;
		}
		if (area >= maxarea) {
			maxarea = area;
		}
		if (density >= maxdensity) {
			maxdensity = density;
		}
		if (pop < minpop || minpop == 0) {
			minpop = pop;
		}
		if (area < minarea || minarea == 0) {
				minarea = area;
		}
		if (density < mindensity || mindensity == 0) {
			mindensity = density;
		}
	}

	p_avg = tpop/counter, a_avg = tarea/counter, d_avg = tdensity/counter;
	p_range = maxpop-minpop, a_range = maxarea-minarea, d_range = maxdensity-mindensity;

		
	stats << "Population statistics of America's " << counter << " cities." << endl;
	stats << "Statistic\t Average\t Min\t Max\t Range" << endl;
	stats << "Population\t " << p_avg << "\t\t" << minpop << "\t" << maxpop << "\t" << p_range << endl;
	stats << "Land Area\t " << a_avg << "\t" << minarea << "\t" << maxarea << "\t" << a_range << endl;
	stats << "Density\t\t " << d_avg << "\t" << mindensity << "\t" << maxdensity << "\t" << d_range << endl;
	
	populations.close();
	stats.close();
    // Exit program.
    return 0;

}