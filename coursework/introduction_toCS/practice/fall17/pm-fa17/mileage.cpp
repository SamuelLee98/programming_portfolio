#include <iostream>
#include <fstream>

#include "mlib.h"
using namespace std;


/**
 * main
 *
 * Description:  Overall application should read in mpg information from
 *               the file specified at the command line and then
 *               take pairs of integers representing speed (in mph) followed by
 *               the number of minutes driven at that speed.
 *               It should then output the number of gallons consumed by 
 *               each car type for the given journey and, finally, output
 *               the car type with the minimum fuel consumption.
 *          
 * Parameters:
 *    argc      Number of command line arguments
 *
 *    argv      array of pointers to character arrays which are the command
 *              line arguments
 * 
 * Returns:
 *   0 if normal execution complete
 *   1 if the command line argument is not provided or if the provided
 *     filename does not represent a valid file
 */
int main(int argc, char* argv[])
{
  //---------- YOU COMPLETE! --------------------
  // YOU CAN STILL GET A FEW POINTS OF CREDIT FOR
  // PARTIALLY WORKING CODE
  //---------------------------------------------
	if (argc < 2)
	{
		cout << "No filename error" << endl;
		return 1;
	}
	ifstream ifile(argv[1]);
	if (ifile.fail())
	{
		cout << "File open error" << endl;
		return 1;
	}

	int numCarTypes; 

	int** mpg_array = read_mpg(argv[1], &numCarTypes); 


	int speed, time;

	double* total_gallons = new double[numCarTypes];
	int i = 0;

	do 
	{
		cin >> speed >> time; 

		double total = 0;

		for(int a=0; a<numCarTypes; a++)
		{
			
			total+=convert_speed_time_to_gallons(speed, time, mpg_array[a]);
		}

		total_gallons[i] = total;

		i++;
	}

	while (speed != -1 && time != -1);

	for (int j=0; j<numCarTypes; j++)
	{
		cout << i << " " << total_gallons[j] << endl;
	}

	



	for (int z=0; z < numCarTypes; z++)
	{
		delete[] mpg_array[z];
	}

 	delete[] mpg_array; 

 	delete[] total_gallons;

	return 0;
}
