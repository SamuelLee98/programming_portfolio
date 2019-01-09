#include "page.h"

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

