#include "CircularDeque.h"

int main() {
	CircularDeque deq;
	printf("%d", (1 % 2));
	for (int i = 1; i < 10; i++) {
		if (i % 2) // true(1) -> Ȧ��
			deq.addFront(i);
		else // false(0) -> ¦��
			deq.addRear(i);
		deq.Ddisplay();
	}
	printf("========================================================");
	deq.deleteFront();
	deq.Ddisplay();
	deq.deleteRear();
	deq.Ddisplay();
	deq.deleteFront();
	deq.Ddisplay();
	return 0;
}