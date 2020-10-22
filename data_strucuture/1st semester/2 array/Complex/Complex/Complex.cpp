#include <stdio.h>    
#include <complex.h>
#include "Complex.h"

void Complex::read(char* msg) {
	printf(" %s", msg);
	scanf("%lf%lf", &real, &imag);
}

void Complex::print(char * msg)
{
	printf(" %s %4.2f + %4.2fi/n", msg, real, imag);
}

void Complex::add(Complex a, Complex b)
{
	real = a.real + b.real;
	imag = a.imag + b.imag;
}
