#include <iostream>
#include <fstream>
#include <string>
#include "binary_tree.h"

using namespace std;

template <class L>
binary_tree<L>::binary_tree() {
	left = NULL;
	right = NULL;
	data = "";
}

template <class L> 
binary_tree<L>::binary_tree(L thing) {
	data = thing;
}

template <class L>
binary_tree<L>::binary_tree(binary_tree<L> &something) {
	data = something.data;
	left = something.left;
	right = something.right;
}