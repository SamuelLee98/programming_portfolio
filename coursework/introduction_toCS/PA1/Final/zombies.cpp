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
  /* Array with enough entries for the 
     maximum population size possible.*/
  bool pop[MAXPOP];

  /****Prompt and initialize*****/
 


  int N, k, M, s; 
  cout << "Enter the size of the total population, "; 
  cout << "the number of initial zombies, ";
  cout << "the number of simulations, and a seed:";
  cin >> N >> k >> M >> s;
  if (k > N)
  {
  	cout << "Number of zombies cannot exceed the total population." << endl;
  	return 0;
  }

  /****Fill array*****/
  //fill first k number of arrays as zombies.
  for (int i = 0; i < k; i++) 
  {
  	pop[i] = true;
  }

  //fill remaining number of arrays as humans
  for (int  i = k; i < N; i++) 
  {
  	pop[i] = false;
  }

/***The Simulation***/
//array to store number of nights, per simulation
srand(s);
double totalnights[100000]; 

	for (int j = 0; j < M; j++) //repeats simulations
	{
		int new_k = k; //stores updated number of zombies 
		double night = 0;
		while (new_k < N) 
		{
		  	int bite = 0; 
		    for (int i = 0; i < new_k; i++) //zombie "picks" new victim 
		    {
		      int r = rand()%N;
		      if (pop[r] == false) //if victim = human, turn bite
		      {
		      	pop[r] = true;
		      	bite++;
		      }
		  	}
		    new_k += bite; //updates the number of zombies
		    night++;
		}

		totalnights[j] = night; //store the number of nights for comparison

		for (int i = 0; i < k; i++) //reset the array 
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

	cout << "Average Nights: " << avg << endl;

	double max = totalnights[0];
	for (int i = 1; i < M; i++) //computes max
	{
		if (totalnights[i] > max)
		{
			max = totalnights[i];
		}
	}
	cout << "Maximum Nights: " << max << endl;

	double min = totalnights[0]; //computes min
	for (int i = 1; i < M; i++)
	{
		if (totalnights[i] < min)
		{
			min = totalnights[i];
		}
	}
	cout << "Minimum Nights: " << min << endl;

 return 0;
}
