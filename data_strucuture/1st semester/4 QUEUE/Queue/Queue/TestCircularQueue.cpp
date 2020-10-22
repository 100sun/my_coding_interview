#include "CircularQueue.h"

int main() {
	CircularQueue que;
	for (int i = 1; i < 4; i++) {
		que.enqueue(i);
		que.display();
	}
	printf("\n");
	que.dequeue(); que.display();
	for (int i = 4; i < 8; i++) {
		que.enqueue(i);
		que.display();
	}
	que.dequeue(); que.display();
	return 0;
}