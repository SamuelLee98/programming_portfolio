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
  
  for (int i=k; i < N; i++)
  {
  	pop[i] = false;
  }

  /***Randomly chooses from pop[] and stores it temp_pop[].. No repeating indices***/
  srand(s);
  bool temp_pop[MAXPOP]; //see if u can use k instead of maxpop
  int z = 0;
  while (z < k)
  {
  	int r1 = rand()%(N+1);
  	int r2 = rand()%(N+1);

  	if (r1 == r2)
  	{
  		temp_pop[z] = r1;
  		z++;
  	}

  	else
  	{
		temp_pop[z] = pop[r1]; 
		temp_pop[z+1] = pop[r2];
		z = z +2;
  	}
  }

  /***Turn randomly chosen individuals into zombies***/
  for (int i = 0; i < k; i++)
  {
  	if (temp_pop[i] == false) //if human
  	{
  		temp_pop[i] = true;
  	}
  }
  	
  /***Go back to pop[] and replace k# of falses with trues***/

  for (int i = 0; i < N; i ++)
  {
  	int j = 0;
  	while (j<k)
  	{
  		if (pop[i] == false)
  		{
  			pop[i] = true;
  			i++; 
  			j++;
  		}
  		else
  		{
  			i++;
  		}
  	}
  }

for (int i = 0; i < N; i ++)
{
	cout << pop[i] << endl;
}
 
 
  // Print out your average, max, and min number of nights here
  // Be sure to follow the format shown in the assignment writeup.

  return 0;
}