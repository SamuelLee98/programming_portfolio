#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main(int argc, char *argv[])
{
  if(argc < 3){
    cout << "Please enter the name of the file to read as an argument and the integer to search for" << endl;
    return 1;
  }

  // Declare the ifstream variable here an open the file
  // specified as the 1st command line argument
  ifstream ifile(argv[1]);
  if(ifile.fail())
  {
    cout << "Unable to open file: " << argv[1] << endl;
    return 1; 
  }

  // Read the number of integers specified on the first line
  // into the following variable
  int numInts;
  ifile >> numInts;
  
  // Dynamically allocate an array of ints of size: numInts
  //  using the 'new' operator
  int* data = new int[numInts];

  // Read the integers on the 2nd line of text in the file into
  //  the array you allocated
  for (int i=0; i<numInts; i++)
  {
    ifile >> data[i];
  }

  // Convert the 2nd command line argument to an integer named searchval
  int searchval = atoi(argv[2]);
  int occurences = 0;
  for (int i=0; i<numInts; i++)
  {
    occurences += data[i] == searchval ? 1:0; //if equal inrease by one. other wise increase by 0
  }

  // Average the last uhalf of the array


  cout << searchval << " appears " << occurences << " times." << endl;

  // Use delete to deallocate the array you new'ed



  return 0;
}
