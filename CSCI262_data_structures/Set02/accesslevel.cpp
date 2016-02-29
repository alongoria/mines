#include <iostream>
#include <string>

using namespace std;

string can_access(int user_rights[], size_t user_count, int min_permission) {

	//char access_string[];
	string access = "";

	for (int iii = 0; iii < user_count; iii++) {
		if (user_rights[iii] < min_permission) {
			access.append("D");
		}
		else {
			access.append("A");
		}
	}

	cout << access << endl;
	system("pause");
	return access;
}
/*
int main() {

int g[6] = {0,1,2,3,4,5};
can_access(g, 6, 2);
return 0;
}
*/