#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int which_order(string ingredients[], size_t icount,
	string orders[], size_t ocount) {
	// fill in code here


	int choice = -1;


	for (int i = 0; i < ocount; i++) {
		int match_count = 0;
		int count = 0;

		string temp = orders[i];
		istringstream in(temp);

		while (!in.eof()) {
			string foo;
			in >> foo;
			cout << "current order ingredient is " << foo << endl;
			count++;
			for (int y = 0; y < icount; y++) {
				if (foo == ingredients[y]) {
					match_count++;
					cout << foo << " and " << ingredients[i] << " match" << endl;
					break;
				}
			}
		}
		if (count == match_count) {
			choice = i;
			break;
		}
	}
	return choice;
}




int main() {
string ingredients[] = { "cheese", "mustard", "lettuce" };
string want[] = { "cheese mustard lettuce" , "ketchup", "beer","cheese ham"};
string temp = want[0];
istringstream in(temp);

which_order(ingredients, 3, want, 4);

system("pause");
return 0;
}

