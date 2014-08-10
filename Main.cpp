#include "Mandelbrot.h"
#include <iostream>
using namespace std;
#include "GraphicsBitmap.h"


// CRACK LOCATION:
// (2 * -(256.0-160.0)/256.0, 0)

// TAIL LOCATION:
// (2 * -(256.0-31.0)/256.0, 0)

#define PIXEL_SIDE 256
#define CMPLX_SIDE 3.0//4.0
#define CENTER_R -1.409
#define CENTER_I 0.0
struct coor {
	int r, c;
	bool is_in_bounds() {
		return (0 <= r && r < PIXEL_SIDE) &&
				(0 <= c && c < PIXEL_SIDE);
	}
};
coor to_pixel(Complex Z) {
	coor rtrn;
	rtrn.r = static_cast<int>((Z.imag - (CENTER_I-CMPLX_SIDE/2)) * (PIXEL_SIDE/CMPLX_SIDE));
	rtrn.c = static_cast<int>((Z.real - (CENTER_R-CMPLX_SIDE/2)) * (PIXEL_SIDE/CMPLX_SIDE));
	return rtrn;
}
Complex to_cmplx(int r, int c) {
	return Complex(CENTER_R + c*(CMPLX_SIDE/PIXEL_SIDE) - CMPLX_SIDE/2,   // centered on origin
					CENTER_I + r*(CMPLX_SIDE/PIXEL_SIDE) - CMPLX_SIDE/2); //
}

void main() {
	//// Render a nice Mandelbrot bitmap:
	//Bitmap I(PIXEL_SIDE, PIXEL_SIDE);
	//Complex C(-0.74543, 0.11301);
	//Complex Z(0, 0);
	//for(int i = 0; i < 512*512*64; i++) {
	//	Z = julia(Z, C);
	//	coor rc = to_pixel(Z);
	//	if(rc.is_in_bounds()) {
	//		I.paint_pixel(rc.r, rc.c, 255);
	//	}
	//	if(i%(512*512)==0) cout << '.';
	//}
	//I.write_to("C:\\Users\\Sam\\Documents\\Visual Studio 2012\\Projects\\Fractal\\Fractal\\J.bmp");

	//Bitmap I(PIXEL_SIDE, PIXEL_SIDE);
	//for(int r = 0; r < PIXEL_SIDE; r++) {
	//	for(int c = 0; c < PIXEL_SIDE; c++) {
	//		Complex C = to_cmplx(r, c);
	//		//int e = escape_time(C, &newton);
	//		I.paint_pixel(r, c, ((C^(-1)).exponential()).color());
	//	}
	//	if(r % 16 == 0) cout << '.';
	//}
	//I.write_to("C:\\Users\\Sam\\Documents\\Visual Studio 2012\\Projects\\Fractal\\Fractal\\JL.bmp");

	Bitmap I(PIXEL_SIDE, PIXEL_SIDE);
	for(int r = 0; r < PIXEL_SIDE; r++) {
		for(int c = 0; c < PIXEL_SIDE; c++) {
			Complex C = to_cmplx(r, c);
			RGB X = limit_color(C, &alech);
			I.paint_pixel(r, c, X);
		}
		if(r % 16 == 0) cout << '.';
	}
	I.write_to("C:\\Users\\Sam\\Documents\\Visual Studio 2012\\Projects\\Fractal\\Fractal\\_out\\Mz_.bmp");

	// Pause before exiting:
	cout << "tada!" << endl; char l; cin >> l;
}
