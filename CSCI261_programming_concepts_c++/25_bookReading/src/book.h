#pragma once
#include <string>
using namespace std;

class Book {

	public:

		Book();
		Book(string title, int pages);

		bool hasBeenRead;
		bool isOpen;

		string getTitle();
		int getPages();
		int getCurrentPage();
		void nextPage();
		void open();
		void markPageAsRead();
		int getPagesRead();

	private:
		string title;
		int pages;
		int currentPage;	
		int pagesRead;

};