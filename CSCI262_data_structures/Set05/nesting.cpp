#include <iostream>
#include <stack>
using namespace std;

void print_stack(stack<char> s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}


bool is_valid(string expr, string left, string right) {

	stack<char> real_stack;

	for (int i = 0; i < expr.length(); i++) {
		for (int j = 0; j < left.length(); j++) {
			if (expr[i] == left[j]) {
				real_stack.push(left[j]);
			}
			if (expr[i] == right[j]) {
				if (real_stack.empty()) return false;
				else if (real_stack.top() != left[j]) {
					cout << "false" << endl;
					return false;
				}
				else {
					real_stack.pop();
				}
			}
		}
	}

	if (!real_stack.empty()) return false;
	cout << "true" << endl;
	return true;

}

/*
int main() {
	is_valid("{(x + y) * z}", "{(", "})");
	system("pause");
	return 0;
}
*/