/*******************************************************
 * cS 103 Zombie-pocalypse PA
 * Name: Samuel Kyu Seo Lee
 * USC email: lee344@usc.edu
 * Comments (you want us to know): this program takes in 
 * user input (population, zombie population, number of simulations 
 * and a seed) and out puts the avg, max, and min number of nights
 * it takes to make the entire population zombies. 
 ********************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAXPOP = 100000;

int main()
{
  // Array with enough entries for the maximum population size possible.
  bool pop[MAXPOP];

  /****Prompt and initialize*****/
  int N, k, M, s;
  cout << "Enter the size of the total population, the number of initial zombies, ";
  cout << "the number of simulations, and a seed:";
  cin >> N >> k >> M >> s;
  if (k > N)
  {
  	return 0;
  }

  /****Fill array*****/

  for (int i = 0; i < k; i++)
  {
  	pop[i] = true;
  }
  
  for (int  i = k; i < N; i++)
  {
  	pop[i] = false;
  }

  //int simulation = 0;
  //int arraynight[10000];
  //while (simulation < s)
  //{
    /**if zombie, pick a random person and make them a zombie. Run until k = N***/
    int night = 0;
    srand(s);
    while (k < N)
    {
      int j = k;
      for (int i = 0; i < j; j++)
      {
        if (pop[i] == true)
        {
          int r = rand()%N;
          if (pop[r] == false)
          {
            pop[r] = true;
            k++;
          }
        //}
      //arraynight[i] = night; 
        }
      }
      night++;
    //}
 // simulation++;
    }

  //for (int i = 0; i < N; i++)
  //{
    cout << night << endl;
  //}
  return 0;
}
 