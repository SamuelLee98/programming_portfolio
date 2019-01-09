#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


// sum an array of numbers
int test1(int *data, int len)
{
  int sum = 0;
  for(int i=0; i < len; i++){ //the bounds on this was wrong!
    sum += data[i];
  }
  return sum;
}

// Allocate a random number array
char* test2_init(int len)
{
  char buf[80];
  cout << "Enter a word: ";
  cin >> buf;
  char* mydat = new char[strlen(buf)+1];
  strcpy(mydat, buf);
  return mydat;
}

char* test2_reverse(char* word)
{
  int len = strlen(word);
  char* otherword = new char[len+1]; //last array is len
  
  for(int i=0; i < strlen(word); i++){
    otherword[i] = word[len-i-1];
  }
  otherword[len] = '\0'; //it cant be len+1 because we didn't allocate enough mem
  //delete [] word;
  return otherword;
}

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please enter the test number you want to run [1-2]" << endl;
    return 1;
  }
  const int len = 7;
  int test = atoi(argv[1]);

  if(test == 1){
    // Test should sum up the array values and print it
    int *data = new int[len];
    for(int i=0; i < len; i++){
      data[i] = rand()%100;
    }
    int sum = test1(data, len);
    cout << "Test 1 sum is " << sum << endl;
    delete [] data; //have to deallocate data after u use it
  }

  else if(test == 2){
    // Test should create a random string & then reverse a copy
    char* myword = test2_init(len);
    cout << "myword is " << myword << endl;
 
    char* otherword = test2_reverse(myword);    
    cout << "otherword is " << otherword << endl;
   
    delete [] myword; 
    delete [] otherword;
  }
  else {
    cout << "Unknown test number" << endl;
  }

  return 0;
}
