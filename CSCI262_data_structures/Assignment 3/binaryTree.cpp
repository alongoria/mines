//binaryTree.cpp
//Implements class binaryTree
//Roy Stillwell
//4.1.14

#include <string>
using namespace std;

template <class T>binaryTree<T>::binaryTree(binaryTree<T> &a) {
	question = a.question;
	left = a.left;
	right = a.right;
}
template <class T>binaryTree<T>::binaryTree() {
	left = NULL;
	right = NULL;
	question = "";
	answer = "";
}
//default constructor
// template < class T> binaryTree<T>::binaryTree() {
// 	question = "";
// }
// template < class T> binaryTree<T>::binaryTree(string s) {
// 	question = s;
// }
// template < class T> T binaryTree<T>::add(T x, T y) { //Template example w/ return type
// 	return x + y;
// }