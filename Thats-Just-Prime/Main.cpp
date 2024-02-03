#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

vector<int> branches{};

int FindLCD(int nmbr) {
	int lcd = 0;
	//finds the lcd for the number
	for (int i = 2; i < sqrt(nmbr)+1; i++) {
		if ((nmbr % i) == 0)
		{
			return i;
		}

	}
	return 1;
}

string outpt(int inp) {
	string str = to_string(branches[0]);

	//outputs the vector for user to read
	if (inp <= 1){
		return "Cannot calculate the prime factors for " + to_string(inp);
	}
	cout << endl << "the Primes of " << inp << " is:" << endl;

	for (int i = 1; i < branches.size(); i++) {
		str = str + " X " + to_string(branches[i]);
	}

	return str;
}

void PrimeTime(int nmbr) {
	int lcd = (FindLCD(nmbr));

	cout << "finding primes of " << nmbr << endl;

	//checks to see if primes have stopped.
	if ((nmbr <= 2) || (lcd == 1)){
		branches.push_back(nmbr);
		return;
	}

	//adds least common denominator to vector
	branches.push_back(lcd);
	//recursion
	PrimeTime(nmbr / lcd);

}


void Driver() {
	cout << "Starting the test...\n";
//z
	int inpt = 0;
	PrimeTime(inpt);
	assert(outpt(inpt) == "Cannot calculate the prime factors for 0");
//o
	inpt = 1;
	branches.clear();
	PrimeTime(inpt);
	assert(outpt(inpt) == "Cannot calculate the prime factors for 1");
//m
	inpt = 2;
	branches.clear();
	PrimeTime(inpt);
	assert(outpt(inpt) == "2");
//b
	inpt = 100;
	branches.clear();
	PrimeTime(inpt);
	assert(outpt(inpt) == "2 X 2 X 5 X 5");
//i
	inpt = 54;
	branches.clear();
	PrimeTime(inpt);
	assert(outpt(inpt) == "2 X 3 X 3 X 3");
//e
	inpt = 17;
	branches.clear();
	PrimeTime(inpt);
	assert(outpt(inpt) == "17");

//s
	inpt = 1111;
	branches.clear();
	PrimeTime(inpt);
	assert(outpt(inpt) == "11 X 101");

	cout << "Congrats, it passed!!\n\n";

	branches.clear();
}

int main() {
	//driver to test
	Driver();

	//Main function
	int inpt = 0;
	cout << "Enter a number greater than 1: ";
	cin >> inpt;
	PrimeTime(inpt);
	cout << outpt(inpt);

	return 0;
}