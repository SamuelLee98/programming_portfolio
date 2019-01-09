#include <iostream>
#include "bigint.h"

using namespace std;

BigInt::BigInt(string s) //constructor
{

	int temp;
	for(int i=0; i<s.size(); i++) 
	{
		num.push_back(s[i]); //put string in to vector
		num[i] -= 48; //turn ASCII into integers. 
	}


	for(int i=0; i<(num.size()/2); i++) //reverse
	{
		temp = num[i]; 
		num[i] = num[num.size()-i-1];
		num[num.size()-i-1] = temp;

	}
}

string BigInt::to_string() 
{

	string numPrint = "";

	for (int i=num.size()-1; i>=0; i--) //just decrement, dont need to reverse
	{
		
		numPrint += (char)(num[i]+48);
	}

	return numPrint;
}

void BigInt::add(BigInt other) //other is a integer in "reverse order"
{
	// cout << endl << num.size();

	 bool carry; 
	
	if(num.size() > other.num.size()) //if num has more digits
	{
		for (int i=0; i<num.size()-other.num.size(); i++)
		{
			other.num.push_back(0);
		}
	}

	else if (num.size() < other.num.size()) //if other has more digits
	{
		for (int i=0; i<other.num.size()-num.size(); i++)
		{
			num.push_back(0);
		}
	}

	for (int i=0; i<num.size(); i++)
	{
		num[i] += other.num[i]; 

		if(num[i]>9)
		{
			carry = true;
			num[i] -= 10; //subtract 10 from current
			num[i+1]++; //incrememt next digit 
		}

		if(carry && i== num.size()-1) //if ur at the end and carry is true. 
		{
			num.push_back(1);
		}

		carry = false;
	}

}


