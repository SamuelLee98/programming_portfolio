#include <iostream>
#include <string>
#include "delist.h"

using namespace std;

DElist::DElist() //constructor
{
	n = new DEItem; 
	n->val = NULL;
	n->prev = NULL;
	head = n; 
	tail = n; 
}

DElist::~DElist()
{

}