#include <time.h>
#include "BankSimulator.h"

int main() {
	srand((unsigned int)time(NULL));

	BankSimulator sim;
	sim.read();
	sim.run();
	sim.print();

	return 0;
}