#include "Polynomial.h"

int main() {
	Polynomial a, b, c, d, e;

	a.read(); // keyboard enter
	b.read(); // keyboard enter
	printf("\n");

	a.display("A = ");
	a.display2("display2) A = ");
	b.display("B = ");
	b.display2("display2) B = ");
	printf("\n");

	c.add(a, b); // c = a+b
	c.display("A+B = ");
	c.trim();
	c.display2("trim) A+B = ");
	
	d.sub(a, b);
	d.display("A-B = ");
	d.trim();
	d.display2("trim) A-B = ");
	
	e.mult(a, b);
	e.display("A*B = ");
	e.trim();
	e.display2("trim) A*B = ");

	return 0;
}