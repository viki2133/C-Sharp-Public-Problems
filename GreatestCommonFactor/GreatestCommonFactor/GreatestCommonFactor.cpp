#include "pch.h"
#include <iostream>

using namespace std;

string Row;

void EnterRow()
{
	Row=cin.getline()
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		EnterRow();
	}
	return 0;
}