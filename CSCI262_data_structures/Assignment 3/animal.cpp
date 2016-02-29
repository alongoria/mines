/*Asisgnment 3 animal 20 questions.
//Roy Stillwell
//4.1.14
	To run in terminal:
	g++ animal.cpp binaryTree.cpp -o animal.out
	./animal.out
*/


#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "binaryTree.h"

using namespace std;

void recursiveDataRead(binaryTree<string>* root,ifstream &file) {
	string type;
	string question;

	//The data being read should be a file w/ two types of data #Q or #A, a space, and then the question
	file >> type; //reads first string (#Q or #A)
	file.ignore();  //skip the space
	getline(file, question); //get rest of string on that line (the question)
	//root.question = question;
	//cout << type << " " << question << endl;
	root->question = question;
	if(type == "#Q") {
		//this is still a valid tree, keep going left (all the way) and then right (recursively.)
		binaryTree<string>* left = new binaryTree<string>;
		binaryTree<string>* right = new binaryTree<string>;

		root->left = left;
		root->right = right;
		recursiveDataRead(left, file);
		recursiveDataRead(right, file);

	} else if (type == "#A") { //we found a branch, end recursion!
		return;

	} else {
		cout << "this guy ->" << type << " <-was found , and it ain't right ." << endl;
		return;
	}

}

void generateNewTree(){
	ofstream outFile;
	outFile.open("animal.txt");
	if (outFile.fail()) {
		cerr << "The memory file animal.txt does not exist." << endl;
	}
		outFile << "#Q Is it a mammal?" << endl;
		outFile << "#Q Does it have stripes?" << endl;
		outFile << "#A Is it a zebra?" << endl;
		outFile << "#Q Does it have four legs?" << endl;
		outFile << "#A Is it an elephant?" << endl;
		outFile << "#A Is it a lion?" << endl;
		outFile << "#Q Is it a bird?" << endl;
		outFile << "#Q Does it fly?" << endl;
		outFile << "#A Is it an eagle?" << endl;
		outFile << "#A Is it a penguin?" << endl;
		outFile << "#Q Does it swim in the water?" << endl;
		outFile << "#A Is it a whale?" << endl;
		outFile << "#A Is it a gila monster?" << endl;
		outFile.close();
}
//Builds the binary tree in memory from a file animal.txt
binaryTree<string>* readGameTree() {
	ifstream file;
	binaryTree<string>* root = new binaryTree<string>;
	string type, question;


	file.open("animal.txt");
	if (file.fail()) {
		cerr << "The memory file animal.txt does not exist." << endl
		<< " Creating a new one.  I will be really bad at this game. :)" << endl;
		

		//TODO create new file and read from it.
		generateNewTree();
		file.open("animal.txt");

	}

	recursiveDataRead(root,file);

	//close stream
	file.close();

	return root;
}


binaryTree<string>* playGame(binaryTree<string>* root) {
	char choice;
	cout << root->question << "[y/n]" << endl;
	cin >> choice;
	binaryTree<string>* endNode;

	switch(choice) {
		case 'y':
			root->answer = choice;
			if (root->left == NULL) { //Case where we guessed it!
				cout << "Guessed it foo!! " << endl; 
				return root;
			} else {
				endNode = playGame(root->left); // case where we need to keep going
				break;
			}
		case 'n':
			root->answer = choice;
			if (root->left == NULL) {
				cout << "What!? You stumped me foo!!" << endl;
				return root;
			}
			else {
				endNode = playGame(root->right);
				break;
			}
		default:
			cout << "That isn't a choice...";
			return root;
	}
	return endNode;

}

void printAnswers(binaryTree<string>* root, binaryTree<string>* endNode) {
	if (root->answer == "") { // there was no answer in this node
		return;
	} else {
			cout << root->question;
	}
	if (root->answer=="y") {
		cout << " YES" << endl;
		if ( !(root->left == NULL) ) printAnswers(root->left, endNode);
		return;
	} 
	if (root->answer == "n") { 
		cout << " NO" << endl;
		if ( !(root->right == NULL) ) printAnswers(root->right, endNode);
		return;
	} else {
		return;

	}

}
void addNewAnswer(binaryTree<string>* endNode) {
	string animal;
	string question;
	string temp;
	cout << "Ok dude. Now enter a new animal like dis: " << endl
	<< "e.g., Is it a whale? : " << endl;
	cin.ignore();
	getline (cin, animal);

	cout << "Now enter a question WITH AN ANSWER OF 'YES' fo yo new" << endl
	<< "animal, which does not mess with your prevous answers: " << endl;

	//cin.ignore();
	getline(cin, question);

	temp = endNode->question;
	endNode->question = question;

	//left node stuff
	binaryTree<string>* left = new binaryTree<string>;
	left->question = animal;
	endNode->left = left;

	//right node stuff
	binaryTree<string>* right = new binaryTree<string>;
	endNode->right = right;
	right->question = temp;

	cout << "Ok Foo! Now I've learned somethin new! Try another 20 questions!" << endl;

}

void willYouMakeMeSmarterFoo(binaryTree<string>* root, binaryTree<string>* endNode) {
	char answer;
	cout << "Will you help dis pitiful foo to be smarter!? [y/n]";
	cin >> answer;
	switch(answer) {
		case 'y':
			cout << "Coo Foo.  Let's do it." << endl;
			cout << "I asked your punk a** this:" << endl;
			printAnswers(root, endNode);
			addNewAnswer(endNode);
			break;

		case 'n':
			cout << "I Pity da foo!!" << endl;
			break;
			
		default:
			cout << "Not a choice foo!" << endl;
			break;
	}
}

//This function recursively traverses binary tree and clear's the game's history
void clearHistory(binaryTree<string>* root){
	if(root->answer=="y") {
		root->answer="";
		//cout << "cleared memory for: " << root->question << " ";
		clearHistory(root->left);
	}
	if(root->answer=="n") {
		root->answer="";
		//cout << "cleared memory for: " << root->question << " ";
		clearHistory(root->right);
	} 
	return; //root answer is blank so we are all done clearing that recursive branch!
}


void recursiveDataWrite(binaryTree<string>* root,ofstream &file) {
	if (root->left==NULL) {
		file << "#A " << root->question << endl;
		return;
	} else {
		file << "#Q " << root->question << endl;
		recursiveDataWrite(root->left, file);
		recursiveDataWrite(root->right, file);
		return;
	}
}

void saveGameTree(binaryTree<string>* root) {
	ofstream file;
	file.open("animal.txt");
	if (file.fail()) {
		cerr << "The memory file animal.txt does not exist." << endl;
	}
	recursiveDataWrite(root,file);

	//close stream
	file.close();

}

void deleteGameTree(binaryTree<string>* root) {
	if(root->left==NULL){
		delete root;
	} else {
		deleteGameTree(root->left);
		deleteGameTree(root->right);
	}

}


int main() {
	binaryTree<string>* root;
	binaryTree<string>* endNode; //marker for the last tree node we made it too.

	root = readGameTree();  //reads in a game w/ a file named animal.txt (if it exists)
	//if (root == NULL) return -1;

	while (true) {
		int choice;
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Ok! I pity the foo..." << endl;
			endNode = playGame(root);
			//cout << "endNode: "<< endNode->question;
			// case where we failed to guess right answer
			if (endNode->left==NULL && endNode->answer=="n") willYouMakeMeSmarterFoo(root, endNode);
			//TODO clear 'memory' for next game play.
			clearHistory(root);
			cout << endl;
			break;
		case 2:
			cout << "Saving game foo." << endl;
			saveGameTree(root);
			cout << "Dis Be done." << endl;
			break;
		case 3:
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	cout << "Deleting game tree from memory." << endl;
	deleteGameTree(root);
	return 0;
}

