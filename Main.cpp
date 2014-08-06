#include "Mandelbrot.h"
#include <iostream>
using namespace std;
#include "GraphicsBitmap.h"


#define SIDE 512


void main() {
	// Test angle calculation:
	Complex Z;

	Z = Complex(1, 1);
	Z.print();
	cout << Z.angle() / 3.14159265358979 << endl; // should be +0.25
	Z = Complex(-1, 1);
	Z.print();
	cout << Z.angle() / 3.14159265358979 << endl; // should be +0.75
	Z = Complex(-1, -1);
	Z.print();
	cout << Z.angle() / 3.14159265358979 << endl; // should be -0.25
	Z = Complex(1, -1);
	Z.print();
	cout << Z.angle() / 3.14159265358979 << endl; // should be -0.75

	// Render a nice Mandelbrot bitmap:
	Bitmap I(SIDE, SIDE);
	for(int r = 0; r < SIDE; r++) {
		for(int c = 0; c < SIDE; c++) {
			Complex C(	c*(4.0/SIDE) - 2.0, // for 4x4 square
						r*(4.0/SIDE) - 2.0);// centered on origin
			int e = escape_time(C, &mandelbrot);
			I.paint_pixel(r, c, e);
		}
		if(r % 16 == 0) cout << '.';
	}
	I.write_to("C:\\Users\\Sam\\Documents\\Visual Studio 2012\\Projects\\Fractal\\Fractal\\M.bmp");

	// Pause before exiting:
	cout << "tada!" << endl; char l; cin >> l;
}
