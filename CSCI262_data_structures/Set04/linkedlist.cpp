#include <cstdlib>
#include <iostream>

using namespace std;

class node {
	friend class list;

public:
	node(int value) { _data = value; _next = NULL; }
	node() { _data = 0; _next = NULL; }

private:
	int   _data;
	node* _next;
};



class list {
public:
	list();
	list(const list&);
	~list();

	void operator=(const list&);

	int size();
	int get(int position);
	void add(int);
	void insert(int n, int position);
	void erase(int position);

	void print();

private:
	node* _head;
	node* _tail;
	int _size;
};

list::list() {
	_size = 0;
	_head = NULL;
	_tail = NULL;
}

list::list(const list& source) {
	
	_size = 0;
	_head = NULL;
	_tail = NULL;
	
	this->_size = source._size;
	node* head_node = new node(source._head->_data);
	_head = head_node;

	node* source_list = this->_head;
	node* current = source._head;
	
	for (node* current = source._head->_next; current != NULL; current = current->_next) {
		node* new_node = new node(current->_data);
		source_list->_next = new_node;
		source_list = source_list->_next;
	}
	
}


void list::operator=(const list& source) {

	if (this == &source) return;

	node* current = _head;
	while (current != NULL) {
		_head = _head->_next;
		delete current;
		current = _head;
	}

	_size = source._size;
	_head = new node(source._head->_data);  // how do we proceed???

	node* source_list = this->_head;
	current = source._head;
	for (node* current = source._head->_next; current != NULL; current = current->_next) {
		node* new_node = new node(current->_data);
		source_list->_next = new_node;
		source_list = source_list->_next;
	}
	
}

list::~list() {
	while (_head != NULL) {
		node* current_head = _head;
		_head = _head->_next;
		delete current_head;
	}
	_size = 0;
}


int list::size() {
	return _size;
}


int list::get(int position) {
	node* current = _head;
	if (position > _size) return 0;
	else {
		int get_count = 0;
	
		while (get_count < position) {
			current = current->_next;
			get_count++;
		}	
	}
	return current->_data;
}

void list::add(int data) {
	node* new_node= new node(data);
	if (_head == NULL) _head = new_node;
	if (_tail == NULL) _tail = new_node;
	else {
		_tail->_next = new_node;
		_tail = new_node;
	}
	this->_size++;
}

void list::erase(int position) {
	if (position >= this->_size);
	else if (position == 0) {
		node* temp = _head;
		_head = _head->_next;
		delete temp;
	}
	else {
		int erase_count = 0;
		node* current = _head;
		while (erase_count < position - 1) {
			current = current->_next;
			erase_count++;
		}
		node* temp = current->_next;
		current->_next = current->_next->_next;
		delete temp;
	}
	this->_size--;
}

void list::insert(int n, int position) {
	node* current = _head;
	if (position > _size);
	else if (position == 0) {
		node* new_node = new node(n);
		new_node->_next = _head;
		_head = new_node;
	}
	else {
		int insert_count = 0;

		while (insert_count < position - 1) {
			current = current->_next;
			insert_count++;
		}
		node* new_node = new node(n);
		new_node->_next = current->_next;
		current->_next = new_node;
	}
	this->_size++;
}


void list::print() {
	for (node* p = _head; p != NULL; p = p->_next) {
		cout << p->_data << " ";
	}
}

/*
int main() {
	int s = 456;
	list* stuff = new list;
	stuff->add(1);
	stuff->add(2);
	stuff->add(3);
	stuff->add(4);
	stuff->add(5);
	stuff->print();
	cout << endl << "elements in list:  " << stuff->size() << endl;
	cout << stuff->get(1) << endl;
	stuff->insert(69, 3);
	stuff->print();
	cout << endl;
	stuff->erase(4);
	stuff->print();
	cout << endl;
	list thing = *new list(*stuff);
	cout << "new list: ";
	thing.print();
	cout << endl;

	thing.add(10);
	thing.add(5);
	thing.add(3);
	cout << "list before: ";
	thing.print();
	cout << endl;

	system("pause");
	return 0;
}
*/