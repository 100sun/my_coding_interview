#include "LinkedQueue.h"
#include <stdio.h>

int main() {
	LinkedQueue q;
	q.enqueue(new Node(2017, "정건우", "경영학과"));
	q.enqueue(new Node(2018, "백선혜", "컴퓨터공학과"));
	q.enqueue(new Node(2019, "정순영", "호텔경영학과"));
	q.enqueue(new Node(2020, "백선영", "심리학과"));
	q.display();

	delete q.dequeue();
	q.display();
	return 0;
}