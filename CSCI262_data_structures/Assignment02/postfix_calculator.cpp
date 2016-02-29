/*
postfix_calculator.cpp

For CSCI 262, Spring 2014, Assignment 2.

Implementation of the postfix calculator.  You should modify the code
everywhere you see a "TODO" comment!
*/

#include "postfix_calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

postfix_calculator::postfix_calculator() {

	stack_underflow = false;
	invalid_op = false;
	invalid_op_string = "";

}

void postfix_calculator::print() {
	stack<double> pancopy = pancake;
	while (!pancopy.empty()) {
		cout << pancopy.top();
		pancopy.pop();
	}
	cout << endl;
}



bool postfix_calculator::evaluate(string expr) {
	// TODO: Implement as per postfix_calculator.h
	//
	// Read the comments in postfix_calculator.h for this
	// method first!  That is your guide to the required
	// functioning of this method.
	//
	// There are various ways to parse expr.  I suggest
	// you create an istringstream object, constructed on
	// expr:
	// 	istringstream string_in(expr);
	// Then you can get each substring from expr using >>.
	// You can determine which of the substrings represent
	// numbers using the to_double function provided below.

	//string temp = expr[i];
	istringstream in(expr);
	while (!in.eof()) {
		double current = 0.0;
		string foo;
		in >> foo;
		//cout << "right now foo is : " << foo << endl;

		if (to_double(foo, current)) {
			pancake.push(current);
		}
		// binary operations
		else if (foo == "+"   || foo == "-"  || foo == "*" ||
			     foo == "/"   || foo == "\\" || foo == "^" ||
			     foo == "mod" || foo == "hypo") {
			double temp1, temp2;
			// check for empty stack
			if (pancake.empty()) {
				stack_underflow = true;
				return false;
			}
			temp2 = pancake.top();
			pancake.pop();
			if (pancake.empty()) {
				stack_underflow = true;
				return false;
			}
			temp1 = pancake.top();
			pancake.pop();
			
			// addition
			if (foo == "+") {
				pancake.push(temp1 + temp2);
			}
			// subtraction
			if (foo == "-") {
				pancake.push(temp1 - temp2);
			}
			// multiplication 
			if (foo == "*") {
				pancake.push(temp1 * temp2);
			}
			// division
			if (foo == "/" || foo == "\\") {
				pancake.push(temp1 / temp2);
			}
			// powers
			if (foo == "^") {
				pancake.push(pow(temp1, temp2));
			}
			// modulus
			if (foo == "mod") {
				pancake.push(fmod(temp1,temp2));
			}
			// hypotenuse
			if (foo == "hypo") {
				pancake.push(hypot(temp1, temp2));
			}
		}

		// unary operations
		else if (foo == "sqrt"  || foo == "log"   || foo == "ln"      || 
			     foo == "sin"   || foo == "cos"   || foo == "tan"     ||
			     foo == "abs"   || foo == "floor" || foo == "ceiling" || 
				 foo == "round" || foo == "trunc") {
			double temp;
			// check for empty stack
			if (pancake.empty()) {
				stack_underflow = true;
				return false;
			}
			else {
				temp = pancake.top();
				pancake.pop();
			}
			// square root
			if (foo == "sqrt") {
				pancake.push(sqrt(temp));
			}
			// log
			if (foo == "log") {
				pancake.push(log10(temp));
			}
			// natural log 
			if (foo == "ln") {
				pancake.push(log(temp));
			}
			// sin
			if (foo == "sin") {
				pancake.push(sin(temp));
			}
			// cos
			if (foo == "cos") {
				pancake.push(cos(temp));
			}
			// tan
			if (foo == "tan") {
				pancake.push(tan(temp));
			}
			// absolute value
			if (foo == "abs") {
				pancake.push(abs(temp));
			}
			// floor
			if (foo == "floor") {
				pancake.push(floor(temp));
			}
			// ceiling
			if (foo == "ceiling") {
				pancake.push(ceil(temp));
			}
			// round
			if (foo == "round") {
				pancake.push(round(temp));
			}
			// trunctate value
			if (foo == "trunc") {
				pancake.push(trunc(temp));
			}

		}

		else {
			invalid_op = true;
			invalid_op_string = foo;
			return false;
		}
	}

	return true;
}


// TODO: Implement the remaining functions specified
// in postfix_calculator.h (except for to_double(), 
// which is done for you below).
//
// You should start by creating "stubs" for each of
// the methods - these are methods that do nothing
// except return a value if needed.  For example, the 
// evaluate() method above does nothing but return true.
//
// Once you've got stubs for everything, then you should
// be able to compile and test the user interface.  Then
// start implementing functions, *testing constantly*!


// Returns true and sets d to the first numerical value in s if
// a numerical value can successfully be extracted.  Returns false
// if unsuccessful (implying there is no numerical value).
bool postfix_calculator::to_double(const string &s, double &d) {
	istringstream cvt(s);
	cvt >> d;
	return !(cvt.fail()) && cvt.eof();
}

void postfix_calculator::clear() {
	// clear the stack
	while (!pancake.empty()) {
		pancake.pop();
	}

	// unset flags
	stack_underflow = false;
	invalid_op = false;
	invalid_op_string = "";

}

double postfix_calculator::top() {
	if (pancake.empty()) return 0.0;
	else {
		// print to std out for testing
		// cout << pancake.top() << endl;
		return pancake.top();
	}
}

bool postfix_calculator::stack_underflow_flag() {
	return stack_underflow;
}

bool postfix_calculator::invalid_operator_flag() {
	return invalid_op;
}

std::string postfix_calculator::invalid_operator_string() {
	return invalid_op_string;
}


