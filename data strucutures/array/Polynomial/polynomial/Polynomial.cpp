#include "Polynomial.h"

Polynomial::Polynomial()
{
	degree = 0; // constructor : init MaxDgree
}

bool Polynomial::isZero()
{
	return degree == 0; // higest degree == 0 : true
}

void Polynomial::negate()
{
	for (int i = 0; i <= degree; i++)
		coef[i] = -coef[i]; // reverse sign
}

void Polynomial::read()
{
	printf("Enter a degree maximum of polynomial : ");
	scanf("%d", &degree);
	printf("Enter the coefficients for each term by space(total %d) : ", degree + 1);
	for (int i = 0; i <= degree; i++)
		scanf("%f", coef + i); // each term scan 
							   // array name = array first address : coef=&coef[0], coef+1=&coef[1]
}

void Polynomial::display(const char *str = " Poly = ") // original display from book
{
	printf("\t%s", str); // string parameter print
	for (int i = 0; i < degree; i++)
		printf("%5.1fx^%d", coef[i], degree - i); // reversely : higest degree = coef[0]
	printf("%4.1f\n", coef[degree]); // _ _ _ _ . _
}

void Polynomial::add(Polynomial a, Polynomial b)
{
	// c = a(7) + b(3) : c = a; c += b;
	if (a.degree > b.degree) {
		*this = a; // <copy> c = a; 
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] += b.coef[i]; // <add> c += b;
														//		a's	 go back by degree difference : start from 0 + 3 to 2 + 3
	}
	else { // a term < b term
		*this = b;
		for (int i = 0; i <= a.degree; i++)
			coef[i + (degree - a.degree)] += a.coef[i];
	}
	trim();
}

void Polynomial::sub(Polynomial a, Polynomial b)
{
	// c = a(7) - b(3) : c = a; c -= b;
	if (a.degree >= b.degree) {
		*this = a; // <copy> c = a; 
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] -= b.coef[i]; // <add> c -= b;
	}
	else { // a term < b term
		b.negate();
		*this = b;
		for (int i = 0; i <= a.degree; i++)
			coef[i + (degree - a.degree)] += a.coef[i];
	}
	trim();
}

void Polynomial::mult(Polynomial a, Polynomial b)
{
	// init c
	for (int i = 0; i <= a.degree + b.degree; i++)
		coef[i] = 0;
	// sum degree , multiply coeff
	this->degree = a.degree + b.degree;
	for (int i = 0; i <= a.degree; i++)
		for (int j = 0; j <= b.degree; j++)
			coef[i + j] += (a.coef[i] * b.coef[j]);
	trim();
}

void Polynomial::trim() // leading coeff != 0
{
	int count = 0;
	while (!coef[count]) // find degree whose coeff==0
		count++;
	if (count) { // degree == 0 : decrease and move to 
		int temp = degree;
		degree -= count; // decrease
		for (int i = 0; i <= temp - count; i++) // move
			coef[i] = coef[i + count];
	}
}

void Polynomial::display2(const char * str) // display() expand
{
	// display explanation
	printf("%s", str);
	// display variable terms
	for (int i = 0; i < degree; i++) {
		if (coef[i] != 0 || i == 0)
			// coeff == |1| : not display coeff
			if (coef[i] == 1)
				printf(" x^%d", degree - i);
			else if (coef[i] == -1)
				printf(" - x^%d", degree - i);
		// coeff == 0 : display nothing
			else if (coef[i] == 0)
				printf("");
			else
				printf("%5.1fx^%d", coef[i], degree - i);
		// connector ( skip max degree )
		if (coef[i + 1] > 0)
			printf("  + ");
	}
	// display constant temrs 
	if (degree == 0) //	if there is nothing remain values
		printf("0.0\n");
	else if (coef[degree]) // not 0 
		printf("%4.1f\n", coef[degree]);
	else
		printf("\n");
}