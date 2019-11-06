#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	cin >> str;
	int a = 0, b = 0;
	int i = 0;
	int len = str.length();

	while (i < len && str[i] == 'A') 
	{
		a++;
		i++;
	}

	while (i < len && str[i] == '!')
	{
		b++;
		i++;
	}

	if (a > 0 && b > 0 && i == len) cout << "Panic!" << endl;
	else cout << "No panic" << endl;

	return 0;
}
