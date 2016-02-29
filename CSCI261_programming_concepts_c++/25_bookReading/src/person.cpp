#include "person.h"
#include <iostream>

Person::Person() {
	age = 21;
	name = "No Name";
}

Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}

bool Person::openBook(Book &b) {
	if (b.isOpen) {
		cout << "Book is already open.\n";
		return false;
	} else {
		cout << "Opening the book called " << b.getTitle() << " (" << b.getPages() << " pages)" << endl;
		b.isOpen = true;
		b.open();
		return true;
	}
}

bool Person::closeBook(Book &b) {
	if ( b.isOpen && (b.getPagesRead() == b.getPages()) ) {
		cout << "Closing the book called " << b.getTitle() << endl;
		b.isOpen = false;
		return true;
	} else if (b.getPagesRead() != b.getPages()) {
		cout << "You haven't finished reading the book!\n";
		return false;
	} else {
		cout << "Book is already closed.\n";
		return false;
	}
}

bool Person::readPage(Book &b) {
	if (!b.isOpen) {
		cout << "Book is not open!\n";
	} else if (b.getCurrentPage() > b.getPages()) {
		cout << "No page to read!\n";
	} else {
		cout << "Reading page " << b.getCurrentPage() << endl;
		b.markPageAsRead();
		return true;
	}
	return false;
}

bool Person::turnPage(Book &b) {
	if (!b.isOpen) {
		cout << "Book is not open!";
	} else if (b.getCurrentPage() >= b.getPages()) {
		cout << "No more getPages() to turn.";
	} else {
		b.nextPage();
		cout << "Turning to page " << b.getCurrentPage() << endl;
		return true;
	}
	return false;
}