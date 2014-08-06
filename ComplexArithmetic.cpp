#include "Complex.h"


Complex Complex::operator*(double other) const {
	return Complex(real*other, imag*other);
}
Complex Complex::operator*(const Complex& other) const {
	return Complex(real*other.real - imag*other.imag,
					imag*other.real + real*other.imag);
}
Complex Complex::operator+(const Complex& other) const {
	return Complex(real+other.real,
					imag+other.imag);
}
