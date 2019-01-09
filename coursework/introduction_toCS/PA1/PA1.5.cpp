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
  
  for (int i=k; i < N; i++)
  {
  	pop[i] = false;
  }

  /**Shuffle Array***/
  srand(s);
  for (int i = 0; i < N; i++)
  {
    int r = rand()%N; 
    int temp = pop[i]; 
    pop[i] = pop[r]; 
    pop[r] = temp;
  }

  //test
  /*for (int i = 0; i < N; i++)
  {
    cout << pop[i] << endl;
  }
  cout << endl;*/


  /***Turn k number of humans into zombies. 
  Update the number of zombies. 
  Repeat until number of zombies is equal to N **/
  int nights = 0;
  while (k < N)
  {
    for (int i = 0; i < k; i++) //turn the first k # of shuffled array into true. 
    {
      pop[i] = true; 
    }

    for (int i = 0; i < N; i++) //new total numbeer of zombies (k)
    {
      if (pop[i] == true)
      {
        k++; //problemquit
      }
    }

    for (int i = 0; i < N; i++) //randomize array again
    {
    int r = rand()%N; 
    int temp = pop[i]; pop[i] = pop[r]; pop[r] = temp;
    }
    nights++;
  }

  //test
  cout << k << " " << nights << endl;
  for (int i = 0; i < N; i++)
  {
    cout << pop[i] << endl;
  }

return 0;
}