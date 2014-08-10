#include "Mandelbrot.h"
#include <iostream>
using namespace std;
#include "GraphicsBitmap.h"

/*
#define PIXEL_SIDE_H (1920*5)
#define PIXEL_SIDE_W (1080*5)

const double LEFT = -2.7;
const double RIGHT = 0.8;
const double LOWER = -3.11111111111;
const double UPPER = 3.11111111111;

const double HEIGHT = (UPPER-LOWER);
const double WIDTH = (RIGHT-LEFT);
const double CENTER_R = (LOWER + HEIGHT/2);
const double CENTER_I = (LEFT + WIDTH/2);
*/

#define PIXEL_SIDE_H 256
#define PIXEL_SIDE_W 256

const double LEFT = -2;
const double RIGHT = +2;
const double LOWER = -2;
const double UPPER = 2;

const double HEIGHT = (UPPER-LOWER);
const double WIDTH = (RIGHT-LEFT);
const double CENTER_R = (LOWER + HEIGHT/2);
const double CENTER_I = (LEFT + WIDTH/2);


struct coor {
	int r, c;
	bool is_in_bounds() {
		return (0 <= r && r < PIXEL_SIDE_H) &&
				(0 <= c && c < PIXEL_SIDE_W);
	}
};
//coor to_pixel(Complex Z) {
//	coor rtrn;
//	rtrn.r = static_cast<int>((Z.imag - LOWER) * (PIXEL_SIDE_H/HEIGHT));
//	rtrn.c = static_cast<int>((Z.real - LEFT) * (PIXEL_SIDE_W/WIDTH));
//	return rtrn;
//}
Complex to_cmplx(int r, int c) {
	return Complex(LEFT + c*(WIDTH/PIXEL_SIDE_W),
					LOWER + r*(HEIGHT/PIXEL_SIDE_H));
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

	Bitmap I(PIXEL_SIDE_H, PIXEL_SIDE_W);
	for(int r = 0; r < PIXEL_SIDE_H; r++) {
		for(int c = 0; c < PIXEL_SIDE_W; c++) {
			Complex C = to_cmplx(r, c);
			RGB X = limit_color(C, &mandelbrot);
			I.paint_pixel(r, c, X);
		}
		if(r % 16 == 0) cout << '.';
	}
	I.write_to("C:\\Users\\Sam\\Documents\\Visual Studio 2012\\Projects\\Fractal\\Fractal\\_out\\Mz_.bmp");

	// Pause before exiting:
	cout << "tada!" << endl; char l; cin >> l;
}
