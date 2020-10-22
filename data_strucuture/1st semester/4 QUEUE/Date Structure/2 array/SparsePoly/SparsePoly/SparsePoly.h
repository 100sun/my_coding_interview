#pragma once
#include <cstdio>
#define MAX_TERMS 10

struct Term { // �� �� ǥ���ϴ� ����ü
	int expon; // ���� ����
	float coeff; // ���� ���
};

class SparsePoly {
	int nTerms; // ����� 0�� �ƴ� ���� ����
	Term term[MAX_TERMS]; // ����� 0�� �ƴ� ���� �迭
public:
	SparsePoly();
	void read();
	void add(SparsePoly a, SparsePoly b);
	void display(const char *str = "SPoly = ");
};

