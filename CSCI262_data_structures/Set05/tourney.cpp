#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string winner(vector<string> bracket, string results) {

	queue<string> teams;
	int X = 0;

	// push teams onto the bracket 
	for (int i = 0; i < bracket.size(); i++) {
		teams.push(bracket[i]);
	}

	while (teams.size() != 1) {
		// set current teams into temps
		string a_team = teams.front();
		teams.pop();
		string b_team = teams.front();
		teams.pop();
		// check for byes
		if (a_team == "bye") teams.push(b_team);
		else if (b_team == "bye") teams.push(a_team);
		// check for winner
		else if (results[X] == 'H') {
			teams.push(a_team); X++;
		}
		else if (results[X] == 'L') {
			teams.push(b_team); X++;
		}
	}
	
	cout << teams.front() << endl;
	return teams.front();
}

/*
int main() {
	vector<string> bracket = { "DUKE", "UCLA", "bye", "MIT" };
	string results = "HL";
	winner(bracket, results);
	system("pause");
	return 0;
}
*/