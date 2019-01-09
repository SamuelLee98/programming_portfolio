
Section 10-Prelab
1. Padding design: 
Largest padded image size: 266 x 266 ; 
Upper left pixel indices: [N/2][N/2]; 
Lower right pixel [255 + N/2][255 + N/2].

2. N = 3; sigma = 2;


raw kernal 

0.7788  0.8825 0.7788
0.8825     1   0.8825
0.7788  0.8825 0.7788

normalized kernal

0.1019  0.1154  0.1019
0.1154  0.1308  0.1154
0.1019  0.1154  0.1019

 If you use the raw kernals, the output image will be brighter because the 
 values in the kernal are larger than if we used the normalized values. So
 when we convolve and add we get higher values for the output pixels. 

Section 13-Experimentation

1. Increasing the sigma and N values (individually) the 
image becomes much blurier. When decreasing them (individually), the images
become less blurry. Increasing sigma makes a change to the image by making 
each individual pixel blurry, while increasing N affects a larger area by 
increasing the values of the kernal

2. It appears to highlight the areas in the image with sudden changes in 
color/value by making it white, unhighlighting areas that are relatively 
static in terms of change of color by making it black. 

3. If they were inverse operations they would have the same number of 
overall variables. The unsharp fitler has an extra variable alpha that
gaussian doesn have. Because the variables in each operation is different
they are not inverses of each other so getting an "unsharped-image" and
putting it into guassian (and vice versa) won't un-do each other. 


Section 15-Read me
1. Number of calculations (G) done in convolve
G(N) = 256*256*3*N^2; 

Num of pixels in image multiplyed by num of planes multiplied by 
num of pixels in the kernal. 

Its growth (f(x)) is represented using big O notation
f(x) = O(N^2)


