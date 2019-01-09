#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {

	for (int i = 0; i < height; i++){ //two verical lines
	        	image[i+top][left] = 0;
	        	image[i+top][left+width-1] = 0;
	     	}

	for (int i = 0; i < width; i++){ // two horizontal lines
	        	image [top][i+left] = 0;
	        	image [top+height-1][i+left] = 0;
	     	}

   	//if (top + height <= 256 || left + width <= 256) { //height and width w/ in bounds.
 
	//    	if (left + width <= 256) { //if its narrow

	    	// for (int i = 0; i < height; i++){ //two verical lines
	     //    	image[i+top][left] = 0;
	     //    	image[i+top][left+width-1] = 0;
	     // 	}
	//      }

	//     if (top + height <= 256) { //if its short

	    	// for (int i = 0; i < width; i++){ // two horizontal lines
	     //    	image [top][i+left] = 0;
	     //    	image [top+height-1][i+left] = 0;
	     // 	}
	//     }
	// //}


 //   // else if (top + height > 256 || left + width > 256){ //height and width are too large

	//     if (left + width > 256)	{ //if its wide

	//     	for (int i = 0; i < 255; i++){ // one vertical line
	//     		image[i+top][left] = 0;
	//     	}
	//     }

	//     if (top + height > 256) { //if its tall

	//     	for (int i = 0; i < 255; i++){ // one horizontal line 
	//     		image [top][i+left] = 0;
	//     		//image[i+top][left+width-1] = 0;
	//     	}
	//     }
	 //}
}

 //    else if (top + height > 256 && left + width <= 256){ //height is too big, width is fine

 //    	for (int i = 0; i < 255; i++){
 //    		image[i+top][left] = 0;
 //    		image[i+top][left+width-1] = 0;
 //    	}

 //    	for (int i = 0; i < width; i++){ 
 //        	image [top][i+left] = 0;
	// 	}

	// }

	// else if (top + height <= 256 && left + width > 256){ //width is too big, height is fine

 //    	for (int i = 0; i < 255; i++){
 //    		image[i+top][left] = 0;

 //    	}

 //    	for (int i = 0; i < width; i++){ 
 //        	image [top][i+left] = 0;
 //        	image[i+top][left+width-1] = 0;

	// 	}
	// }

// METHOD 2
 
    // 	for (int i = 0; i < height; i++){ //verical lines
        	
    //     	if (left + width < 256){
				// image[i+top][left] = 0;
    //     		image[i+top][left+width-1] = 0;
    //     	}

    //     	else if (left + width >= 256){
    //     		image[i+top][left] = 0;
    //     	}
        	
    //  	}

    // 	for (int i = 0; i < width; i++){ // horizontal lines
    //     	if (top + height < 256){
    //     		image [top][i+left] = 0;
    //     		image [top+height-1][i+left] = 0;
    //     	}

    //     	else if (top + height >= 256){
    //     		image [top][i+left] = 0;
    //     	}
    //  	}
//}


// Fill in this function:

void draw_ellipse(int cy, int cx, int height, int width) {

	for (double theta = 0; theta < 6.28; theta += 0.01){

		double row = sin(theta)*height/2;
		double column = cos(theta)*width/2;
		row += cy;
		column += cx;
		//int radius = sqrt(height*height + width*width)

		//if (row + radius <= 256 && column +  )

		image[(int)row][(int)column] = 0;
	}

}



int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
  
   // Main program loop here
   int choice;
   bool user_chose_2 = false;

   while (user_chose_2 == false) {

	   	int p1, p2, d1, d2;

	   	cout << "To draw a rectangle, enter: 0 top left height width" << endl;
	   	cout << "To draw and ellipse: 1 cy cx height width " << endl;
	   	cout << "To save your drawing as output.bmp and quit, enter: 2" << endl;

	   	cin >> choice >> p1 >> p2 >> d1 >> d2;

	   	if (choice == 0){
	   		draw_rectangle(p1, p2, d1, d2);
	   	}

	   	else if (choice == 1) {
	   		draw_ellipse(p1, p2, d1, d2);
	   	}

	   	else if (choice == 2) {
	   		user_chose_2 = true;
	   	}
   }

   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
