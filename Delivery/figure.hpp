

void DrawFigure(A01 *A) {
/**************
 Function A->Plot(float x1, float y1, float r, float g, float b)

 draws a single point at (x1,y1), colored with the (r,g,b) specified color.
 The point is addressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 

 Function A->Line(float x1, float y1, float x2, float y2, float r, float g, float b)

 draws a segment from point (x1,y1) to point (x2, y2), colored with the (r,g,b) specified color.
 Starting and ending points are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]),
 following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 

 Function A->Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 Vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 
 
 Using functions Plot(...), Line(...) and Triangle(...) try to draw a simple picture.
 
 First remove the ten functions below (given only as an example), and replace them with your own.
 Please note that there is an upper limit in the number of primitives that can be used (89998). This number
 xs however huge, and it should not pose any limit, not even for the most complex drawings.

 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

	//house
	A->Triangle(0,-0.75,	-0.7,-0.2,		0.7,-0.2,   0.5, 0.2, 0);
	A->Triangle(-0.5,0.7,	-0.5,-0.2,		0.5,-0.2,   1,0.9,0);
	A->Triangle(-0.5,0.7,	0.5,0.7,		0.5,-0.2,   1,0.9,0);
	A->Line(-0.8,0.7,		0.8,0.7,		0,1,0);

	//flowers
	int i;
	for(i = 0; i < 31; i++){
		A->Line(-0.75+0.05*i,0.7,				-0.75+0.05*i,0.68-(i%2)*0.05,	0,1,0);
		A->Plot(-0.75+0.05*i,0.68-(i%2)*0.05, 									1,0,i%2);
	}
	
	//door
	A->Line(-0.1,0.3,	-0.1,0.7,	0,0,0);
	A->Line(0.1,0.3,	0.1,0.7,	0,0,0);
	A->Line(-0.1,0.3,	0.1,0.3,	0,0,0);
	A->Triangle(-0.1,0.3,	-0.1,0.7,	0.1,0.3,	1,0,0);
	A->Triangle(0.1,0.3,	0.1,0.7,	-0.1,0.7,	1,0,0);

	//windows
	A->Line(-0.4,0.2,	-0.2,0.2,		0,0,0);
	A->Line(-0.4,0,		-0.2,0,			0,0,0);
	A->Line(-0.4,0.2,	-0.4,0,			0,0,0);
	A->Line(-0.2,0.2,	-0.2,0,			0,0,0);

	A->Line(0.4,0.2,	0.2,0.2,		0,0,0);
	A->Line(0.4,0,		0.2,0,			0,0,0);
	A->Line(0.4,0.2,	0.4,0,			0,0,0);
	A->Line(0.2,0.2,	0.2,0,			0,0,0);	

	//A->Line(float x1, float y1, float x2, float y2, float r, float g, float b)

	
	
}
