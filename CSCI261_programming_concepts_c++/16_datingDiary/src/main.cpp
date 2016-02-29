/* CSCI261 Homework 16: datingDiary
 *
 * Author: ADAM LONGORIA
 *
 * This program records a little information about your Mines dating life and
 * saves the data to an external file.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//prompt function accepts one string and displays message on screen
void prompt(string message) {
	cout << message;
}

//captureInt function accepts one string and two intergers, and returns one interger  
int captureInt(string message, int min, int max) {
	int number; 
	while (true) {
		cout << message << "(" << min << " to " << max << "): ";
		cin >> number;
		if ((number <= max) && (number >= min)) {
			break;	
		}
	}

	cin.ignore();
	return number;
}

//captureString function accepts one string and returns one string 
string captureString(string message) {
	string words;
	cout << message;
	getline(cin, words);
	return words;
}

//save function accepts four strings and two intergers and writes values to an output file
void save(string FILENAME, string dateOfDate, string name, int age, string favoriteFood, int rating) {
	ofstream file;
	file.open(FILENAME.c_str(), ios_base::app);

	if (!file) {
		cerr << "Error opening output file";
		exit(1);
	}

	file << "Date: " << dateOfDate << endl;
	file << "Name: " << name << endl;
	file << "Age: " << age << endl;
	file << "Favorite Food: " << favoriteFood << endl;
	file << "Rating: " << rating << endl << endl;

	file.close();
}


int main() {

    const string FILENAME = "dates.txt";
    const int MIN_AGE = 18;
    const int MAX_AGE = 25;
    const int MIN_RATING = 1;
    const int MAX_RATING = 5;

    int age, rating;
    string name, favoriteFood, dateOfDate;

    prompt("Welcome to the date tracker.\n");

    // Capture date information
    dateOfDate = captureString("Date of date (eg 10/22/11): ");
    name = captureString("Date's name: ");
    age = captureInt("Date's age ", MIN_AGE, MAX_AGE);
    favoriteFood = captureString("Date's favorite food: ");
    rating = captureInt("Rate your date ", 1, 5);

    save(FILENAME, dateOfDate, name, age, favoriteFood, rating);

    prompt("Your date has been recorded.\n");

    // Exit program.
    return 0;

}