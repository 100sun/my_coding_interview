#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_DEGREE 80

class Polynomial {
private:
	int degree;
	float coef[MAX_DEGREE];
public:
	Polynomial() { degree = 0; }

	void read() {
		printf("���׽��� �ְ� ������ �Է��Ͻÿ� : ");
		scanf_s("%d", &degree); //scanf ���ÿ� "This function or variable may be unsafe Consider using scnaf_s instead" ���� -> scanf_s�� ����.
		printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf_s("%f", coef + i);
	}


	void display(const char * str = " Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++) {
			if (coef[i] != 1 && coef[i] != 0 && coef[i] > 0)
				printf("%5.1f x^%d + ", coef[i], degree - i);
			else if (coef[i] == 1)
				printf("x^%d + ", degree - i);
			else if (coef[i] < 0)
				printf("(%5.1f) x^%d + ", coef[i], degree - i);
			}
		if (coef[degree] != 0)
			printf("%4.1f\n", coef[degree]);
		else
			printf("\n");
		}
	

	void add(Polynomial a, Polynomial b) {
		if (a.degree >= b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}

	void sub(Polynomial a, Polynomial b) {
		if (a.degree >= b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++) {
				coef[i + (degree - b.degree)] -= b.coef[i];
			}
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] -= a.coef[i];
		}
	}

	void mult(Polynomial a, Polynomial b) {
		this->degree = a.degree + b.degree;
		for (int i = 0; i <= this->degree; i++)
			this->coef[i] = 0; // this�� coef�� �ʱ�ȭ
		for (int i = 0; i <= a.degree; i++) {
			for (int j = 0; j <= b.degree; j++)
				this->coef[i + j] += (a.coef[i] * b.coef[j]);
		}
	}

	void trim() {
		int zeroCount = 0;
		while (!coef[zeroCount])
			zeroCount++;
		if (zeroCount != 0) {
			degree -= zeroCount;
			for (int i = 0; i <= degree; i++)
				coef[i] = coef[i + zeroCount];
		}
	}

	bool isZero() { return degree == 0; }

	void negate() {
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}
};

int main() {

	Polynomial a, b, c;
	a.read();
	b.read();
	a.display("A = ");
	b.display("B = ");
	cout << endl;

	c.add(a, b);
	c.display("A+B = ");
	cout << endl;

	c.sub(a, b);
	c.trim();
	c.display("A-B = ");
	cout << endl;

	c.mult(a, b);
	c.display("A*B = ");

	return 0;
}