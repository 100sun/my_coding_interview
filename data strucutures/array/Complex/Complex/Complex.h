#pragma once
#include <stdio.h>    
#include <complex.h>
#include "Complex.h"
class Complex {
	double real; // �Ǽ�
	double imag; // ���
public:
	void set(double r, double i) {
		real = r;
		imag = i;
	}
	void read(char* msg = " Complex = ");
	void print(char* msg = " Complex = ");
	void add(Complex a, Complex b);
};
