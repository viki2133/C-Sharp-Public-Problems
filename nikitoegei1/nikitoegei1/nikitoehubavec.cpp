#include "pch.h"
#include<iostream>
#include<math.h>

using namespace std;

int P;
int tr = 0;
int S;

double FindArea(int a, int b, int c)
{
	double p = (a + b + c) / 2;
	long double S = sqrt(p*(p - a)*(p - b)*(p - c));
	//cout << S << endl;
	return S;
}

bool IsTriangle(int a, int b, int c)
{
	if (a + b > c && a + c > b && b + c > a) return true;
	return false;
}

bool IsHeron(int a, int b, int c)
{
	double S = FindArea(a, b, c);
	if (floor(S) == ceil(S)) return true;
	return false;
}

bool WholeSmallRadius(int a, int b, int c)
{
	double r = FindArea(a, b, c) / ((a + b + c)/2);
	if (floor(r)==ceil(r)) return true;
	return false;
}

bool WholeBigRadius(int a, int b, int c)
{
	double R = (a*b*c) / (4 * FindArea(a, b, c));
	if (floor(R)==ceil(R)) return true;
	return false;
}

bool IsUniqueTriangle(int a, int b, int c)
{
	if (!IsTriangle(a, b, c)) return false;
	if (!IsHeron(a, b, c)) return false;
	if (!WholeSmallRadius(a, b, c)) return false;
	if (!WholeBigRadius(a, b, c)) return false;
	//cout << FindArea(a,b,c) << endl;
	return true;
}

void Input()
{
	cin >> P;
}

void GenerateTriangles()
{
	for (int i = 1; i < P/2; i++)
	{
		for (int j = i + 1; j < P - i; j++)
		{
			int t = P - (j + i);
			if (t>j && IsUniqueTriangle(i, j, t)) tr++;
			
		}
	}
}

void main()
{
	Input();
	GenerateTriangles();
	cout << tr;
}
