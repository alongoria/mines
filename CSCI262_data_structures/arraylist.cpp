#include<cstdlib>
#include<iostream>

using namespace std;

class list {
public:
	list();
	list(const list&);
	~list();

	void operator = (const list&);
    
	int size();
	int get(int position);
	void add(int);
	void insert(int n, int position);
	void erase(int postition);
	void print();
	

private:
	int _size;
	int _capacity;
	int* _numbers;


};

void list::operator = (const list& source) {
	if (this == &source) {
		return;
	}
	else {
		// if there was already memory allocated, get rid of it
		delete[] _numbers;
		_size = source._size;
		_capacity = source._capacity;
		_numbers = new int[_capacity];
		for (int i = 0; i < _size; i++) {
			_numbers[i] = source._numbers[i];
		}
	}
}

	

list::list(const list& source) {
	_size = source._size;
	_capacity = source._capacity;
	_numbers = new int[_capacity];
	for (int i = 0; i < _size; i++) {
		_numbers[i] = source._numbers[i];
	}
}

list::list() {
	_size = 0;
	_capacity = 4;
	_numbers = new int[_capacity];
}

list::~list() {
	delete[] _numbers;
}

int list::size() {
	return this->_size;
}

int list::get(int position) {
	if (position > _size) {
		return 0;
	}
	return _numbers[position];
}

void list::add(int n) {
	if (_size == _capacity) {
		int* tmp = new int[2 * _capacity];
		for (int i = 0; i < _size; i++) {
			tmp[i] = _numbers[i];
		}
		delete[] _numbers;
		_numbers = tmp;
		_capacity *= 2;
	}
	_numbers[_size] = n;
	_size++;
}

void list::insert(int n, int position){
	if (position > _size) {
	}
	else {
		if (_size + 1 == _capacity) {
			int* tmp = new int[2 * _capacity];
			for (int i = 0; i < _size; i++) {
				tmp[i] = _numbers[i];
			}
			delete[] _numbers;
			_numbers = tmp;
			_capacity *= 2;
		}
                
                int* temp = new int[_capacity];
		for (int i = 0; i < _size; i++) {
			temp[i] = _numbers[i];
		}
		//_numbers[position] = n;
		for (int i = position; i < _size + 1; i++) {
			_numbers[i+1] = temp[i];
		}
		_numbers[position] = n;
		_size++;
	}
}

void list::erase(int position) {
	if (position > _size) {
	}
	else {
		for (int j = position; j < _size; j++) {
			_numbers[j] = _numbers[j+1];
		}
	_size--;
	}
}



void list::print() {
	for (int i = 0; i < _size; i++) {
		cout << _numbers[i] << ' ';
	}
	cout << endl;
}

/*
int main() {
	list *foo = new list;
	for (int i = 0; i < 10; i++) {
		foo->add(i);
	}
	list *bar = new list;
	for (int i = 0; i < 10; i++) {
		bar->add(rand() % 2);
	}
	
	foo->print();
        cout << endl << foo->size() << endl;
	foo->erase(3);
	//foo->erase(123);
	foo->print();
	foo->insert(12,4);
	cout << endl;
	foo->print();
	cout << endl;
        //system("pause");

        foo->print();
        cout << endl << endl;
	bar->print(); 
	cout << endl << endl;
	*bar = *foo; 
	cout << endl << endl;
	bar->print(); 
	cout << endl << endl;
	bar->print(); cout << endl;
	bar->insert(12,4);
	bar->print(); cout << endl;
}
*/
