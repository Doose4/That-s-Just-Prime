#include <iostream>
#include <cmath>
#include <ctype.h>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

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
	return;

}

//checks if number is prime
bool isPrime(string mystr) {
	int loc;
	loc = mystr.find("X");
	if (loc < 1000) {
		return true;
	}
	return false;
}

//reducation array function
void reduce(int* myarr, int val1, int val2) {
	int reduction1=1;
	int reduction2=1;
	PrimeTime(val1);
	vector<int> string1{};
	for (int i = 0; i < branches.size(); i++)
	{
		string1.push_back(branches[i]);
	}	
	branches.clear();
	PrimeTime(val2);
	vector<int> string2{};
	for (int i = 0; i < branches.size(); i++)
	{
		string2.push_back(branches[i]);
	}
	branches.clear();
	std::sort(string1.begin(), string1.end());
	std::sort(string2.begin(), string2.end());
	vector<int>::iterator it;

	for (int i = 0; i < string1.size(); i++)
	{
		for (int j = 0; j < string2.size(); j++)
		{
			if (string1[i] == string2[j]) {
				it = string1.begin() + i;
				string1.erase(it);
				it = string2.begin() + j;
				string2.erase(it);
				if (i != 0) {
					i--;
				}
				j--;
			}
			else if (string1[i]<string2[j])
			{
				break;
			}
		}
	}

	for (int i = 0; i < string1.size(); i++)
	{	
		reduction1 = reduction1 * string1[i];
	}
	for (int i = 0; i < string2.size(); i++)
	{
		reduction2 = reduction2 * string2[i];
	}

	*myarr = reduction1;
	*(myarr +1) = reduction2;

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

	cout << "Uses isPrime Function\n";
	PrimeTime(2);
	assert(isPrime(outpt(inpt)) == true);
	branches.clear();
	PrimeTime(6);
	assert(isPrime(outpt(inpt)) == true);
	branches.clear();
	PrimeTime(13);
	assert(isPrime(outpt(inpt)) == true);
	branches.clear();
	PrimeTime(198);
	assert(isPrime(outpt(inpt)) == true);
	branches.clear();

	cout << "Uses the reduction function\n";
	int myarr[2] = {0, 0};
	int* pntr = myarr;
	reduce(pntr, 50, 100);
	cout << myarr[0] << "/" << myarr[1] << endl;
	reduce(pntr, 50, 50);
	cout << myarr[0] << "/" << myarr[1] << endl;
	reduce(pntr, 75, 125);
	cout << myarr[0] << "/" << myarr[1] << endl;

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