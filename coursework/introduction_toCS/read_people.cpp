#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream ifile("data.txt");

	int num_records;
	string line;
	getline(ifile,line);
	stringstream sr(line);
	sr >> num_records;
	cout << "This file contains" << num_records << " records." << endl;
	vector<Person> people; 

	for (int i=0; i<num_records; i++)
	{
		string first, last;
		int year;
		vector<string> colors;
		getline(ifile, line);

		for (int k=0; k<4; k++)
		{
			getline(ifile,line);
			stringstream ss (line);
			if (k==0)
			{
				ss >> first >> last;
			}

			else if(k==1)
			{
				ss >> year;
			}
			else if(k==2)
			{
				string color;
				while(ss >> color)
				{
					colors.push_back(color);
				}
			}
			else
			{
				int zip;
				while(ss >> zip)
				{
					zips.push_back(zip);
				}
			}
		}
		Person p(last, first, year, colors, zips);
		people.push_back(p);
	}

	people[0].Print();
	people[1].Print();
	return 0;
}
