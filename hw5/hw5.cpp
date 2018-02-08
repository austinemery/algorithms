//Algorithms Homework 5

#include <iostream>
#include <string>
#include <algorithm>

#define N 4

using namespace std;

int l[N] = {10, 1, 10, 10};
int h[N] = {5, 50, 5, 1};
int moneyForWeek[N] = {0, 0, 0, 0};
int choiceForWeek[N] = {0, 0, 0, 0};
int total = 0;

int optSol(int);

int main ()
{
	cout << "Best Monies: " << optSol(N - 1) << endl << "Best Path: ";
	for (int i = 0; i < N; i++)
	{
		cout << moneyForWeek[i] << ' ';
	}
	cout << endl << "Best Choices: ";

	for (int i = 0; i < N; i++)
	{
		if (choiceForWeek[i] == -1)
		{
			cout << "Low ";
		}
		else if (choiceForWeek[i] == 0)
		{
			cout << "None ";
		}
		else
		{
			cout << "High ";
		}
	}
	cout << endl;
}
//n is length of arrays - 1, l is lowstress array, h is highstress array
int optSol(int n)
{
	int tempHigh;
	int tempLow;

	if (n == 0)
	{	
		if (l[n] > h[n])
		{
			moneyForWeek[n] = l[n];
			choiceForWeek[n] = -1;
		}
		else
		{
			moneyForWeek[n] = h[n];
			choiceForWeek[n] = 1;
		}
		return moneyForWeek[n];
	}
	if (n == 1)
	{
		tempLow = optSol(n-1);
		if (l[n] + tempLow > h[n])
		{
			moneyForWeek[n] = l[n];
			choiceForWeek[n] = -1;
			return moneyForWeek[n] + tempLow;
		}
		else 
		{
			moneyForWeek[n] = h[n];
			moneyForWeek[n - 1] = 0;
			choiceForWeek[n] = 1;
			choiceForWeek[n - 1] = 0;
			return moneyForWeek[n];
		}
	}
	tempLow = optSol(n-1);
	tempHigh = optSol(n-2);
	total = max(l[n] + tempLow, h[n] + tempHigh);
	if (l[n] + tempLow > h[n] + tempHigh)
	{
		moneyForWeek[n] = l[n];
		choiceForWeek[n] = -1;
	}
	else 
	{
		moneyForWeek[n] = h[n];
		moneyForWeek[n - 1] = 0;
		choiceForWeek[n] = 1;
		choiceForWeek[n - 1] = 0;
	}
	return total;
}