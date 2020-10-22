#include "Polynomial.h"

int main(){
	
	Polynomial a,b,c,d,e;

	a.read();
	b.read();
	c.add(a,b);
	d.sub(a,b);
	d.trim();	
	e.mult(a,b);
	a.display("A = ");
	b.display("B = ");
	c.display("A+B = ");
	d.display("A-B = ");
	e.display("A*B = ");
}
