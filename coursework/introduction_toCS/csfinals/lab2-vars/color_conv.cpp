#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here
	double r, g, b; 

	cout << "Please enter r, g, and b values: "; 

	cin >> r >> g >> b;

	double R = r/255; 
	double G = g/255; 
	double B = b/255; 

	double largest = max(B,max(R,G));

	double cyan = (largest-R) / (largest);
	double magenta = (largest-G) / (largest);
	double yellow = (largest-B) / (largest);

	double black = 1- largest;

	cout << cyan << " " <<  magenta << " " << yellow << " " << black << endl;

   return 0;
}
