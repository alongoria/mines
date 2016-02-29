#include "book.h"

Book::Book() {
	title = "Untitled";
	pages = 10;
	currentPage = 0;
	pagesRead = 0;
	isOpen = false;
	hasBeenRead = false;
}

Book::Book(string title, int pages) {
	this->title = title;
	if (pages > 0)
		this->pages = pages;
	else
		this->pages = 10;
	pagesRead = 0;
	currentPage = 0;
	isOpen = false;
	hasBeenRead = false;
}

int Book::getCurrentPage() {
	return currentPage;
}

int Book::getPages() {
	return pages;
}

void Book::nextPage() {
	currentPage++;
}

void Book::open() {
	currentPage = 1;
}

void Book::markPageAsRead() {
	++pagesRead;
}

int Book::getPagesRead() {
	return pagesRead;
}

string Book::getTitle() {
	return title;
}