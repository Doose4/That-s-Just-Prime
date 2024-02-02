#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

vector<int> branches{};

int FindLCD(int nmbr) {
	int lcd = 0;


	for (int i = 2; i < nmbr; i++) {
		if ((nmbr % i) == 0)
		{
			return i;
		}

	}

	return 1;

}

void outpt(int nmbr) {
	string str = to_string(branches[0]);
	cout << endl << "the Primes of " << nmbr << " is:" << endl;

	for (int i = 1; i < branches.size(); i++) {
		str = str + " X " + to_string(branches[i]);
	}

	cout << str;
}

void PrimeTime(int nmbr) {
	//cout << nmbr << endl;
	int lcd = (FindLCD(nmbr));

	cout << "finding primes of " << nmbr << endl;
	

	if ((nmbr <= 2) || (lcd == 1)){
		//cout << outpt;
		branches.push_back(nmbr);
		return;
	}
	
	//cout << lcd << endl;
	//cout << nmbr / lcd << endl << endl;
	branches.push_back(lcd);
	PrimeTime(nmbr / lcd);

}

int main() {
	int inpt = 20;

	PrimeTime(inpt);
	outpt(inpt);

	return 0;
}