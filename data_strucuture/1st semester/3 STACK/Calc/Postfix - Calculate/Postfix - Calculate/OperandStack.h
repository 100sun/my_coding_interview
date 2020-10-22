#pragma once
#include <cstdio>
#include <cstdlib>

// error msg + quit
inline void error(const char *message) {
	printf("%s\n", message);
	exit(1); 
}

const int MAX_STACK_SIZE = 20;
class OperandStack {
	int top; // element num
	double data[MAX_STACK_SIZE]; // element array

public:
	OperandStack() {top = -1;} // defualt value
	bool isEmpty() { return top == -1; } 
	bool isFull() { return top == MAX_STACK_SIZE - 1; } // - defualt value

	void push(double e) { // element to top
		if (isFull()) error("Stack Full Error");
		data[++top] = e; // top ++ first and push
	}

	double pop() { // delete top and return
		if (isEmpty()) error("Stack Blank Error");
		return data[top--];  // return first and pop
	}	

	double peek() { // just return top
		if (isEmpty()) error("Stack Blank Error");
		return data[top];  // just return
	}

	void display() {
		printf("[���� �׸��� �� = %2d] ==> ", top + 1); 
		for (int i = 0; i <= top; i++)
			printf("<%5.2f>",data[i]);
		printf("\n");
	}

};
