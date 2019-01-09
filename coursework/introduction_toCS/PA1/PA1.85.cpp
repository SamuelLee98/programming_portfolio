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

  int N, k, M, s; //N = Population; k  = number of zombies; M = number of simulations; s = seed
  cout << "Enter the size of the total population, the number of initial zombies, ";
  cout << "the number of simulations, and a seed:";
  cin >> N >> k >> M >> s;
  if (k > N)
  {
  	return 0;
  }

  /****Fill array*****/

  for (int i = 0; i < k; i++) //fill first k number of arrays as zombies.
  {
  	pop[i] = true;
  }
  
  for (int  i = k; i < N; i++) //fill remaining number of arrays as humans
  {
  	pop[i] = false;
  }

/***The Simulation***/

srand(s);
double totalnights[1000000]; //array to store number of nights, per simulation

	for (int j = 0; j < M; j++) //repeats simulations
	{
		int new_k = k; //stores updated number of zombies after each night
		double night = 0;
		while (new_k < N) 
		{
		  	int bite = 0; 
		    for (int i = 0; i < new_k; i++) //each zombie chooses a new random 'victim.' 
		    {
		      int r = rand()%N;
		      if (pop[r] == false) //if the victim is a human, turn him into a zombie
		      {
		      	pop[r] = true;
		      	bite++;
		      }
		  	}
		    new_k += bite; //updates the number of zombies
		    night++;
		}

		totalnights[j] = night; //store the number of nights in an array for comparison later

		for (int i = 0; i < k; i++) //reset the array for next simulation
	 	{
	  		pop[i] = true;
	  	}
	  
	  	for (int  i = k; i < N; i++)
	  	{
	  		pop[i] = false;
	  	}

	}

	/***Compute average, min, and max***/
	
	double total = 0; //Computes average
	for (int i = 0; i < M; i++)
	{
		total += totalnights[i];
	}
	double avg = total / M;

	cout << "Average Number of Nights: " << avg << endl;

	double max = totalnights[0];
	for (int i = 1; i < M; i++) //computes max
	{
		if (totalnights[i] > max)
		{
			max = totalnights[i];
		}
	}
	cout << "Maximum Number of Nights: " << max << endl;

	double min = totalnights[0]; //computes min
	for (int i = 1; i < M; i++)
	{
		if (totalnights[i] < min)
		{
			min = totalnights[i];
		}
	}
	cout << "Minimum Number of Nights: " << min << endl;

 return 0;
}
