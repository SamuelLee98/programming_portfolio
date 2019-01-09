#include <iostream>
#inlcude <fstream>

using namespace std;

PA5: Pagerank
Topics Covered: String stream, file i/o, objected oriented programming, 
functions, headerfiles, vectors

***********************Topic: Object Orieted Programing*******************
Page header file. Class objects have a public and a private section. 

class Page { 
public:
  
private:
  int id;
  string url;
  double rank;
  vector<int> links;
};  

#include "page.h" //u need to include the header file. 
Page::Page(int i,const string &u) //constructor for Page object
{
	id = i; 
	url = u;
	rank = 0.0;
}

void Page::addLink(int id) //pushback outgoing links into vector
{
	links.push_back(id); 
}

Web::~Web()// destructor for classes
{

}

Topic: File i/O

ifstream ifile(filename); //opens stream.. 
ifile.fail(); //checks to see if the file opens

ifile >> numpages; //start to read things in.

- for loops become useful when the thing youre reading in has a regular format.

- dont forget to use ifile.fail() for everything you try to read in. 

- Need to make a variable for something to hold what your reading in. 


OUTPUT 
pages is a vector of pages... its initialzed as vector<Page> pages; 

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

	return true; //make sure u return something
}

****************Topic: Stringstreams*************************************

- often, string stream is used with get line. 
- when using get line, need to flush the newline character. 

	string spaceholder; //hold space to get to the next line
	getline(ifile, spaceholder); //flush the newline character

	string temp_ss; //read in outgoing links
	getline(ifile,temp_ss); //dont forget to check with ifile.fail()..

	stringstream ss(temp_ss); 
		
	int temp_links; //another tem variable to read in the terms.
		
		while(ss >> temp_links) //read in outgoing links for that page
		{
			single_page.addLink(temp_links); 
		}
**********************Vectors******************************************
useful vector member functions. 

initialzing and putting numbers in 

vector<type> name; 

name.push_back(contents); 

name.size(); //to get how many elements name has. 

PA4: Connected component labeling 
Main topics: Dynamic memory allocation for 2D arrays and 3D arrays, some basic
object oriented programming, making queues, BFS search, connected component labeling. 

1. Struct vs. Classes 
in a struct all the data members are public by default 
in a class the data members are pri=vate, unless specified. So trying to use dot notation 
wont work.

2. Dyanmic memory

Allocating and Deallocating a 2D array 

unsigned char** rand_color = new unsigned char*[num_segments-1]; 
   		//allocate dynamic 2D array

   for(int i=0; i<num_segments-1; i++) 
   {
   		rand_color[i] = new unsigned char[3]; //3 because of R G B components
   }

   for(int i=0; i<num_segments-1; i++) //deallocate array
   {
   		delete [] rand_color[i]; //delete  contents of array. 
   }

   delete [] rand_color;//delete the array itself

 3. Recursive BFS

 int component_labeling(unsigned char **binary_image,int **label,
	int height,int width) 
{

	int current_label = 1; //initialized to 1, so the first objec tthat is ecounterered will be labeled one. 
	Queue BFS(height*width); //set to max possible size of queue

	Location loc; //pixel pushed into queue

	Location element; //used for examination of pixel in BFS

	for (int i=0; i<height; i++) //run through entire image
	{
		for (int j=0; j<width; j++)
		{
			if (binary_image[i][j] == 1 && label[i][j] == 0) //if white
			//and unlabeled
			{
				label[i][j] = current_label; //label it

				loc.row = i; //initialize loc object
				loc.col = j;

				BFS.push(loc); // so that u can push into the queue for BFS
			

				while (!(BFS.is_empty())) //start BFS
				{
					element = BFS.pop(); //pop next an element out of the queue of locations and 
					//examine neighbors

					//if neighbor pixel is white and unlabeled....
					if ((element.row+1<height)&& //check the border pixels
						(binary_image[element.row+1][element.col] == 1)&& 
						(label[element.row+1][element.col] == 0)) //check bot
					{
						label[element.row+1][element.col] = current_label;
						//label the pixel
						Location south; 
						//create new location for the pixel
						south.row = element.row+1;
						south.col = element.col;

						BFS.push(south); //push into BFS queue
					}

					if ((element.row>0)&&
						(binary_image[element.row-1][element.col] == 1)&& 
						(label[element.row-1][element.col] == 0)) //check top
					{
						label[element.row-1][element.col] = current_label;

						Location north; 

						north.row = element.row-1;
						north.col = element.col;

						BFS.push(north);
					}

					if ((element.col+1<width)&&
						(binary_image[element.row][element.col+1] == 1)&& 
						(label[element.row][element.col+1] == 0)) //check right
					{
						label[element.row][element.col+1] = current_label;

						Location east; 

						east.row = element.row;
						east.col = element.col+1;

						BFS.push(east);
					}

					if ((element.col>0)&&
						(binary_image[element.row][element.col-1] == 1)&& 
						(label[element.row][element.col-1] == 0)) //check left
					{
						label[element.row][element.col-1] = current_label;

						Location west; 

						west.row = element.row;
						west.col = element.col-1;

						BFS.push(west);
					}
				}

				current_label++; //increment label for next object
			}
		}
	}

	return current_label; //return num of segments/objects detected
}
