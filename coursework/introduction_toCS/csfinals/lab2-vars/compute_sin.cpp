#include <iostream>
#include <cmath>

/* Author: YOUR NAME HERE
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
   cout << "Enter x in radians:  ";
   
   // get input
   cin >> x; 
   
   // Do some operations
   double term1 = x;
   double term2 = pow(x,3)/6; 
   double term3 = pow(x,5)/120;
   double term4 = pow(x,7)/5040; 

   double total = term1-term2+term3-term4;
   
   // Print the result to the user
   
   cout << total << endl;
   
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

