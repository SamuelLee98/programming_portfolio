/***************************************
Name: Samuel Lee
Class: CS103
Comments: Simulates dice rolls and then 
plots them on a normal curve... 
***************************************/
#include <iostream>
#include <cmath> 
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <ctime>


using namespace std;

void printHistogram(int sumarray[])
{
	for (int i = 4; i <= 24; i++)
	{
		cout << i << ":";

		for (int j = 0; j < sumarray[i-4]; j++)
		{
			cout << "X";
		}
		cout << endl;
	}
}

int main ()

{
	srand(time(0));

	int roll[4];

	int n;

	
	int sumarray[21];

	for (int i=0; i < 21; i++)
	{
		sumarray[i] = 0;
	}

	cout << "enter a num: ";
	cin >> n;

	for (int j = 0; j < n; j++)
	{
		int sum = 0;

		for (int i = 0; i < 4; i++)
			{
				roll[i] = rand()%6 + 1;
				sum = sum + roll[i];
			}

		sumarray[sum-4] += 1;
	}

	printHistogram(sumarray);

	
return 0;
}
