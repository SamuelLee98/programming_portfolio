
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>

using namespace std;

int main () 
{
 
    int degrees;
    cout << "Please enter an angle between 15 and 75: ";
    cin >> degrees;
    
    double radians = (M_PI/180) * degrees;
    
    for (int y = 0; y < 31; y++)
    {
        double new_bound = floor (y*tan(radians));

        if (new_bound >= 20 and new_bound <= 30) 
        {
           	for (int base = 0; base < 20; base++)
            {
            	cout << "*";
            }
		}	
        else
        {
        	for (int x = 0; x < new_bound; x++) 
        	{
        		cout << "*";
        	}
       	}
        cout << endl; 
    }   
  return 0;
}