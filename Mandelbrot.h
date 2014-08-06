#include "Complex.h"


Complex mandelbrot(Complex z, Complex c) {
	Complex y = z*z*z;
	//Complex x = y*y*y;
	return y*y*z + c;
}

int escape_time(Complex c, Complex (*map)(Complex, Complex), Complex initial, double threshold, int max_steps) {
	Complex z = initial;

	for(int steps = 0; steps < max_steps; steps++) {
		if(z.length() > threshold) {
			return steps;
		}
		z = map(z, c);
	}
	return -1;
}
int escape_time(Complex c, Complex (*map)(Complex, Complex)) {
	return escape_time(c, map, Complex(0, 0), 100.0, 256);
}

int color(int num_steps) {
	if(num_steps >= 0) {
		return num_steps > 255 ? 255 : num_steps;
	}
	return 0; // got -1, meaning never escaped. => black.
}
