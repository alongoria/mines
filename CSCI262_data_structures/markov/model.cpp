#include <string>
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
			pos = working_data.find(seed, pos+1);
		}
		char c = list[rand() % list.size()];
		answer.push_back(c);
		seed = seed.substr(1) + c;
	}

	return answer;
}

string map_model::generate(int sz) {
	// copy k chars to back
	string working_data = data + data.substr(0, order);
	
	// pick random k-char substring for seed
	int start = rand() % (data.length() - order);
	string seed = working_data.substr(start, order);
	int pos = working_data.find(seed);

	// create a map
	map<string, vector<char>> stuff;

	// read data, create/update key values for the chars
	for (int i = 0; i < working_data.size() - order; i++) {
		string stringy = working_data.substr(i, order);
		char chary = working_data.at(i + order);
		// if found, update vector
		if (stuff.find(stringy) != stuff.end()) {
			vector<char> vecty = stuff[stringy];
			vecty.push_back(chary);
			stuff[stringy] = vecty;
		}
		// else, insert key and value pair
		else {
			vector<char> vecty;
			vecty.clear();
			vecty.push_back(chary);
			stuff.insert(pair<string, vector<char>> (stringy, vecty));
		}
	}
	cout << "Map created" << endl;

	// print map
	for (map<string, vector<char>>::const_iterator it = stuff.begin(); it != stuff.end(); ++it) { 
		cout << it->first << " ";
		vector<char> vecty = it->second;
		for (vector<char>::const_iterator i = vecty.begin(); i != vecty.end(); i++) {
			cout << *i << ' ';
		}
		cout << endl;
	}

	// create random text
	string ans;
	ans.reserve(sz);
	for (int i = 0; i < sz; i++) {
		// gen random letter
		vector<char> vecty = stuff[seed];
		cout << vecty[rand() % vecty.size()];
		char chary = vecty[rand() % vecty.size()];
		ans.push_back(chary);
		seed = seed.substr(1) + chary;
	}
	return ans;
}

string umap_model::generate(int sz) {
	string working_data = data + data.substr(0, order);
	
	// pick random k-char substr as init seed
	int start = rand() % (data.length() - order);
	string seed = working_data(start, order);
	int pos = working_data.find(seed);

	// create map
	unordered_map<string, vector<char>> stuff;

	// read data, updata key values
	for (int i = 0; i < working_data.size() - order; i++) {
		string stringy = working_data.substr(i, order):
		char chary = working_data.at(i + order);
		
		// if found, update vector
		if (stuff.find(stringy) != stuff.end()) {
			vector<char> vecty = stuff[stringy];
			vecty.push_back(chary);
			stuff[stringy] = vecty;
		}
		// else, insert key/value pair
		else {
			vector<char> vecty;
			vecty.clear();
			stuff.insert(pair<string, vector<char>> (stringy, vecty));
		}
	}
	cout << "map created" << endl;
		
	// print map
	for (map<string, vector<char>>::const_iterator it = stuff.begin(); it != stuff.end(); ++it) { 
		cout << it->first << " ";
		vector<char> vecty = it->second;
		for (vector<char>::const_iterator i = vecty.begin(); i != vecty.end(); i++) {
			cout << *i << ' ';
		}
		cout << endl;
	}
	
	// create random text
	string ans;
	ans.reserve(sz);
	for (int i = 0; i < sz; i++) {
		// gen random letter
		vector<char> vecty = stuff[seed];
		cout << vecty[rand() % vecty.size()];
		char chary = vecty[rand() % vecty.size()];
		ans.push_back(chary);
		seed = seed.substr(1) + chary;
	}
	return ans;
}

string word_model::generate(int sz) {
	// create vector with words from data
	vector<string> words;
	istringstream my_file(data);

	while (!my_file.eof()) {
		string a;
		my_file >> a;
		words.push_back(s);
	}
	
	// wrap around words to start
	for (int i = 0; i < order; i++) {
		words.push_back(words[i]);
	}
	
	// pick random word and words after for random init seed
	vector<string> seeed;
	int start_i = rand() % words.size();
	
	for (int i = 0; i < order; i++) {
		seeed.push_back(words[start_i + i]);
	}
	
	// print the init seed
	for (vector<string>::const_iterator i = seeed.begin(); i != seeed.end(); ++i) {
		cout << *i << ' ';
	}
	
	// create map
	map<string, string> stuff;
	
	// read data
	for (int i = 0; i < words.size() - order; i++) {
		// create key
		string da_key;
		da_key.clear();
		for (int a = 0; a < order; a++) {
			da_key.append(words[i + a]);
			da_key.push_back(' ');
		}
		
		string val = words[i + order];
		val.push_back(' ');
	
	// if found, update vector
	if (stuff.find(da_key) != stuff.end()) {
		string aval = stuff[da_key];
		aval.append(val);
		stuff[da_key] = aval;
	}
	
	// else insert key/value pair
	else {
		stuff.insert(pair<string, string> (da_key, val));
	}
	
	// print
	for (map<string, string>::const_iterator it = stuff.begin(); it != somemap.end(); ++it) {
		cout << it->first << " " << it-> second << endl;
	}
	
	// create random text
	string ans;
	for (int i = 0; i < sz; i++) {
		// gen random work from seed
		string da_seed2; 
		for (int i = 0; i < da_seed2.size(); i++) {
			da_seed2.append(seeed[i]);
			da_seed2.push_back(' ');
		}
	
		// get value from map
		string poss = stuff[da_seed2];
	
		// load value into vector
		vector<string> is_poss;
		istringstream da_file(poss);
		while (!da_file.eof()) {
			string g;
			da_file >> g;
			if (g != "") {
				is_poss.push_back(g);
			}
		}
	
		// randomly choose word
		string toapp = is_poss[rand() % is_poss.size()];
		ans.append(toapp);
		ans.push_back(' ');
		seeed.erase(seeed.begin());
		seeed.push_back(toapp);
	}
	return ans;
}


		


