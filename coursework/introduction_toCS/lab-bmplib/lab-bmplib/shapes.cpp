#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {


	for (int i = 0; i < height; i++){ //two verical lines    	
	    
	  
	    if ((i+top < SIZE) && (i+top >= 0) && (left < SIZE) && (left >= 0)){

	    	image[i+top][left] = 0;
	    }

	    if ((i+top < SIZE) && (i+top >= 0) && (left + width -1 < SIZE) && (left + width -1 >= 0)){ 
	    	image[i+top][left+width-1] = 0;

	    }

}

	for (int i = 0; i < width; i++){ // two horizontal lines

		if ((i+left < SIZE) && (i + left >= 0) && (top < SIZE) && (top >= 0)){
	   		image[top][i+left] = 0;
	    }

	    if ((i+left < SIZE) && (i + left >= 0)&& (top + height -1 < SIZE) && (top + height -1 >= 0)) {
	    	image [top+height-1][i+left] = 0;
	    }

	}
}

void draw_ellipse(int cy, int cx, int height, int width) {

	for (double theta = 0; theta < 6.28; theta += 0.01){

		double row = sin(theta)*height/2;
		double column = cos(theta)*width/2;
		row += cy;
		column += cx;

		if (((int)row < 256) && ((int)row >= 0) && ((int)column < 256) && ((int)column >= 0)){

			image[(int)row][(int)column] = 0;
		}
	}

}int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
  
   //Main program loop here
  int choice;
  bool user_chose_2 = false;

   while (user_chose_2 == false) {

	   	int p1, p2, d1, d2;

	   	cout << "To draw a rectangle, enter: 0 top left height width" << endl;
	   	cout << "To draw and ellipse: 1 cy cx height width " << endl;
	   	cout << "To save your drawing as output.bmp and quit, enter: 2" << endl;

	   	cin >> choice;

	   	if (choice == 2){
	   		break;
	   	}

	   	cin >> p1 >> p2 >> d1 >> d2;

	   if (choice == 0){
	   		draw_rectangle(p1, p2, d1, d2);
	   	}

	   	else if (choice == 1) {
	   		draw_ellipse(p1, p2, d1, d2);
	   	}
   }

   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}


