#include <iostream>
#include <cmath> 

/*Author: Samuel Lee
Program: digits
Description: Takes in a three digit number and divides it in to its constitutents.
*/

using namespace std; 

int main()
{
	//define variable x
	int x;

	//prompt user for input
	cout << "Enter a digit between 0 and 999: ";

	//receive input and store it in variable x
	cin >> x; 

	// //calculations using modulus
	int ones = x % 10; //finds modulus of x and 10
	int tens = (x % 100) / 10;  // finds modulus of x and 100, subtracts one's digit then divides by 10 to isolate the 10's digit
	int hundreds = x / 100; //same function as above except it subtracts tens and ones and divides by 100 to silate 100's digit

	//outputs the calculatons made above to the user. 
	cout << "1's digit: " << ones << endl;
	cout << "10's digit: " << tens << endl; 
	cout << "100's digit: " << hundreds << endl;

	return 0;
}

// void printNum(int x){
// 	return (x == 0) ? NULL : {  printNum(x/10); cout << x % 10; };
// }