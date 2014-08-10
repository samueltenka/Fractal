#include "Complex.h"
#include <random>
inline bool rand_choice() {
	return rand()%2 == 1;
}
#include "GraphicsRGB.h"


#define POWER 4


int color(int num_steps) {
	if(num_steps >= 0) {
		return num_steps>255 ? 255 : num_steps;
	}
	return 255; // got -1, meaning never escaped. => white.
}


Complex mandelbrot(Complex z, Complex c) {
	return (z^POWER) + c;
}
Complex alech(Complex z, Complex c) {
	return (z^POWER) + (c^z);
}
//Complex julia(Complex z, Complex c) {
//	return (z^POWER) + z;
//}
//Complex julia(Complex z, Complex c) {
//	return (z + c*(-1))^(1.0/POWER) * // inverse of z^2+c
//			(rand_choice()? -1 : 1); // randomly choose between + and - roots.
//}
Complex newton(Complex z, Complex c) {
	return (z + (z^(-1))*c) * (1.0/2);
}


int escape_time(Complex c, Complex (*map)(Complex, Complex), Complex initial, double threshold, int max_steps) {
	Complex z = initial;

	for(int steps = 0; steps < max_steps; steps++) {
		if(z.length() > threshold) {
			return steps;
		}
		z = (*map)(z, c);
	}
	return -1;
}
RGB escape_color(Complex c, Complex (*map)(Complex, Complex)) {
	int v = color(escape_time(c, map, Complex(0, 0), 100.0, 256));
	return RGB(v, v, v);
}


Complex limit(Complex c, Complex (*map)(Complex, Complex), Complex initial, double threshold, int max_steps) {
	Complex z = initial;
	Complex sum(0, 0); int steps = 0;
	while(steps < max_steps && z.length() <= threshold) {
		sum = sum + z; steps++;
		z = (*map)(z, c);
	}
	return sum * (1.0/steps);
}
RGB limit_color(Complex c, Complex (*map)(Complex, Complex)) {
	return limit(c, map, Complex(0, 0), 1000.0, 256).color();
}

