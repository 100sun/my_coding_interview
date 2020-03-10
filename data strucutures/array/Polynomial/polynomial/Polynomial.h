#pragma once
#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {
	int degree; // 최고차수
	float coef[MAX_DEGREE]; // 각 항에 대한 계수
public:
	Polynomial();
	bool isZero();
	void negate();
	void read();
	void display(const char * str);
	void add(Polynomial a, Polynomial b);
	void sub(Polynomial a, Polynomial b);
	void mult(Polynomial a, Polynomial b);
	void trim();
	void display2(const char * str);
};