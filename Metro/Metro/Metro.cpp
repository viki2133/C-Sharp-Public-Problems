#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int N;
int M;
int *BigStops = new int[M];
int A;
int B;
int Price;
int BigA;
int BigB;

void EnterData()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> BigStops[i];
	cin >> A >> B;
	if (A > B) swap(A, B);
}

int IndexOf(int ch)
{
	for (int i = 0; i < M; i++)
		if (ch == BigStops[i]) return i;
}

int ClosestBigA()
{
	int clst = BigStops[0];
	int cldist = abs(A - BigStops[0]);
	for (int i = 1; i < M; i++)
	{
		if (abs(A - BigStops[i]) <= cldist)
		{
			cldist = abs(A - BigStops[i]);
			clst = BigStops[i];
		}
	}
	return clst;

}

int ClosestBigB()
{
	int clst = BigStops[0];

	int cldist = abs(B - BigStops[0]);
	for (int i = 1; i < M; i++)
	{
		if (abs(B - BigStops[i]) < cldist)
		{
			cldist = abs(B - BigStops[i]);
			clst = BigStops[i];
		}
	}
	return clst;

}

int FastFromTo(int start, int end)
{
	int Price=0;
	start = IndexOf(start);
	end = IndexOf(end);
	for (int i = start ; i < end; i++)
	{
		
		if (BigStops[i] == BigStops[i+1]-1) Price++;
		else Price += 2;
	}
	return Price;
}

int SlowFromTo(int start, int end)
{
	return abs(start - end);
}

void Travel()
{
	BigA = ClosestBigA();
	BigB = ClosestBigB();
	Price += SlowFromTo(A, BigA);
	Price += FastFromTo(BigA, BigB);
	Price += SlowFromTo(BigB, B);
}

int main()
{
	Price = 0;
	EnterData();
	Travel();
	int DirectPrice = abs(A - B);
	if (DirectPrice < Price) cout << DirectPrice;
	else cout << Price;
	return 0;
}