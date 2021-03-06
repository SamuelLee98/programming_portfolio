#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void sort(int *, int);
int binsearch(int, int *, int, int);
void swap(int&, int&);
int min_position(int*, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  // Uncomment the line below for part 2
  sort(data, count);

  // Call binary search
  int retval = binsearch(target,data,0,count);

  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Deallocate the data array
  delete [] data;
  return 0;
}



int min_position(int data[], int start, int end)
{
  int min_pos = start; 
  for (int i = start +1; i <= end; i++)
  {
    if(data[i] < data[min_pos])
    {
      min_pos = i;
    }
  }

  return min_pos;
}

void swap(int& x, int& y)
{
  int temp = x;
  x = y;
  y = temp;
}
// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
// You aren't allowed to change the prototype of this function
void sort(int *data, int len)
{
  int next;//next pos to be set to the min
  for(next=0; next<len; next++)
  {
    int min_pos = min_position(data, next, len-1);

    if(min_pos != next)
    {
      swap(data[min_pos], data[next]);
    }
  }
}

void rSort(int* data, int len)
{
  int next = 0;
  if (next == len)
  {
    
  }
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{
  if (start > end)
  {
    return -1;
  }

  int mid = (start + end) / 2;
  if (data[mid] == target)
  {
    return mid;
  }

  else if(data[mid] < target)
  {
    return binsearch(target, data, mid+1, end);
  }

  else 
  {
    return binsearch(target, data, start, mid-1);
  }
}


