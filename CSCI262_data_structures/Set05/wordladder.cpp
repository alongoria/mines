#include <iostream>
#include <string>
#include <vector>

using namespace std;

// print function
void print(vector<string> words) {
	for (int i = 0; i < words.size(); i++) {
		cout << words.at(i) << " ";
	}
	cout << endl;
}

// returns smallest # from vector
int small(vector<int> num) {
	int smallest = num.at(0);
	for (int i = 0; i < num.size(); i++) {
		if (num.at(i) < smallest) {
			smallest = num.at(i);
		}
	}
	return smallest;
}

// return true if words are same except for 1 letter
bool off_by_1(string a, string b) {
	int match = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) == b.at(i)) {
			match++;
		}
	}
	if (a.length() - match == 1) {
		return true;
	}
	return false;
}

// find similar words
int find(string t, string end, vector<string> words, int count, vector<int> &val) {
	print(words);
	count++;
	string first = words.at(0);
	int length = first.length();
	// more vectors: matched and non-matches
	vector<string> words2, words3;
	// compare the current word
	if (count >= 3) {
		int match = 0;
		if (off_by_1(end, t)) {
			val.push_back(count);
		}
	}
	// push valid words on second vector
	for (int i = 0; i < words.size(); i++) {
		string compare = words.at(i);
		if (off_by_1(compare, t)) {
			words2.push_back(compare);
		}
		// else keep words
		else {
			words3.push_back(compare);	
		}
	}
	print(words2);
	// continue to find words
	if (!words3.empty()) {
		for (int i = 0; i < words2.size(); i++) {
			find(words2.at(i), end, words3, count, val);
		}
	}
	// final compare
	else {
		for (int i = 0; i < words2.size(); i++) {
			if (off_by_1(words2.at(i), end)) {
				val.push_back(count + 1);
			}
		}
	}
	return 0;
}

int shortest(vector<string> words, string from, string to) {
	vector<int> val;
	int count = 1;
	find(from, to, words, count, val);
	if (val.empty()) {
		return 0;
	}
	else{
		return small(val);
	}
}

/*
int main() {
	vector<string> words = { "hot", "dot", "dog" };
	int answer = shortest(words, "hit", "cog");
	cout << "the shortest path is " << answer << endl;
	system("pause");
	return 0;
}
*/