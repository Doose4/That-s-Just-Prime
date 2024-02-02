#include <iostream>

using namespace std;

int FindLCD(int nmbr) {
	int lcd = 0;

	for (int i = 1; i < (nmbr / 2); i++) {
		if ((nmbr % i) == 0)
		{
			return i;
		}

	}

	return nmbr;

}


void PrimeTime(int nmbr) {

	cout << "finding primes of " << nmbr;

	

}

int main() {
	int inpt = 10;

	PrimeTime(inpt);

	return 0;
}