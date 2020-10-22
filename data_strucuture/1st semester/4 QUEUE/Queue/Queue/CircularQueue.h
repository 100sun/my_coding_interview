#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 6

inline void error(const char* str) { printf("%s\n", str); exit(1); }

class CircularQueue {
protected:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(int val) {
		if (isFull()) error("error : 큐가 포화상태이므로 push하지 못합니다\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {
		if (isEmpty()) error("error : 큐가 공백상태이므로 pop하지 못합니다");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (isEmpty()) error("error : 큐가 공백상태이므로 pop하지 못합니다");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	
	void display() {
		printf("큐 내용 : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
		printf("\nfront: %d    rear : %d", front, rear);
		printf("\n");
	}
};