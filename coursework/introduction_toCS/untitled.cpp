#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std; 

void mergeSort(vector<int>& x)
{
	if(x.size() == 1 || x.size() == 0)
	{
		return x;
	}

	vector<int>::iterator it=x.begin(x.begin()+x.size()/2;
	vector<int> left(x.begin(), it);
	left = mergeSort(left);
	vector<int> right = mergeSort(++it, x.end()));
}

int main(int argc, char const *argv[])
{
	 vector <int> x(10);
	 for (int i=9; i>0; i--)
	 {
	 	x[9-i] = i;
	 }

	 return 0;
}