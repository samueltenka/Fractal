#include <math.h>
#include <cstdio>


class Complex {
private:
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
	double length() const;
	double angle() const;
	Complex logarithm() const;				
	Complex exponential() const;

	// Printing:
	void print() {
		printf("%f + %fi\n", real, imag);
	}
};
