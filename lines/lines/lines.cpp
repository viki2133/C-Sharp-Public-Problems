#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, ch=1;
	cin >> n;
	int i = 1;
	while (true)
	{
		if (n >= ch && n < ch + i)
		{
			cout << i;
			break;
		}
		ch += i;
		i++;
	}
	return 0;
}

