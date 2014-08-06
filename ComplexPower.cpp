#include "Complex.h"


#define PI 3.14159265358979


//
// Main function:
Complex Complex::operator^(const Complex& power) const { // (power, not XOR)
	return (logarithm() * power).exponential();
}

//
// Helper functions:
double Complex::length() const { // will always >= 0.
	return sqrt(real*real + imag*imag);
}
double Complex::angle() const { // trigonometry, with all this sign-checking, just to avoid dividing by 0 and stuff :'(
	//           Im
	//            | pi/2      
	//            |             
	//            |             
	//  pi    "Q2"|"QI"      0 
	// -----------|------------> Re
	// -pi    "Q3"|"Q4"      0 
	//            |             
	//            |             
	//            |-pi/2      
	if(imag != 0) {
		if(real > 0)		return atan( imag/real);		// Q1, Q4.
		else if(imag > 0)	return atan( real/imag) + PI/2;	// Q2
									
		else				return atan(-real/imag) - PI/2;	// Q3
	}
	else {													// Real Axis.
		if(real > 0)  return 0;
		else          return PI; // -PI also works.
	}
}

// since exp(it) = unit of angle t:
Complex Complex::logarithm() const {
	return Complex(log(length()), angle()); // polar -> cartesian 
}											
Complex Complex::exponential() const {
	return Complex(exp(real), imag, false); // cartesian -> polar
}
