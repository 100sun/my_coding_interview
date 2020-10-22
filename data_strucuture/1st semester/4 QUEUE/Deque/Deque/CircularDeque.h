#pragma once
#include "CircularQueue.h"

class CircularDeque :public CircularQueue {
public:
	CircularDeque() {}
	void addFront(int val) {
		if (isFull()) error("error:��ȭ���� add front �Ұ�");
		data[front] = val;
		front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
	int deleteFront() { return dequeue(); }
	int getFront() { return peek(); }

	void addRear(int val) { enqueue(val); }
	int deleteRear() {
		if (isEmpty()) error("error:������� deleter rear �Ұ�");
		int ret = data[rear];
		rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return ret;
	}
	int getRear() {
		if (isEmpty()) error("error:������� deleter rear �Ұ�");
		return data[rear];
	}

	void Ddisplay() {
		printf("\nť��� �������� ���� �����Դϴ�.\n");
		display();
	}
};
