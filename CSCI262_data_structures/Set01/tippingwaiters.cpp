#include<iostream>
#include<fstream>

using namespace std;

int possible_payments(int bill, int cash) {

	/*
	Using the constraint equation: (tip + bill) * percent = tip,
	we can derive equation for the required tip

	low_tip = .05 * bill / .95
	high_tip = .1 * bill / .90

	*/
	int count = 0; //number of possible payments
	double low_tip = .05 * bill / .95; //possibility for low tip
	double high_tip = .1 * bill / .90; //possibility for high tip
	double low_bill_D = low_tip + bill;
	double high_bill_D = high_tip + bill;
	int low_bill = low_bill_D;
	int high_bill = high_bill_D;
	double low_diff = 0;
	low_diff = low_bill_D - low_bill;

	if ((low_diff < 1) && (low_diff) > 0) {
		low_bill++;
	}

	if (low_bill % 5 != 0) {
		low_bill += (5 - low_bill % 5);
	}

	if (high_bill % 5 != 0) {
		high_bill -= high_bill % 5;
	}

	if (high_bill > cash) {
		high_bill = cash;
	}

	count = 1 + (high_bill - low_bill) / 5;

	if ((high_bill < low_bill) || (count < 0)) {
		count = 0;
	}

	return count;

}
	
/*
int main() {
	//possible_payments(4,100);
	//possible_payments(23,100);
	//possible_payments(23, 24);
	possible_payments(220,239);
	//possible_payments(1234567,12345678);
	//possible_payments(1880000000,1980000000);
	//possible_payments(171000000,179999999);
	system("pause");
	return 0;
}
*/