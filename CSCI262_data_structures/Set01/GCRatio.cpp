#include<string>

using namespace std;

double ratio(string dna) {
	double count = 0;
	double percent = 0;
	for (int ii = 0; ii < dna.size(); ii++) {
		if ((dna[ii] == 'c') || (dna[ii] == 'g')) {
			count++;
		}
	}
	percent = count / dna.size();
	return percent;
}

/*
int main() {
	ratio("agatc");
	return 0;
}
*/