#include "Complex.h"


//Complex mandelbrot(Complex z, Complex c)
//{
//	return z*z + c;
//}
//
//double value(Complex c, Complex (*map)(Complex, Complex))
//{
//	Complex z = c;
//	z = map(z, c);
//}


#include <iostream>
using namespace std;
void main() {
	Complex C(2, 1);
	Complex Z = C;
	for(int i = 0; i < 5; i++) {
		Z.print();
		Z = Z*C;
	}
	
	char l;
	cin >> l;
}
