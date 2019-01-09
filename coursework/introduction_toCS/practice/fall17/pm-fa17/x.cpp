#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * Prints an n by n X pattern to the screen
 * See the website for details
 *
 * Note: n is input as the 1st command line argument
 *       after the program name
 */
int main(int argc, char* argv[])
{
  if(argc < 2){
    cout << "Please provide a value of n" << endl;
    return 1;
  }
  //******* You complete ***************

  	// If n is a negative or 0, return 0
	if (argv[1] <= 0)
	{
		return 0;
	}

	// Dynamically allocate 2D array
	int n = atoi(argv[1]);

	char** grid = new char*[n];

	for (int i = 0; i < (n); i++)
	{
       grid[i] = new char[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int distance_left_side = 0;
			int distance_right_side = n - 1;
			distance_left_side = distance_left_side + i;
			distance_right_side = distance_right_side - i;
			if (distance_right_side == distance_left_side)
			{
				cout << "X";
			}
			else if (j == distance_left_side)
			{
				cout << "\\";
			}
			else if (j == distance_right_side)
			{
				cout << "/";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}


	for (int i=0; i < n; i++)
	{
		delete[] grid[i];
	}
	delete[] grid; 

	return 0;
}
