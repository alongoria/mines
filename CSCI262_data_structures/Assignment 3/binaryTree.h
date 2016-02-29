//binaryTree.h
//Class for storing binary tree nodes

using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T> class binaryTree
{
public:
	binaryTree* left;
	binaryTree* right;
	T question;
	T answer;
	//T blah();
	binaryTree();
	binaryTree(T s) { question = s;};
	binaryTree(binaryTree<T> &);
	//T add(T x, T y);  //example w/ return type
};

#include "binaryTree.cpp"
#endif