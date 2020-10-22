#pragma once
#include "CircularQueue.h"

class CircularDeque :public CircularQueue {
public:
	CircularDeque() {}
	void addFront(int val) {
		if (isFull()) error("error:포화상태 add front 불가");
		data[front] = val;
		front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
	int deleteFront() { return dequeue(); }
	int getFront() { return peek(); }

	void addRear(int val) { enqueue(val); }
	int deleteRear() {
		if (isEmpty()) error("error:공백상태 deleter rear 불가");
		int ret = data[rear];
		rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return ret;
	}
	int getRear() {
		if (isEmpty()) error("error:공백상태 deleter rear 불가");
		return data[rear];
	}

	void Ddisplay() {
		printf("\n큐라고 나오지만 덱의 내용입니다.\n");
		display();
	}
};
