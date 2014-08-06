#include "Mandelbrot.h"
#include <iostream>
using namespace std;
#include "GraphicsBitmap.h"


#define SIDE 512


void main() {
	// Render a nice Mandelbrot bitmap:
	//Bitmap I(SIDE, SIDE);
	//for(int r = 0; r < SIDE; r++) {
	//	for(int c = 0; c < SIDE; c++) {
	//		Complex C(	c*(4.0/SIDE) - 2.0, // for 4x4 square
	//					r*(4.0/SIDE) - 2.0);// centered on origin
	//		int e = escape_time(C, &mandelbrot);
	//		I.paint_pixel(r, c, e);
	//	}
	//}
	//I.write_to("C:\\Users\\Sam\\Documents\\Visual Studio 2012\\Projects\\Fractal\\Fractal\\M.bmp");

	Complex Z(0, 3.14159265358979);
	Z.exponential().print(); // should get -1

	Complex Y(3, 0);
	(Y^Y).print(); // should get 27

	Complex X(0, 1);
	(X^X).print();	// should get   i^i	= exp(i pi/2)^i
					//					= exp(ii pi/2) 
					//					= exp(-pi/2) = 0.207879...

	// Pause before exiting:
	cout << "tada!" << endl; char l; cin >> l;
}
