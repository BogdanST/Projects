#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ArmstrongNumbers {
public:
	int ArmstrongNumber(int);
};

int ArmstrongNumbers::ArmstrongNumber(int number)
{
	/*This program checks if a number is an Armstrong Number
	 The program iterates through the number until the copy gets to 0 and each digit is placed
	 into the vector*/
	vector<int> sNumbers;                        
	int copynumber = 0, lastdigit = 0;           
	copynumber = number;						 
	while (copynumber>0) {
		lastdigit = copynumber % 10;
		copynumber = copynumber / 10;

		sNumbers.push_back(lastdigit);
	}
	cout << endl;
	int sum = 0;							//sum - increases while it iterates through the vector
	for (std::vector<int>::iterator it = sNumbers.begin(); it != sNumbers.end(); ++it) {
		sum = sum + int(0.5 + pow(*it, 3));
	}
	return sum;
}

int main(int argc, char* argv[]) {
	int number;
	cout << "Insert a number:";
	cin >> number;
	ArmstrongNumbers sum; 
	if (sum.ArmstrongNumber(number) == number)
		cout << "HURRAY!! Number: " << number << " It is an Armstrong number!" << endl;
	else
		cout << "Number: " << number << " It's not an Armstrong number!" << endl;

	cin >> number;
	return 0;
}
