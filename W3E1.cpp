#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class reverseString {
public:
	string reverseStringRecursively(string);
};
//O(n);
string reverseString::reverseStringRecursively(string str)
{
	if (str.length() == 1)
		return str;
	else
		return reverseStringRecursively(str.substr(1, str.length())) + str.at(0);
}

int main(int argc, char* argv[])
{
	reverseString StringReversed;
	int n, i;
	vector<string> words;
	cout << "How many words would you like to insert? ";
	cin >> n;
	for (i = 0; i<n; ++i) {
		string word;
		cin >> word;
		words.push_back(StringReversed.reverseStringRecursively(word));
	}

	for (std::vector<string>::iterator i = words.begin(); i != words.end(); ++i) {
		cout << *i << " ";
	}
	int a;
	cin >> a;
	return 0;
}

