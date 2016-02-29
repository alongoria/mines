#pragma once
#include "book.h"
#include <string>
using namespace std;

class Person {

	public:

		Person();
		Person(string name, int age);

		int age;
		string name;
		bool gender;

		bool openBook(Book &b);
		bool closeBook(Book &b);
		bool turnPage(Book &b);
		bool readPage(Book &b);

};