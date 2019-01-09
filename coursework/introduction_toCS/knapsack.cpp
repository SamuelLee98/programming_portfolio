#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Another helper
int minWeight(const vector<int>& weights){
  int min = weights[0];
  for(unsigned int i=1; i < weights.size(); i++){
    if(weights[i] < min) min = weights[i];
  }
  return min;
}



// client interface
void genOptions(int limit, vector<int >& weights)
{
  vector<int> myknapsack;
  int min = minWeight(weights);
  vector<int> items;
  genOptions(limit, weights, items);

}

int totalWeight (const vector<int>& items)
{
	int total =0;
	for (int i=0; i<items.size(); i++)
	{
		total += items[i];
	}

	return 0;
}

int printItems(const vector<int>& items)
{
	for (int i=0;i<items.size(); i++)
	{
		cout << items[i] << " ";
	}

	cout << endl;
}

void genOptions(int limit, vector<int>& weights, vector<int> items)
{
	if (totalWeight(items) + weights[i] <= limit)
	{
		printItems(items);
		return;
	}

	for (int i=0; i<weights.size(); i++)
	{
		items.push_back(weights[i]);
		genOptions(limit, weights, items);
		items.pop_back();
	}
}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./knapsack weight_limit [item_weights]" << endl;
    return 1;
  }
  int limit;
  limit = atoi(argv[1]);
  vector<int> weights;
  for(int i=2; i < argc; i++){
    weights.push_back(atoi(argv[i]));
  }
  genOptions(limit, weights);
  return 0;
}
  
