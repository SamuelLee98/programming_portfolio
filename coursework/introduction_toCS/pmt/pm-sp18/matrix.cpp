#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

#include "matrix_ops.h"

using namespace std;

//Program is called like: ./matrix t1.txt add
//First argument is filename
//Second argument is operation to perform
int main(int argc, char const *argv[])
{
	//First check if there are enough arguments
	if(argc < 3)
	{
		cout << "Not enough arguments: ./matrix <filename> <operation>" << endl;
		return 1;
	}

	//Now create an ifstream object and try to open the file,
	//If this fails print a message and return 1
	//See the writeup for the error message	
	
	ifstream infile(argv[1]);

	if (infile.fail())
	{
		cout << "\"Unable to open file: " << argv[1] << "\" where " << 
		argv[1] << "is the file name given as argv[1]" << endl;

		return 1;

	}

	//The first line of the file is #rows #cols for the A matrix.
	//Read in these two integer values into appropriately named variables
	int rows_A;
	int cols_A; 

	infile >> rows_A >> cols_A;

	//Pass these values to the matrix_allocate function to allocate 
	//a row x col sized array of doubles
	double** A = matrix_allocate(rows_A, cols_A);

	//Write the code needed to read in matrix A into 
	//the array you just allocated
	for (int i=0; i< rows_A; i++)
	{
		for (int j=0; j<cols_A; j++)
		{
			infile >> A[i][j]; 
		}
	}

	//The next line of the file is #rows #cols for the B matrix
	//Read in these two integer values into appropriately named variables
	int rows_B;
	int cols_B; 

	infile >> rows_B >> cols_B;

	//Pass these two values to the matrix_allocate function to allocate 
	//a row x col sized array of doubles
	double** B = matrix_allocate(rows_B, cols_B);
	
	//Write the code needed to read in matrix B 
	//into the array you just allocated

	for (int i=0; i< rows_B; i++)
	{
		for (int j=0; j<cols_B; j++)
		{
			infile >> A[i][j]; 
		}
	}
	
	//Now verify the dimensions are compatible with the operation specified.
	//The operation comes from the 2nd command line argument
	//If the dimensions aren't compatible, then quit with an error message
	//See the writeup for the error message.
	//If the 2nd command line argument isn't one of {add, subtract, multiply}
	//Then print out an error message and return 1. See writeup for message.
	//Return 1 in all failure cases

	double** result = NULL;
	int rows =0; 
	int cols = 0;
	
	if((strcmp(argv[2],"add")) || (strcmp(argv[2],"subtract")))
	{
		if((rows_A == rows_B)&&(cols_A==cols_B))
		{
		 	if(strcmp(argv[2],"add"))
		 	{
		 		result = matrix_add(A,B, rows_A, cols_A);
		 	}

		 	else 
		 	{
		 		result = matrix_add(A,B, rows_A, cols_A);
		 	}

		 	rows = rows_A;
		 	cols = cols_A;
		}

		else 
		{
			cout << "Number of rows and number of columns "<<
			"must match for add or subtract." << endl;
			return 1;
		}
	}

	else if(strcmp(argv[2],"multiply"))
	{
		if (cols_A!=rows_B)
		{
			
			cout << "Number of columns in A must match "<<
				"number of rows in B for multiply." << endl;
			return 1;
		}
		else 
		{
			result = matrix_multiply(A, rows_A, cols_A, B, 
	                     rows_B, cols_B );
			rows = rows_A;
			cols = cols_B;
		}
	}

	else
	{
		cout << "\"Unknown Operation: " << argv[2] << endl; 
		cout << "Valid operations: add, subtract, multiply\" where " 
			<< argv[2] << " is what was given as argv[2]." << endl;
	}

	//Now perform the operation. 
	//The functions matrix_add, matrix_subtract and matrix_multiply allocate 
	//the result matrix for you.
	//They will return a pointer to this matrix. 
	//Don't forget to caputure that pointer. You'll need it.
	
	//Store the size of the result in these variables.
	//For add and subtract it's easy, for multiply check the docs.
	

	//Based on the 2nd command line argument call the proper function in
	//matrix_ops. Set rows and cols to the proper value
	
	//At this point assuming your matrix_ops functions are correct,
	//then YOU'RE almost DONE! ;-) See below for one last thing.

	//We give you the code to print out the resulting matrix
	for(int r = 0; r<rows;r++)
	{
		for(int c = 0; c<cols;c++)
		{
			cout << fixed << setprecision(2) << setw(7) << result[r][c];
		}
		cout << endl;
	}

	//Now delete A, B and result using matrix_delete();
	
	for (int i=0; i<cols_A; i++)
	{
		delete[] A[i];
	}

	delete[] A;

	for (int i=0; i<cols_B; i++)
	{
		delete[] B[i];
	}

	delete[] B;


	for (int i=0; i<cols; i++)
	{
		delete[] result[i];
	}

	delete[] result;


	return 0;
}
