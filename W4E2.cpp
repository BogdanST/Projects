#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;
 const int min = 1;
 const int max = 20000;

class guessnumber {
public:
	int GuessTheNumber(int, int, int);
};

int guessnumber::GuessTheNumber(int min, int max, int RandNumber) {
	/* using the binary search technique to find the guessed number using recursion*/
	int guess = (min + max) / 2;
	int minGuess = min, maxGuess = max;
	if (RandNumber > guess) {  // case 1: when randNumber is greater than the actuall guess;
		minGuess = guess;
		cout << "let me Guess, " << minGuess << " it doesn't seems right let me try again!" << endl;
		GuessTheNumber(minGuess, maxGuess, RandNumber);
	}
	else
		if (RandNumber < guess) { // case 2: when randNumber is lower than the actuall guess;
			maxGuess = guess;
			cout << "let me Guess, " << maxGuess << " it doesn't seems right let me try again!" << endl;
			GuessTheNumber(minGuess, maxGuess, RandNumber);
		}
		else
			return guess; // the number guessed was found
}
int main() {
	guessnumber GNumber;
	srand(time(NULL));					//initialize a random number from [1,20000];
	int RandNumber = rand() % (min, max);
	cout << "The Number was: " << RandNumber << " I think i got IT! The Guessed Number " << GNumber.GuessTheNumber(1, 20000, RandNumber);
	int a;
	cin >> a;
	return 0;
}