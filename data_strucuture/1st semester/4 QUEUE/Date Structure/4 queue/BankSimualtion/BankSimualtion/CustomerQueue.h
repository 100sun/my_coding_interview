#pragma once
#include <cstdio>
#include <cstdlib>
#include "Customer.h"
#define MAX_QUEUE_SIZE 100

inline void error(const char* str) {
	printf("%s\n", str); exit(1);
}

class CustomerQueue {
	int front;
	int rear;
	Customer data[MAX_QUEUE_SIZE];
public:
	CustomerQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(Customer& val) {
		if (isFull()) error("error:고객큐가 포화상태이므로 새고객 push 불가");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Customer& dequeue() {
		if (isEmpty()) error("error:고객큐가 공백상태이므로 기존고객 pop 불가");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	Customer& peek() {
		if (isEmpty()) error("error:고객큐가 공백상태이므로 기존고객 pop 불가");
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	void display() {
		printf("Queue display : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		if (isEmpty())printf(" ");
		else
			for (int i = front + 1; i <= maxi; i++)
			printf("%5d", data[i%MAX_QUEUE_SIZE].id);
		printf("\n");
	}
};