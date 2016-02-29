#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef BINARY_TREE
#define BINARY_TREE

template <class L>

class binary_tree {
public:
	L data;
	binary_tree<L>* left;
	binary_tree<L>* right;
	binary_tree();
	binary_tree(L thing);
	binary_tree(binary_tree<L> &something);
};

#endif