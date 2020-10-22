#pragma once
#include<stdbool.h>
#include<stdio.h>
#define MAX_DEQUE_SIZE 10

static int deque[MAX_DEQUE_SIZE];
static int front = -1;
static int rear = -1;

bool isEmpty() {
	return front == rear;
}
bool isFull() {
	return rear - front == MAX_DEQUE_SIZE;
}
bool insertLast(int data) {
	int i;
	if (rear == MAX_DEQUE_SIZE - 1) {
		if (front!= -1) {
			for (i = 0; i < MAX_DEQUE_SIZE - front - 1; i++) 
				deque[i] = deque[front + i + 1];
			front = -1;
			rear = rear - MAX_DEQUE_SIZE + i;
			deque[++rear] = data;
			return true; 

		}

		else return false;

	}

	else {

		deque[++rear] = data;

		return true;

	}

}



int deque_pop_back() {

	if (deque_empty()) return NULL;

	return deque[rear--];

}



bool deque_push_front(int data) {

	int i;



	if (front == -1) {

		if (rear != MAX_DEQUE_SIZE - 1) {

			for (i = rear; i >= 0; i--) deque[i + 1] = deque[i];

			deque[0] = data;

			rear++;

			return true;

		}

		else return false;

	}

	else {

		deque[front--] = data;

		return true;

	}

}



int deque_pop_front() {

	if (deque_empty()) return NULL;

	return deque[++front];

}



int deque_begin() {

	if (deque_empty()) return NULL;

	return deque[front + 1];

}



int deque_end() {

	if (deque_empty()) return NULL;

	return deque[rear];

}



#endif

[출처] 06 - 자료구조: 덱(Deque) | 작성자 저스트쿠카로

