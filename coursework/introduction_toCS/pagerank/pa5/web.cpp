#include "web.h"
#include "page.h"
#include <sstream>

Web::Web()
{

}

Web::~Web()
{

}

bool Web::read_graph(const char *filename)
{
	ifstream ifile(filename); 

	if (ifile.fail()) //check
	{
		return false;
	}

	int numpages; //get number of pages. 

	ifile >> numpages; 

	if(ifile.fail()) //check 
	{
		return false;
	}

	for (int i=0; i < numpages; i++) //for each page...
	{
		string url;

		int id;

		ifile >> id; //read in web ID
		if (ifile.fail())
		{
			return false; 
		}

		ifile >> url; //read in URL
		if(ifile.fail())
		{
			return false;
		}
		Page single_page(id, url); //read in id and url (checked)

		double rank; //read in rank
		ifile >> rank;
		if (ifile.fail())
		{
			return false;
		}
		single_page.setRank(rank); 

		string spaceholder; //hold space to get to the next line
		getline(ifile, spaceholder);

		string temp_ss; //read in outgoing links
		getline(ifile,temp_ss);

		if(ifile.fail())
		{
			return false;
		}

		stringstream ss(temp_ss); 
		
		int temp_links; 
		
		while(ss >> temp_links) //read in outgoing links for that page
		{
			single_page.addLink(temp_links); 
		}

		pages.push_back(single_page);
	}

	return true;
}

bool Web::write_graph(const char *filename)
{
	ofstream ofile(filename); 
	
	if (ofile.fail())
	{
		return false; 
	}

	ofile << pages.size() << '\n'; 

	for (int i=0; i<pages.size(); i++) //for each page
	{
		ofile << pages[i].getID() << '\n'; //print out ID

		ofile << '\t' << pages[i].getURL() << '\n'; //print out URL

		ofile << '\t' << pages[i].getRank() << '\n'; //print out Rank

		vector<int> out_links = pages[i].getLinks(); //retreive vector of
		//outlinks

		ofile << '\t';
		for (int j=0; j<out_links.size(); j++) //cout the outlinks. 
		{
			ofile << out_links[j] << " "; 
		}

		ofile << '\n'; 
	}

	return true;
}

void Web::calculate_rank(int S,int N)
{
	int quotient = N/pages.size(); 

	int remainder = N%pages.size(); //in case it doesn't divide perfectly. 

	for (int i=0; i<pages.size(); i++) //spread walkers into pages
	{
		walkers.push_back(quotient); 
	}
 
	for (int i=0; i<remainder; i++) //consider the remainder.
	{
		walkers[i]++;
	}

	for (int k = 0; k<S; k++) //for loop for simulations. 
	{	
		vector<int> initial_state; //to account for double counting. 
		for (int z=0; z<walkers.size(); z++)
		{
			initial_state.push_back(walkers[z]);
		}

		for (int i=0; i<pages.size(); i++) //for each page...
		{
			vector<int> out_links = pages[i].getLinks(); //read in out links

			for (int j=0; j<initial_state[i]; j++) //run thru each walker 
			{
				int randomizer = rand()%(out_links.size()); //get a random ID
				
				walkers[i]--; //subtract current page

				walkers[out_links[randomizer]]++; //add to another page
			}
		}
	}

	for (int i=0; i<walkers.size();i++) //add up and find r. 
	{
		double r = (double)walkers[i]/N;
		pages[i].setRank(r); 
	}
}