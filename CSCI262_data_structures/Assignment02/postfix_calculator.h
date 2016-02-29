/*
postfix_calculator.h

For CSCI 262, Spring 2014, Assignment 2.

Header file for the postfix calculator.  You will need to
add some member variables to store the state of your
calculator; you may also add any methods you need.  Keep
in mind that whatever changes you make, your code should
still work with calculator_main.cpp.

author: C. Painter-Wakefield
*/

#ifndef POSTFIX_CALCULATOR_H
#define POSTFIX_CALCULATOR_H

#include <stack>
#include <string>

using namespace std;

class postfix_calculator {
public:
	// Take in and process a string query such as "7 14 * 3 /".
	// The string is read left to right.  Numbers are pushed onto
	// the stack.  All other strings are assumed to be operators.
	// If the operator is a binary operator such as "+", then two
	// numbers are popped off the stack, the binary operator is
	// applied, and the answer is pushed back on the stack.  If
	// the operator is a unary operator such as "sin" (if 
	// implemented), then only one number is popped off and the
	// answer pushed.
	//
	// IF the query causes a stack underflow situation (i.e., 
	// an operator requires an operand but the stack is empty),
	// then the method returns false and the stack_underflow_flag()
	// method should return true until clear() is called.
	//
	// IF any operator is not recognized, then the method returns
	// false, the invalid_operator_flag() returns true, and the 
	// invalid_operator_string() method returns the unknown operator
	// until clear() is called.
	//
	// When either flag method returns true, the behavior of evaluate 
	// is unspecified until the clear() function is called.
	//bool evaluate(std::string);
	bool evaluate(string);


	// Clear flags and invalid operator string, if set, and remove
	// all items from the current stack.
	void clear();

	// Return the number at the top of the stack (this will be the
	// answer if a valid query was passed to evaluate).  If the
	// stack is empty, returns 0.0.  The number  should *not* be 
	// popped from the stack (this allows further  calculations
	// using this number).
	double top();

	// Errors
	bool stack_underflow_flag();
	bool invalid_operator_flag();
	string invalid_operator_string();
	//std::string invalid_operator_string();
	void postfix_calculator::print();


	// Constructor
	postfix_calculator();

	// Utility
	// If the contents of string s are recognizable as a real 
	// number, then the value of d is set to the number and
	// true is returned.  If not, d is set to 0.0 and false is
	// returned.
	static bool to_double(const string& s, double &d);
	//static bool to_double(const std::string& s, double &d);


private:
	// TODO: declare member variables here for your stack, flags, etc.

	//std::stack<double> pancake;
	stack<double> pancake;
	bool stack_underflow;
	bool invalid_op;
	string invalid_op_string;
};

#endif
