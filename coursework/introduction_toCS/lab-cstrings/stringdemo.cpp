#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char mystring[80] = "Computer Science";
	char yourstring[80];
	char *astring = 0;

	//yourstring = mystring; //does this make a copy?
	//strncpy(astring, mystring, 80); //does this make a copy?

	astring = mystring; //is this illegal assignment? 
	strncpy(yourstring, mystring, 80); //make a copy?
	cout << astring << endl;
	cout << yourstring << endl; 

	mystring[0] = '*';  //which one actually made a copy?
	cout << astring << endl;
	cout << yourstring << endl; 

	return 0;
}
