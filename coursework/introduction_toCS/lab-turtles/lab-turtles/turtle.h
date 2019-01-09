#include "draw.h"

class Turtle 
{
	public:
		Turtle(double x0, double y0, double dir0);
		Turtle();
		void move(double dist);
		void turn(double deg);

		void setColor(Color c);
		void off();
		void on();
	private:
		double x1; //holds initial positions and dirm
		double y1;
		double dir1; //holds direction

		double x2; //holds the next position to where line is drawn
		double y2; 

		Color current_color; 
		bool vanish;
};