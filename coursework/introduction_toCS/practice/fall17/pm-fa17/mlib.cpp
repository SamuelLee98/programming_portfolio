#include <iostream>
#include <fstream>

using namespace std;

/**
 * read_mpg function
 *
 * Description:  Opens and reads the contents of the file given by filename.
 *          
 * Parameters:
 *    filename points to a character array containing the name of the file
 *             to open and read.
 *    n        points to an integer that your function must overwrite with the
 *             number of car types read from the file.
 * 
 * Returns:
 *   array of arrays of integers. A pointer to an array of integer pointers
 *             that each point to an array of 4 integers representing
 *             the mpg of the car at speeds 0-19, 20-39, 40-59, 60 and up.
 *   (Note: Though it is not a literal return value, you should use the 
 *          pointer, n, to set the number of car-types)
 *
 * Errors to Check: Return NULL (and don't leak memory) if you are unable to 
 *                  open the file given by 'filename'      
 *
 * The expected format of the file contains a number n on the first line
 * which should be read into the integer pointed to by parameter n 
 * followed by n additional lines with 4 integers each. Each line represents a 
 * car type (type 0 to n-1) and the 4 integers represent the mpg at speed 
 * intervals 0-19, 20-39, 40-59, 60 and up. An example is shown below
 *
 *   3
 *   25 20 40 30
 *   15 18 20 12
 *   25 45 40 35
 *
 * Note: Each row of 4 values is the consumption at different speed intervals 
 *       for a particlar car type.  [25 20 40 30] is the consumption for 
 *       car-type 0, [15 18 20 12] for car-type 1, etc.
 */
 
int** read_mpg(const char* filename,
               int* n)
{
  //---- YOU COMPLETE. YOU CAN STILL GET 5 PTS PARTIAL CREDIT
  //---- IF THIS FUNCTION WORKS BUT THE WHOLE APPLICATION
  //---- DOES NOT.

	// Use ifstream to read in inputs from file
	ifstream infile(filename); 

		infile >> *n; 

	
	// Dynamically allocate a 2D array
	int** fuel_rate = new int*[*n]; //is this allowed?

	for (int i = 0; i < (*n); i++)
	{
	    fuel_rate[i] = new int[4];
	}


	// Input data from file to 2D array
	for (int i=0; i<*n; i++)
	{
		for (int j=0; j<4; j++)
		{
			infile >> fuel_rate[i][j];
		}
	}

	// Return the 2D array
	return fuel_rate; 
}

/**
 * convert_speed_time_to_gallons function
 *
 * Description:  Converts the given speed and time to gallons of gas consumed
 *               using the mpg array.
 *          
 * Parameters:
 *    speed     integer representing the speed in *miles per hour* (can be any
 *              integer 0 or greater)
 *    minutes   integer representing the number of minutes driven at the given
 *              speed (can be any integer 0 or greater).
 *    mpg_array integer array of size 4 with entries representing the mpg
 *              of the given car type at speeds: 0-19, 20-39, 40-59, 60 and up.
 *              **Note: This is only a single row of the larger 2D array you
 *                      read in from the file. It should be the row that 
 *                      corresponds to the current car type for which you want 
 *                      to compute the consumption value.
 * 
 * Returns:
 *   number of gallons (as a double) consumed to drive for the given time at
 *   the given speed.
 */
double convert_speed_time_to_gallons(
				     int speed,
				     int minutes,
				     int* mpg_array)
{
  //---- YOU COMPLETE. YOU CAN STILL GET 5 PTS PARTIAL CREDIT
  //---- IF THIS FUNCTION WORKS BUT THE WHOLE APPLICATION
  //---- DOES NOT.

	double gallon;
	int mpg_index; 
	double hour = minutes / 60.0;

	// Input data from file to 2D array
	if (speed >= 0 && speed <= 19)
	{
		mpg_index = 0;
	}
	if (speed >= 20 && speed <= 39)
	{
		mpg_index = 1;
	}
	if (speed >= 40 && speed <= 59)
	{
		mpg_index = 2;
	}
	if (speed >= 60)
	{
		mpg_index = 3;
	}


	gallon = (speed*hour)/(mpg_array[mpg_index]);
	
	return gallon;
}
