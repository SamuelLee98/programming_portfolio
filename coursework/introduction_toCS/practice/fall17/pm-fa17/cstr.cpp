#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
 * to_cstr function
 *
 * Description:  Produces and returns a valid C-string (character array) that
 *               contains a copy of the contents in the C++ string, orig.
 *          
 * Parameters:
 *    orig      C++ string whose contents should be copied into a C-string
 * 
 * Returns:
 *   pointer to a character array containing the copy. It should be a 
 *   valid C-string and wholly separate from 'orig'
 */
char* cstr(string orig)
{
  //******** You complete *************

  int len = orig.length(); 

  char* cs = new char[len+1]; 


  for (int i=0; i<len; i++ )
  {
    cs[i] = orig[i];
  }

  return cs; 
}

// -------- Do not change the following 2 lines--------------
#ifndef CSTR_TEST
#define CSTR_TEST

int main()
{
  string s1 = "Hello world";
  string s2 = "USC";

  char* cs1 = cstr(s1);
  char* cs2 = cstr(s2);

  //*** Feel free to add more code to test your function ****

  // prove cs1 is a separate copy by changing s1
  s1 = "Bye";

  cout << cs1 << endl;  // prints: Hello world
  cout << cs2 << endl;  // prints: USC

  /* Other code to do any necessary cleanup */
  delete [] cs1;
  delete [] cs2;

  return 0;
}
//***** Do not change the following line******
#endif
