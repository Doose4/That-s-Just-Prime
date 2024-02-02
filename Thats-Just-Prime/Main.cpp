#include <iostream>
#include <cmath>

using namespace std;

int FindLCD(int nmbr) {
	int lcd = 0;


	for (int i = 2; i < sqrt(nmbr); i++) {
		if ((nmbr % i) == 0)
		{
			return i;
		}

	}

	return 1;

}


int PrimeTime(int nmbr) {
	int lcd = (FindLCD(nmbr));

	cout << "\nfinding primes of " << nmbr;

	if (nmbr < 2){
		return 1;
	}
	else if (lcd == 1) {
		return nmbr;
	}

	cout << "\n" << lcd << " X " << PrimeTime(nmbr / lcd);
	

}

int main() {
	int inpt = 10;

	PrimeTime(inpt);

	return 0;
}