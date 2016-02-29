/* CSCI261 Homework 25: bookReading
 *
 * Author: ADAM LONGORIA	
 *
 * This program leverages Book objects and Person objects to practice object instantiation
 * and to simulate the process of reading a book from cover-to-cover in one sitting.
 *
 * For this assignment, you should ONLY modify main.cpp!
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include "book.h"
#include "person.h"

using namespace std;

int main() {

	Person p;
	Book b;
	Person me("My Name", 21);
	Book myBook("The RSpec book", 5);

	cout << "The default book is " << b.getTitle() << " (" << b.getPages() << " pages)" << endl;
	cout << "The default person is " << p.name << " (age " << p.age << ")" << endl;

	me.openBook(myBook); 

	while (myBook.getPagesRead() < myBook.getPages()) {
		if (myBook.getPagesRead() < myBook.getPages() - 1) {
			me.readPage(myBook);
			me.turnPage(myBook);
		}
		else if (myBook.getPagesRead() < myBook.getPages()) {
			me.readPage(myBook);
		}
	}

	me.closeBook(myBook);



    // Exit program.
    return 0;
}