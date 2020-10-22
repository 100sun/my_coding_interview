#pragma once
#include <cstdio>
#define MAX_DEGREE 80

class Polynomial {
	int degree; // �ְ�����
	float coef[MAX_DEGREE]; // �� �׿� ���� ���
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