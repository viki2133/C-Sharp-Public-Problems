// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <iostream>

using namespace std;

int BigBusStop(int j, int a[], int nstops)
{
	for (size_t i = 0; i < nstops; i++)
	{
		if (j == a[i])
		{
			return a[i];
		}
	}
	return -1;
}

void Funktion(int a[], int N, int M, int nstops)
{
	int S = 0;
	int x = 0;
	for (int i = N; i < M; i++)
	{
		if (a[i] - N > N - a[i])
			x = a[i] - N;
		else
			x = N - a[i];
		i = a[i];
		if (BigBusStop(i, a, nstops) == i)
		{
			int p = 0;
			for (int j = 0; j < nstops; j++)
			{
				if (a[j + 1] == M)
				{
					S += 1;
					break;
				}
				if (M < a[j + 1] && M > a[j])
				{
					if (a[j + 1] - M > M - a[j])
						x = M - a[j];
					else
						x = a[j + 1] - M;
					break;
				}
				S += 2;
			}
			break;
		}
	}
	cout << S + x;
}

int main()
{
	int BusStops;
	int nstops;
	cin >> BusStops >> nstops;
	int *a = new int[nstops];
	for (size_t i = 0; i < nstops; i++)
	{
		cin >> a[i];
	}
	int N, M;
	cin >> N >> M;
	Funktion(a, N, M, nstops);
	cout << " ";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
