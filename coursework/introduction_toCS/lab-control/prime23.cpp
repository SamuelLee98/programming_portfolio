#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main () {
	int x;
	cout << "Enter a positive integer: ";
	cin >> x; 

	int counter_two = 0;
	int counter_three = 0;

	while (x%2 == 0){
		x = x/2;
		counter_two++;
	}

	while (x%3 == 0){
		x = x/3;
		counter_three++;
	}

	if (x == 1) {
		cout << "Yes" << endl;
		cout << "Twos=" << counter_two << " ";
		cout << "Threes=" << counter_three << endl;
	}

	else {
		cout << "No" << endl;
	}

return 0;

}