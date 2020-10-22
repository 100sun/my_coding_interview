#pragma once
#include "Node.h"

class LinkedQueue {
	Node* front, *rear;
public:
	LinkedQueue() { front = rear = NULL; }
	~LinkedQueue() { while (!isEmpty())delete dequeue(); }
	bool isEmpty() {
		return front == NULL;
	}

	void enqueue(Node* p) {
		if (isEmpty()) front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}

	}
	Node* dequeue() {
		if (isEmpty()) return NULL;
		Node* p = front;
		front = front->getLink();
		if (front == NULL) rear = NULL;
		return p;
	}

	Node* peek() {
		return front;
	}
	void display() {
		printf("[ Linked-Queue (student_list) ]\n");
		for (Node* p = front; p != NULL; p = p->getLink()) // 헤드포인터 ~ 마지막 노드까지
			p->display();
		printf("\n");
	}
};