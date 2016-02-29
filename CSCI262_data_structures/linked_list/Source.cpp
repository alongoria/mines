#include<iostream>
#include<cstdlib>

using namespace std;

class node {

public:
	// typedef
	typedef double value_type;

	// contructor
	node(const value_type& init_data = value_type(), node* init_link = NULL) {
		data_field = init_data;
		link_field = init_link;
	}

	// functions to set data and link fields
	void set_data(const value_type& new_data) {
		data_field = new_data;
	}

	void set_link(node* new_link) {
		link_field = new_link;
	}

	// constant member funtcion to get current data
	value_type data() const {
		return data_field;
	}

	// member functions to get current link
	const node* link() const {
		return link_field;
	}

	node* link() {
		return link_field;
	}

private:
	value_type data_field;
	node *link_field;

};

int main() {
	node *head;
	node *tail;
	system("pause");
	return 0;
}