/* CSCI261 Homework 06: asciiExploration
 *
 * Author: ADAM LONGORIA
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {


    char key;
    int k;

    cout << "Enter only one character on the keyboard: ";
    cin >> key;

    if ( (key >= 'a' && key <= 'z') ) {
        k = key;
        cout << "This is a lowercase letter" << endl;
        cout << "The ASCII code for " << key << " is " << k << endl;}

    if ( (key >= 'A' && key <= 'Z') ) {
        k = key;
        cout << "This is an uppercase letter" << endl;
        cout << "The ASCII code for " << key << " is " << k << endl;}

    if ( (key <= 'a' && key >= 'Z' || key <= 'A' && key >= ':' || key >= 'z' || key <= '/') ) {
        k = key;
        cout << "This is non-alphanumeric" << endl;
        cout << "The ASCII code for " << key << " is " << k << endl;}

     if ( (key <= '9' && key >= '0') ) {
        k = key;
        cout << "This is numeric" << endl;
        cout << "The ASCII code for " << key << " is " << k << endl;}


    // Exit program.
    return 0;
}
