#include "Complex.h"


Complex mandelbrot(Complex z, Complex c) {
	return z*z + c;
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

#include <iostream>
using namespace std;
void main() {
	// Test Mandelbrot escape calculations:
	for(int r = 0; r < 60; r++) {
		for(int c = 0; c < 60; c++) {
			Complex C(r/20.0 - 1.5, c/20.0 - 1.5);
			int e = escape_time(C, &mandelbrot);
			cout << (e==-1? '#' : ' ');
		}
		cout << endl;
	}

	// Pause before exiting:
	cout << "tada!" << endl; char l; cin >> l;
}
