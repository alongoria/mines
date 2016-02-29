#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void sort_dups(vector<string> &v) {
	// sort and delete duplicates 
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

void print(vector<string> c) {
	for (int i = 0; i < c.size(); i++) {
		string tmp = c.at(i);
		cout << tmp << endl;
	}
	cout << endl;
}

vector<string> whos_dishonest(vector<string> club1, vector<string> club2, vector<string> club3) {
	vector<string> bad;
	return bad;
}

int main() {
	vector<string> c1 = { "JOHN", "JOHN", "FRED", "PEG" };
	vector<string> c2 = { "PEG", "GEORGE" };
	vector<string> c3 = { "GEORGE", "DAVID" };
	print(c1);
	print(c2);
	print(c3);

	sort_dups(c1);
	sort_dups(c2);
	sort_dups(c3);

	print(c1);
	print(c2);
	print(c3);
	system("pause");
	return 0;
}