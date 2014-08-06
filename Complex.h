#include <math.h>
#include <cstdio>
#include "GraphicsRGB.h"


class Complex {
public:
	double real, imag;
public:
	//
	// Constructors:
	Complex():
		real(0), imag(0) {}
	Complex(double real, double imag): // cartesian
		real(real), imag(imag) {}
	Complex(double length, double angle, bool conjugate): // polar
		real(length * cos(angle)),
		imag(length * sin(angle) * (conjugate? -1 : 1)) {}
	
	// Assignment:
	Complex operator=(double other) {
		real = other, imag = 0;
		return (*this);
	}
	Complex operator=(const Complex& other) {
		real = other.real, imag = other.imag;
		return (*this);
	}

	// Basic Arithmetic:
	Complex operator*(double other) const;
	Complex operator*(const Complex& other) const;
	Complex operator+(const Complex& other) const;

	// Exponentiation (by means of polar coordinates):
	Complex operator^(const Complex& power) const;
	Complex operator^(double power) const;
	double length() const;
	double angle() const;
	Complex logarithm() const;				
	Complex exponential() const;

	// Display:
	void print() {
		printf("%f + %fi\n", real, imag);
	}
	RGB color() {
		static const RGB offset = RGB(1, 1, 1)/3;
		static const RGB one = RGB(0.0, +1.0, -1.0)/sqrt(2.0) / sqrt(6.0);
		static const RGB two = RGB(1.0, -0.5, -0.5)/sqrt(1.5) / sqrt(6.0);
	
		double l = length();
		if(!l) { // in case it's 0
			return RGB(0, 0, 0);
		}
		else if(real*0 != 0 || imag*0 != 0) { // in case it's infinite or undefined
			return RGB(1, 1, 1)*192;
		}
		double maxed_l = atan(l/4.0) * 255.9 / (3.14159265358979/2);
		return (offset + one*(real/l) + two*(imag/l)) * maxed_l;
	}
};
