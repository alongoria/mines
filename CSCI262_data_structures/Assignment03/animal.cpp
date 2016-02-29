#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "binary_tree.h"
#include "binary_tree.cpp"

using namespace std;

bool game_lost = false;

// reads files and stores data
void read_tree(binary_tree<string>* node_thing, ifstream& file) {
	string type, data;
	file >> type;
	file.ignore();

	getline(file, data);
	node_thing->data = data;

	if (type == "#Q") {
		binary_tree<string>* left = new binary_tree<string>;
		binary_tree<string>* right = new binary_tree<string>;

		node_thing->left = left;
		node_thing->right = right;
		read_tree(left, file);
		read_tree(right, file);
	}
}

// write to file the info
binary_tree<string>* fill_tree() {
	ifstream file_in;
	file_in.open("animal.txt");

	binary_tree<string>* root = new binary_tree<string>;
	read_tree(root, file_in);
	
	file_in.close();
	return root;
}

// read Q's and A's
void read_stuff(binary_tree<string>* node_thing, queue<char> &ans) {
	if (node_thing != NULL) {
		cout << node_thing->data;
		if (ans.front() == 'y') {
			cout << " YES" << endl;
			read_stuff(node_thing->left, ans);
		}
		else {
			cout << " NO" << endl;
			read_stuff(node_thing->right, ans);
		}
		ans.pop();
	}
}

// update tree 
void add_ans(binary_tree<string>* node_thing, binary_tree<string>* end_node, queue<char> &ans) {
	// check for user improvments
	cout << "Help improve the game by adding a new question and answer? (y/n)" << endl;
	char input;
	cin >> input;
	if (input == 'y') {

		// display answers, get info
		cout << "I asked you the following question(s): " << endl;
		read_stuff(node_thing, ans);
		string animal_new;
		string Q_new;
		cout << "Enter new type of animal in the form a question. Ex: \"Is it a whale?\"" << endl;
		cin.ignore();
		getline(cin, animal_new);
		cout << "Enter a question for the new animal " << endl << "which doesn't contradict the previous answers : " << endl;
		getline(cin, Q_new);
		cout << "What is the answer to that question for the new animal (y/n)?" << endl;
		cin >> input;

		// copy data from current node
		string tmp;
		tmp = end_node->data;

		// set node to new question
		end_node->data = Q_new;

		// create child nodes. yes: left is the new animal    no: right is the new animal.
		binary_tree<string>* left = new binary_tree<string>;
		binary_tree<string>* right = new binary_tree<string>;

		if (input == 'y') {
			left->data = animal_new;
			end_node->left = left;

			right->data = tmp;
			end_node->right = right;
		}
		else {
			left->data = tmp;
			end_node->left = left;

			right->data = animal_new;
			end_node->right = right;
		}
	}
}

// 
binary_tree<string>* play(binary_tree<string>* node_thing, queue<char> ans) {
	char gue;
	cout << node_thing->data << "(y/n)" << endl;
	cin >> gue;
	if (gue == 'y') {
		ans.push('y');
		if (node_thing->right == NULL) {
			cout << "I win!" << endl;
			return node_thing;
		}
		else {
			play(node_thing->left, ans);
		}
	}
	else if (gue == 'n') {
		ans.push('n');
		if (node_thing->right == NULL) {
			cout << "Darn, you stumped me." << endl;
			game_lost = true;
			return node_thing;
		}
		else {
			play(node_thing->right, ans);
		}
	}
}

void save(binary_tree<string>* node_thing, ofstream &o_file) {
	if (node_thing != NULL) {
		if (node_thing->left != NULL) {
			o_file << "#Q ";
		}
		else {
			o_file << "#A ";
		}
		o_file << node_thing->data << endl;
		save(node_thing->left, o_file);
		save(node_thing->right, o_file);
	}
}

void delete_stuff(binary_tree<string>* node_thing) {
	if (node_thing != NULL) {
		delete(node_thing->left);
		delete(node_thing->right);
		delete node_thing;
	}
}

int main() {
	binary_tree<string>* root;
	binary_tree<string>* end_node;
	queue<char> ans;
	root = fill_tree();
	if (root == NULL) return -1;

	while (true) {
		int choice;
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		cin >> choice;

		switch (choice) {
		case 1: {
					end_node = play(root, ans);
					if (end_node->right == NULL && game_lost == true) {
						add_ans(root, end_node, ans);
						game_lost = false;
					}
					else {
						while (!ans.empty()) {
							ans.pop();
						}
					}
					break;
		}
		case 2: {
					ofstream o_file;
					o_file.open("animal.txt");
					save(root, o_file);
					o_file.close();
					break;
		}
		case 3: {
					break;
		}
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	delete_stuff(root);
	return 0;
}