#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

typedef unsigned long long ull;

using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;

	ull result = 0;
	if (r == 1 && c == 1)
	{
		result = 1;
	}
	else
	{
		ull diagonal = (r  - 1) + (c - 1);
		ull value = 1 + (1 + diagonal)*diagonal/2;

		if (diagonal % 2 == 1)
		{
			value += diagonal;
			result = value - (c - 1);
		}
		else
		{
			result = value + (c - 1);
		}
	}

	cout << result << endl;
}
