#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "model.h"

using namespace std;

// Brute force character generator
string brute_model::generate(int sz) {

	// copy first k characters to back to simulate wrap-around
	string working_data = data + data.substr(0, order);

	// pick random k-character substring as initial seed
	int start = rand() % (data.length() - order);
	string seed = working_data.substr(start, order);

	vector<char> list;
	string answer;
	answer.reserve(sz);

	for (int i = 0; i < sz; i++) {
		list.clear();
		int pos = working_data.find(seed);
		while (pos != string::npos && pos < data.length()) {
			char c = working_data[pos + order];
			list.push_back(c);
			pos = working_data.find(seed, pos + 1);
		}
		char c = list[rand() % list.size()];
		answer.push_back(c);
		seed = seed.substr(1) + c;
	}

	return answer;
}

string map_model::generate(int sz) {
	// copy first k characters to back to simulate wrap-around
	string working_data = data + data.substr(0, order);

	// pick random k-character substring as initial seed
	int start = rand() % (data.length() - order);
	string seed = working_data.substr(start, order);
	int pos = working_data.find(seed);

	//Create a map
	map<string, vector<char>> somemap;

	//Read through the data, and for every string, use the [] operator to create or update the key with a value of the following character
	for (int i = 0; i < working_data.size() - order; i++) {
		string somestring = working_data.substr(i, order);
		char somechar = working_data.at(i + order);
		//If we have found the string before, we update the map's vector
		if (somemap.find(somestring) != somemap.end()) {
			vector<char> somevector = somemap[somestring];
			somevector.push_back(somechar);
			somemap[somestring] = somevector;
		}
		//Otherwise, we insert the key and value pair into the map
		else {
			vector<char> somevector;
			somevector.clear();
			somevector.push_back(somechar);
			somemap.insert(pair<string, vector<char>>(somestring, somevector));
		}
	}
	cout << "Map created" << endl;

	//Printing the map
	/*for(map<string, vector<char> >::const_iterator it = somemap.begin(); it != somemap.end(); ++it) {
	std::cout << it->first << " ";
	vector<char> somevector = it->second;
	for( std::vector<char>::const_iterator i = somevector.begin(); i != somevector.end(); ++i) {
	std::cout << *i << ' ';
	}
	cout << endl;
	}*/

	// Creating our random text
	string answer;
	answer.reserve(sz);
	for (int i = 0; i < sz; i++) {
		//Generate a random letter from our vector
		vector<char> somevector = somemap[seed];
		//cout << somevector[rand() % somevector.size()];
		char somechar = somevector[rand() % somevector.size()];
		answer.push_back(somechar);
		seed = seed.substr(1) + somechar;
	}

	return answer;
}

string umap_model::generate(int sz) {
	// copy first k characters to back to simulate wrap-around
	string working_data = data + data.substr(0, order);

	// pick random k-character substring as initial seed
	int start = rand() % (data.length() - order);
	string seed = working_data.substr(start, order);
	int pos = working_data.find(seed);

	//Create a map
	unordered_map<string, vector<char>> somemap;

	//Read through the data, and for every string, use the [] operator to create or update the key with a value of the following character
	for (int i = 0; i < working_data.size() - order; i++) {
		string somestring = working_data.substr(i, order);
		char somechar = working_data.at(i + order);
		//If we have found the string before, we update the map's vector
		if (somemap.find(somestring) != somemap.end()) {
			vector<char> somevector = somemap[somestring];
			somevector.push_back(somechar);
			somemap[somestring] = somevector;
		}
		//Otherwise, we insert the key and value pair into the map
		else {
			vector<char> somevector;
			somevector.clear();
			somevector.push_back(somechar);
			somemap.insert(pair<string, vector<char>>(somestring, somevector));
		}
	}
	cout << "Map created" << endl;

	//Printing the map
	/*for(map<string, vector<char> >::const_iterator it = somemap.begin(); it != somemap.end(); ++it) {
	std::cout << it->first << " ";
	vector<char> somevector = it->second;
	for( std::vector<char>::const_iterator i = somevector.begin(); i != somevector.end(); ++i) {
	std::cout << *i << ' ';
	}
	cout << endl;
	}*/

	// Creating our random text
	string answer;
	answer.reserve(sz);
	for (int i = 0; i < sz; i++) {
		//Generate a random letter from our vector
		vector<char> somevector = somemap[seed];
		//cout << somevector[rand() % somevector.size()];
		char somechar = somevector[rand() % somevector.size()];
		answer.push_back(somechar);
		seed = seed.substr(1) + somechar;
	}

	return answer;
}

string word_model::generate(int sz) {
	//Create a vector with all of the words from the data
	vector<string> thewords;
	istringstream thefile(data);

	while (!thefile.eof()) {
		string s;
		thefile >> s;
		thewords.push_back(s);
	}

	//Wrap around the end words to the start
	for (int i = 0; i < order; i++) {
		thewords.push_back(thewords[i]);
	}

	//Pick a random word plus the words that follow it as initial seed
	vector<string> theseed;
	int startindex = rand() % thewords.size();
	for (int i = 0; i < order; i++) {
		theseed.push_back(thewords[startindex + i]);
	}

	//Print the initial seed
	/*for( std::vector<string>::const_iterator i = theseed.begin(); i != theseed.end(); ++i) {
	std::cout << *i << ' ';
	}*/

	//Create a map
	map<string, string> somemap;
	//Read through the data, and for every string, use the [] operator to create or update the key with a value of the following character
	for (int i = 0; i < thewords.size() - order; i++) {
		//Create the key
		string thekey;
		thekey.clear();
		for (int j = 0; j < order; j++) {
			thekey.append(thewords[i + j]);
			thekey.push_back(' ');
		}
		string newvalue = thewords[i + order];
		newvalue.push_back(' ');
		//If we have found the key before, we update the map's vector
		if (somemap.find(thekey) != somemap.end()) {
			string thevalue = somemap[thekey];
			thevalue.append(newvalue);
			somemap[thekey] = thevalue;
		}
		//Otherwise, we insert the key and value pair into the map
		else {
			somemap.insert(pair<string, string>(thekey, newvalue));
		}
	}

	//Printing the map
	/*for(map<string, string>::const_iterator it = somemap.begin(); it != somemap.end(); ++it) {
	std::cout << it->first << " " << it->second << endl;
	}*/

	// Creating our random text
	string answer;
	for (int i = 0; i < sz; i++) {
		//Generate a random word given our seed
		//First, change our seed vector to a string
		string theseed2;
		for (int i = 0; i < theseed.size(); i++) {
			theseed2.append(theseed[i]);
			theseed2.push_back(' ');
		}

		//Get the value from the map using the string
		string possibilities = somemap[theseed2];

		//Load the value into a vector of strings so we can choose 1 at random
		vector<string> thepossibilities;
		istringstream somefile(possibilities);
		while (!somefile.eof()) {
			string t;
			somefile >> t;
			if (t != "") {
				thepossibilities.push_back(t);
			}
		}

		//Choose a word at random and do stuff with it
		string toappend = thepossibilities[rand() % thepossibilities.size()];
		answer.append(toappend);
		answer.push_back(' ');
		theseed.erase(theseed.begin());
		theseed.push_back(toappend);
	}
	return answer;
}
