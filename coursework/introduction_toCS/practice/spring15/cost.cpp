#include <iostream> 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


void read(const char filename[], int* n, double numbers[], string items[]);

int main (int argc, char* argv[]) 
{
	int n = 0;
	double numbers[100];
	string items[100]; 

	int m=0;
	double price[100];
	string stuff[100];

	read(argv[1], &n, numbers, items); //recipe
	read(argv[2], &m, price, stuff); //price

	double total=0.0;
	
	for (int i = 0; i < m; i++)
	{
		bool impossible = false; 

		for(int j=0; j<n; j++)
		{
			if(stuff[i]==items[j])
			{
				total += price[i]*numbers[j];

			}

			if(stuff[i]!=items[j])
			{
				impossible = true;
			}

		}
	}

	if(impossible)
		{
			cout << "impossible" << endl;
				
			return 0;
		}

	cout << n << m << total << " deez nuts" << endl;

return 0;
}

void read(const char filename[], int* n, double numbers[], string items[])
{
	ifstream ifile; //read in the recipe
	
	ifile.open(filename); //why just file name??

	while (!(ifile.fail())) 
	{
		ifile >> numbers[*n] >> items[*n];

		if (!ifile.fail())
		{
			*n = *n + 1;
		}
		
	}

}
		
