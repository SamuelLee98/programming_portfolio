#include <iostream>
#include "turtle.h"
#include "draw.h"
#include <cmath>
#include <cstring>

using namespace std;

Turtle::Turtle(double x0, double y0, double dir0) //constructor
{
	x1 = x0;
	y1 = y0;
	dir1 = dir0 * M_PI/180;
	current_color.red = 0;
	current_color.green = 0;
	current_color.blue = 0;
	vanish = false;

}

void Turtle::turn(double deg) 
{
	deg *= M_PI/180;
	dir1 = (dir1 + deg); //stores direction in radians
}

void Turtle::move(double dist) 
{
	

	if((current_color.red == 0) && (current_color.green==0) && (current_color.blue==0))
	{
		draw::setcolor(draw::BLACK);
	}

	else 
	{
		draw::setcolor(current_color); //sets color as the selected color
	}
 
	x2 = dist*cos(dir1) + x1;
	y2 = dist*sin(dir1) + y1;

	
	if (vanish == false)
	{
		draw::line(x1, y1, x2, y2); //draw
	}


	x1 = x2;
	y1 = y2;
}

void Turtle::setColor(Color c)
{
	current_color = c;

}

void Turtle::off()
{
	vanish = true;
}

void Turtle::on()
{
	vanish = false;
}