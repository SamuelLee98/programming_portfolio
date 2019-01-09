#include <iostream> 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std; 

void read(const char* filename[], int* n, double numbers[], string items[]);

int main (int argc, char* argv[]) 
{
	int n = 0;
	double numbers[100];
	string items[100]; 

	double scale = atof(argv[1]);

	read(argv[2], &n, numbers, items); 

	for (int i = 0; i < n; i++)
		cout << numbers[i]*scale << " " << items[i] << endl;



return 0;
}

void read(const char* filename[], int* n, double numbers[], string items[])
{
	ifstream ifile; //read in the recipe
	
	ifile.open(filename[2]);

	while (!(ifile.fail())) 
	{
		ifile >> numbers[*n] >> items[*n];

		if (!ifile.fail())
		{
			*n = *n + 1;
		}
		
	}

	ifile.close; 
}
		
