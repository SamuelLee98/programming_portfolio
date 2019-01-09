#include <iostream> 
#include <cmath>

using namespace std; 

int main() {

	int x;
	
	cout << "Enter Digit between 0 and 999" << endl;

	cin >> x;

	int ones = x % 100 % 10;
	int tens = (x % 100 - ones)/10;
	int hundreds = x/100;

	cout << "ones: " << ones << endl;

	cout << "tens: " << tens << endl;

	cout << "hundreds: " << hundreds << endl;


	return 0;
}