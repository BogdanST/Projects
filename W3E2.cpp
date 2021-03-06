#include "stdafx.h"
#include <iostream>

/*
Time complexity of a recursive linear search is O(n);
*/

using namespace std;
class RecursiveLinearSeach {
public:
	int RLS(int A[], int, int);
};
int RecursiveLinearSeach::RLS(int A[], int i, int target)
{
	if (i<0)
	{
		return -1;
	}
	if (A[i] == target)
		return true;
	else
		return RLS(A, i - 1, target);
}

int main()
{
	RecursiveLinearSeach Search;
	int A[6] = { 3,5,7,1,2,9 };
	int i = size(A),target;
	cout << "What element are you looking for?: ";
	cin >> target;
	if (Search.RLS(A, i, target)==true)
		cout << "Found it!";
	else
		cout << "Oops.. there is no such element in this LIST!";
	return 0;
}
