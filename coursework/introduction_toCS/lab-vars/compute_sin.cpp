#include <iostream>
#include <cmath>

/* Author: Samuel Lee
 * Program: compute_sin
 * Description: Reads a number x from input, an angle in radians. 
 *    Computes an approximation to sin(x) using an 4th-order Taylor series.
 */

using namespace std;

int fact(int); // declares a function the skeleton defines for you.

int main(int argc, char *argv[])
{
   // Declare any variables you need here
   double x;
   
   // Prompt the user
   cout << "Enter x in radians: ";
   
   // get input
   cin >> x;
   
   // Do some operations
   double first = (pow(x,1) / fact(1));
   double second = (pow(x,3) / fact(3));
   double third = (pow(x,5) / fact(5));
   double fourth = (pow(x,7) / fact (7));
   double sum = first - second + third - fourth;
   
   // Print the result to the user
   cout << "The fourth order talor series of sin("<< x <<") is equal to "<< sum << endl;
  
   // You're done
   
   return 0;
   
}

// here's the actual definition of fact, declared earlier.
int fact(int n)
{
   int result = 1;
   for (int i = 1; i <= n; i++) {
      result = result * i;
   }
   return result;
}

