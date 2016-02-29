/* CSCI261 Homework 21: dataMatrix
 *
 * Author: ADAM LONGORIA
 *
 * This program prints the values in a 2d-array and the sum of values
 * in each row.
 * 
 */
#include <cstdlib>
#include <iostream>
using namespace std;

const int DATA_LENGTH = 10;

void populateMatrix(int f[][DATA_LENGTH]);
void printMatrix(int f[][DATA_LENGTH]);

int main() {

	int mat[DATA_LENGTH][DATA_LENGTH];

	cout << "Hooray, arrays!!!" << endl;

	populateMatrix(mat);
	printMatrix(mat);

    return 0;
}


void populateMatrix(int f[][DATA_LENGTH]){
	for(int a = 0; a < DATA_LENGTH; a++){
		for(int b = 0; b < DATA_LENGTH; b++){
			f[a][b] = rand() % 10;
		}
	}
}

void printMatrix(int f[][DATA_LENGTH]){
	for(int a = 0; a < DATA_LENGTH; a++){
		int sum = 0;
		for(int b = 0; b < DATA_LENGTH; b++){
			cout << f[a][b] << " ";
			sum += f[a][b];
		}
		cout << sum << endl;
	}
}