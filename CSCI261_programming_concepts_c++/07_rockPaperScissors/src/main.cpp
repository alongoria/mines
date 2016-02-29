/* CSCI261 Homework 07: rockPaperScissors
 *
 * Author: ADAM LONGORIA
*/
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {

	char p1, p2; 
	const char ROCK = 'R';
	const char PAPER = 'P';
	const char SCISSORS = 'S';
	const string P1_W = "Player one wins!";
	const string P2_W = "Player two wins!";
	const string RvsS = "Rock beats scissors.";
	const string PvsR = "Paper beats rock.";
	const string SvsP = "Scissors beats paper";

	cout << "The name of the game is Rock, Paper, Scissors!!! (Enter R, P, or S)" << endl; 
	cout << "Player 1 enter choice: ";
	cin >> p1; 
	cout << "Player 2 enter choice: ";
	cin >> p2;

	if ( (p1 <= 'z' && p1 >= 'a') ) {
		p1 = p1 - 32;} 
	if ( (p2 <= 'z' && p2 >= 'a') ) {
		p2 = p2 - 32;} 

	if ( (p1 == p2) ) {
		cout << "Draw" << endl; }
	
	if ( (p1 == ROCK && p2 == PAPER) || (p1 == PAPER && p2 == ROCK) ) {
		if ( (p1 == PAPER ) ) {
			cout << P1_W << endl; }
		else {
			cout << P2_W << endl; } 
	cout << PvsR << endl;
	}


	if ( (p1 == ROCK && p2 == SCISSORS) || (p1 == SCISSORS && p2 == ROCK) ) {
		if ( (p1 == ROCK ) ) {
			cout << P1_W << endl; }
		else {
			cout << P2_W << endl; } 
	cout << RvsS << endl;
	}


	if ( (p1 == SCISSORS && p2 == PAPER) || (p1 == PAPER && p2 == SCISSORS) ) {
		if ( (p1 == SCISSORS ) ) {
			cout << P1_W << endl; }
		else {
			cout << P2_W << endl; } 
	cout << SvsP << endl;
	}


    // Exit program.
    return 0;
}