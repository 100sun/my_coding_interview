#pragma once
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};
#define MAX_QUEUE_SIZE	100

class CircularQueue
{
	int	front;
	int	rear;
	int	data[MAX_QUEUE_SIZE];
public:
	CircularQueue() { front = rear = 0; }
	~CircularQueue() { }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(int val) {
		if (isFull()) {
			printf("  error: ť ��ȭ���� \n");
			system("pause");
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			printf("  Error: ť �������\n");
			system("wait");
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	int peek() {
		if (isEmpty()) {
			printf("  Error: ť �������\n");
			system("wait");
		}
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}

	void display() {
		printf("ť ���� : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
		printf("\n");
	}
};
