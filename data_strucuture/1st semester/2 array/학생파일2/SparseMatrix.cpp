#include <cstdio>
#include <iostream>
#define MAX_TERMS 100
using namespace std;

struct Term {
	int expo;
	float coef;
};


class SparsePoly {
	int nTerms; 
	Term term[MAX_TERMS];

public:
	SparsePoly() {

	}
	
	void reed() {
		printf("항의 계수가 0이 아닌 개수 : ");
		scanf_s("%d", &nTerms);

		for (int i = 0; i < nTerms; i++) {
			printf("%d번째 항의 계수와 차수를 입력하시오.\n", i+1);
			Term temp;
			scanf_s("%f %d", &temp.coef, &temp.expo);
			term[i] = temp;
		}
	}

	void display( const char * str = " SPoly = ") {
		printf("\t%s", str);
		printf("%5.1f x^%d ", term[0].coef, term[0].expo);
		for (int i = 1; i < nTerms; i++)
			printf("+ %5.1f x^%d ", term[i].coef, term[i].expo);
		printf("\n");
	}
	
	void add(SparsePoly a, SparsePoly b) {
		*this = a; int count = 0;
		for (int j = 0; j < b.nTerms; j++) {
			for (int i = 0; i < nTerms; i++) {
				if (term[i].expo < b.term[j].expo) {
					for (int k = nTerms - 1; k >= i; k--)
						term[k + 1] = term[k];
					term[i] = b.term[j];
					nTerms++;
					count++;
					break;
				}
				else if (term[i].expo == b.term[j].expo) {
					term[i].coef += b.term[j].coef;
					count++;
					break;
				}
				if (count == 0) {
					term[nTerms] = b.term[b.nTerms];
					count++;
				}
			}
		}		
	}
};

int main() {

	SparsePoly a, b, c;

	a.reed();
	b.reed();
	a.display(" A = ");
	b.display(" B = ");
	c.add(a,b);
	c.display(" A + B = ");

	return 0;
}