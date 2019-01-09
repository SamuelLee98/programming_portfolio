#include "turtle.h"
#include "draw.h"

int main()
{
	draw::setpenwidth(10); // thick lines
	draw::setrange(-100, 100);
	//draw::show(40);

	Turtle eyer(25,25,0);
	Turtle eyel(-25,25,0);
	Turtle nose(0,17,0);
	Turtle mouth(0,-50,0);
	

	eyer.setColor(draw::BLUE);
	eyel.setColor(draw::MAGENTA);
	nose.setColor(draw::RED);
	mouth.setColor(draw::MINT);

	for (int i=0; i<100; i++) 
	{
      eyer.move(100.0/100); // draw a shape with perimeter 300 steps
      eyer.turn(360.0/100); // do a full turn in N parts
      eyel.move(100.0/100);
      eyel.turn(360.0/100);

      if ((i < 20) || (i > 80))
      	{
	      mouth.on();
  		}

  		else 
  		{
  			mouth.off();
  		}

  		mouth.move(300/100); // draw a shape with perimeter 300 steps
	    mouth.turn(360.0/100); // do a full turn in N parts
   	}

   	nose.turn(270);
   	nose.move(17);

   	for (int i=0; i<100; i++) 
	{
      nose.move(50.0/100); // draw a shape with perimeter 300 steps
      nose.turn(360.0/100); // do a full turn in N parts
	}


   	return 0;
}
