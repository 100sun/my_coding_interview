#pragma once
#include <cstdio>
#define MAX_TERMS 10

struct Term { // 각 항 표현하는 구조체
	int expon; // 항의 지수
	float coeff; // 항의 계수
};

class SparsePoly {
	int nTerms; // 계수가 0이 아닌 항의 갯수
	Term term[MAX_TERMS]; // 계수가 0이 아닌 항의 배열
public:
	SparsePoly();
	void read();
	void add(SparsePoly a, SparsePoly b);
	void display(const char *str = "SPoly = ");
};

