#include <iostream>
#include <algorithm>

/* Author: Samuel Lee
 * Program: color_conv
 * Description: Converts from RGB to CYMB
 */

using namespace std;

int main()
{
	//declare variables.
   int red;
   int green;
   int blue;

	//prompts the user to enter integers for red, green, blue and receives input
   cout << "Enter Red between 0 and 255: ";
   cin >> red; 

   cout << "Enter Green between 0 and 255: ";
   cin >> green;

   cout << "Enter Blue between 0 and 255: ";
   cin >> blue; 

   //finds red/z, green/z, blue/z 
   const double z = 255;
   double r = (red / z);
   double g = (green / z);
   double b = (blue / z);


	//finds the maximum value out of r,g,b and sets it equal to the variable white. 
   double x = max(r,g);
   double y = max(g,b);
   double white = max(x,y);
   
 	//calculates cyan, magenta, yellow, black
   double cyan = ((white - r) / white);
   double magenta = ((white - g) / white);
   double yellow = ((white - b) / white);
   double black = (1 - white);
   
   //Displays cyan, magenta, and black to user. 
   cout <<"Cyan: " << cyan << endl;
   cout <<"Magenta: " << magenta << endl; 
   cout <<"Yellow: " << yellow << endl; 
   cout << "Black: " << black << endl;
   
return 0;
}
