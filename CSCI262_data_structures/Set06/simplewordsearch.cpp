#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// find out how to add 'public' back in
void delete_dups(vector<string> &vec) {
	// sort and delete duplicates 
	sort( vec.begin(), vec.end() );	
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
}

int points(vector<string> player, vector<string> dictionary) {
	int score = 0;
	delete_dups(player);
	for (int i = 0; i < dictionary.size(); i++) {
		for (int j = 0; j < player.size(); j++) {
			string temp = player.at(j);
			if (player.at(j) == dictionary.at(i)) {
				score += pow(temp.length(), 2);
			}
		}
	}
	
	cout << "score is : " << score << endl;	
	return score;

}



void print_vector(vector<string> s) {
	for (int i = 0; i < s.size(); i++) {
		string temp = s.at(i);
		//cout << temp << " point value: " << pow(temp.length(), 2) << endl;
		cout << temp << endl;

	}
	cout << endl;
}

/*
int main() {
	vector<string> p, d, h , j;
	
	p.push_back("apple");
	p.push_back("not_apple");
	p.push_back("apple");
	p.push_back("apple");
	p.push_back("apple");
	p.push_back("orange");
	p.push_back("strawberry");
	d.push_back("strawberry");
	d.push_back("orange");
	d.push_back("grapefruit");
	d.push_back("watermelon");
	
	j.push_back("lidi"); 
	j.push_back("o"); j.push_back("lidi"); j.push_back("gnbewjzb"); j.push_back("kten");
        j.push_back("ebnelff"); j.push_back("gptsvqx"); j.push_back("rkauxq"); 
	j.push_back("rkauxq"); j.push_back("kfkcdn");

	h.push_back("nava"); h.push_back("wk"); h.push_back("kfkcdn"); h.push_back("lidi"); 
	h.push_back("gptsvqx"); h.push_back("ebnelff"); h.push_back("hgsppdezet");
	h.push_back("ulf"); h.push_back("rkauxq"); h.push_back("wcicx");
  	print_vector(j);
	print_vector(h);
	delete_dups(j);
	print_vector(j);
	points(p, d);
	points(j, h);
	return 0;
}
*/
