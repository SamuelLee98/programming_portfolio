#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "bmplib.h" //headerfile

using namespace std;

//============================Add function prototypes here======================
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11]); 

void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB]);

void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB]); 

void gaussian(double k[][11], int N, double sigma);

void gaussian_filter(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
					int N, double sigma);

void unsharp(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
			int N, double sigma, double alpha);

//============================Do not change code in main()======================

#ifndef AUTOTEST

int main(int argc, char* argv[])
{
  
   //First check argc
  if(argc < 3)
    {
      //we need at least ./filter <input file> <filter name> to continue
      cout << "usage: ./filter <input file> <filter name> <filter parameters>";
      cout << " <output file name>" << endl;
      return -1;
    }
   //then check to see if we can open the input file
   unsigned char input[SIZE][SIZE][RGB];
   unsigned char output[SIZE][SIZE][RGB];
   char* outfile;
   int N;
   double sigma, alpha;
   //double kernel[11][11];

   // read file contents into input array - check arg 1
   int status = readRGBBMP(argv[1], input); 
   if(status != 0) //if an integer other than 0
   {
      cout << "unable to open " << argv[1] << " for input." << endl;
      return -1;
   }
   //Input file is good, now look at next argument - check arg 2
   if( strcmp("sobel", argv[2]) == 0) 
   {
     sobel(output, input);
     outfile = argv[3];
   }
   else if( strcmp("blur", argv[2]) == 0) 
   {
     if(argc < 6) 
       {
		 cout << "not enough arguments for blur." << endl;
		 return -1;
       }
     	N = atoi(argv[3]);
     	sigma = atof(argv[4]);
     	outfile = argv[5];
     	gaussian_filter(output, input, N, sigma);
   }
   else if( strcmp("unsharp", argv[2]) == 0)
   {
     if(argc < 7) 
       {
		 cout << "not enough arguments for unsharp." << endl;
		 return -1;
       }
	    N = atoi(argv[3]);
	    sigma = atof(argv[4]);
	    alpha = atof(argv[5]);
	    outfile = argv[6];
     	unsharp(output, input, N, sigma, alpha);

   }
   else if( strcmp("dummy", argv[2]) == 0)
   {
     //do dummy
     dummy(output, input);
     outfile = argv[3];
   }
   else
   {
      cout << "unknown filter type." << endl;
      return -1;
   }

   if(writeRGBBMP(outfile, output) != 0)
   {
      cout << "error writing file " << argv[3] << endl;
   }

}   

#endif 

//=========================End Do not change code in main()=====================


// Creates an identity kernel (dummy kernel) that will simply
// copy input to output image and applies it via convolve()
//
// ** This function is complete and need not be changed.
// Use this as an example of how to create a kernel array, fill it in
// appropriately and then use it in a call to convolve.
void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   for (int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         k[i][j] = 0;
      }
   }
   k[1][1] = 1;
   convolve(out, in, 3, k);
}


// Convolves an input image with an NxN kernel to produce the output kernel
// You will need to complete this function by following the 
//  instructions in the comments
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11])
{
 
   int padded[SIZE+10][SIZE+10][RGB];  // Use for input image with appropriate 
                                       // padding
   int temp[SIZE][SIZE][RGB];          // Use for the unclamped output pixel 
                                       // values then copy from temp to out, 
                                       // applying clamping 

   //first set everything, including the padding to black
   	for (int i=0; i<SIZE+N-1; i++) //row
   	{
   		for (int j=0; j<SIZE+N-1; j++) //column
   		{	
   			for (int k=0; k<RGB; k++) //plane
			{
		   		padded[i][j][k] = 0;

			}
   		}
   	}

   //now copy input into padding to appropriate locations
   	for (int i=0; i<SIZE; i++)
   	{
   		for (int j=0; j<SIZE; j++)
   		{
   			for (int k=0; k<RGB; k++)
   			{
   				padded[i+(N/2)][j+(N/2)][k] = in[i][j][k]; 
   			}
   		}
   	}

   //initialize temp pixels to 0 (black)
	for (int i=0; i<SIZE; i++)
	   	{
	   		for (int j=0; j<SIZE; j++)
	   		{
	   			for(int k=0;k<RGB;k++)
	   			{
	   				temp[i][j][k] = 0;
	   			}
	   		}
	   	}


  //now perform convolve (using convolution equation on each pixel of the 
  // actual image) placing the results in temp (i.e. unclamped result)
  //Here we give you the structure of the convolve for-loops, you need
  //to figure out the loop limits
  for(int y=0;y<SIZE ;y++)
    for(int x=0 ;x<SIZE ;x++)
      for(int k=0;k<RGB;k++)
         for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                  temp[y][x][k] += padded[y+i][x+j][k]*kernel[i][j];


   //now clamp and copy/cast to output
   for(int y=0;y<SIZE; y++)
   {
   		for(int x=0; x<SIZE; x++)
   		{
			for(int k=0;k<RGB;k++)
			{
				if (temp[y][x][k]<0)
				{
					temp[y][x][k] = 0;
				}

				if (temp[y][x][k]>255)
				{
					temp[y][x][k] = 255;
				}

				out[y][x][k] = (unsigned char) temp[y][x][k]; 
			}
   		}
    }


}

// You will need to complete this function by following the 
//  instructions in the comments
void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   double s_h1[3][3] = { {-1, 0, 1}, 
                         {-2, 0, 2}, 
                         {-1, 0, 1} };
   double s_h2[3][3] = { {1, 0, -1}, 
                         {2, 0, -2}, 
                         {1, 0, -1} };
   
   unsigned char h1_soble[SIZE][SIZE][RGB]; //hold intermediate images
   unsigned char h2_soble[SIZE][SIZE][RGB]; 

   for (int i = 0; i < 11; i++)
   {
      for(int j=0; j < 11; j++)
      {
         k[i][j] = 0;
      }
   }

   // Copy in 1st 3x3 horizontal sobel kernel (i.e. copy s_h1 into k)

   for (int i=0; i<3; i++)
   {
   		for (int j=0; j<3; j++)
   		{
   			k[i][j] = s_h1[i][j];
   		}
   }

   // Call convolve to apply horizontal sobel kernel with result in h1_soble
   convolve(h1_soble, in, 3, k);

   // Copy in 2nd 3x3 horizontal sobel kernel (i.e. copy s_h2 into k)
    for (int i=0; i<3; i++)
   {
   		for (int j=0; j<3; j++)
   		{
   			k[i][j] = s_h2[i][j];
   		}
   }

   // Call convolve to apply horizontal sobel kernel with result in h2_soble
   convolve(h2_soble, in, 3, k);


   // Add the two results (applying clamping) to produce the final output 

   for (int i=0; i<256; i++)
   {
   		for (int j=0; j<256; j++)
   		{
   			for (int p=0; p<3; p++)  //'p' variable for RGB plane 
   			{
   				out[i][j][p] = h1_soble[i][j][p] + h2_soble[i][j][p];

   				if(out[i][j][p]>255)
   				{
   					out[i][j][p]=255;
   				}

   				if(out[i][j][p]<0)
   				{
   					out[i][j][p]=0;
   				}
   			}
   		}
   }
}

// Add the rest of your functions here (i.e. gaussian, gaussian_filter, unsharp)

void gaussian(double k[][11], int N, double sigma) //generate kernel. 
{

	for (int i = 0; i < 11; i++) //initialize kernals to 0
   	{
      for(int j=0; j < 11; j++)
      	{
        	k[i][j] = 0.0;
      	}
   	}

	double total = 0; 
	for (int i=0; i<N; i++) //raw gaussian and find total
	{
		for (int j=0; j<N; j++)
		{
			double y = i - N/2; //adjust so center of kernal is 0,0
			double x = j - N/2;
			double combine = ( pow((x),2) +  pow((y),2) ) / (2*pow(sigma,2)); 
			//provided equation
			k[i][j] = exp(-1*combine);

			total += k[i][j]; //add all raw values together
		}
	}

	for (int i=0; i<N; i++) //normalized gaussian
	{
		for (int j=0; j<N; j++)
		{
			k[i][j] = (k[i][j])/total; 

		}
	}
}

void gaussian_filter(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
					int N, double sigma)
{
	double k[11][11];
	gaussian(k, N, sigma); //get the correct kernal
	convolve(out, in, N, k); //convolve and put into out image
}

void unsharp(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
			int N, double sigma, double alpha)
{

	double k[11][11];  
	gaussian(k, N, sigma); //blur the image
	convolve(out, in, N, k); 

	for (int i=0; i<SIZE; i++) 
	{
		for (int j=0; j<SIZE; j++)
		{
			for (int p=0; p<RGB; p++)
			{
				int subBlur = in[i][j][p] - out[i][j][p];//subtract blur

				double add = in[i][j][p] + alpha*(subBlur); //add difference,
				// and apply alpha

				if (add < 0 ) //clamping
				{
					add = 0;
				}
				
				else if(add > 255) 
				{
					add = 255;
				}
				
				out[i][j][p] = (unsigned char)add; //caste and store in out

			}
		}
	}

}
