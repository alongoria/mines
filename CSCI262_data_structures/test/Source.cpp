#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int number;
	node *next;
};

bool is_empty(node *head);
char menu();
void insert_as_first(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void print(node *current);

bool empty(node *head) {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

char menu() {
	char choice;
	cout << "??? Menu ???\n";
	cout << "1) add\n";
	cout << "2) remove\n";
	cout << "3) print\n";
	cout << "4) exit\n";

	cin >> choice;

	return choice;

}

void insert_as_first(node *&head, node *&last, int number) {
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;

}

void insert(node *&head, node *&last, int number) {
	if (empty(head)) {
		insert_as_first(head, last, number);
	}
	else {
		node *temp = new node;
		temp->number = number;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}

}

void remove(node *&head, node *&last) {
	if (empty(head)) {
		cout << "list is empty" << endl;
	}
	else if (head == last) {
		delete head;
		head = NULL;
		last = NULL;
	}
	else {
		node *temp = head;
		head = head->next;
		delete temp;
	}

}

void print(node *current) {
	if (empty(current)) {
		cout << "list is empty" << endl;
	}
	else {
		cout << "the list contains: \n";
		while (current != NULL) {
			cout << current->number << endl;
			current = current->next;
		}
	}
}

int main() {
	node *head = NULL;
	node *last = NULL;

	char choice;
	int number;

	do{
		choice = menu();
		switch (choice) {
			case '1':	cout << "Enter a number: ";
				cin >> number;
				insert(head, last, number);
				break;
			case '2':	remove(head, last);
				break;
			case '3':	print(head);
				break;
			default: cout << "system exit" << endl;
		}

	} while (choice != '4');
	system("pause");
	return 0;

}