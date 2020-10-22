#pragma once
#include <cstdio>
#include <cstdlib>

// error msg + quit
inline void error(const char *message) {
	printf("%s\n", message);
	exit(1); 
}

const int MAX_STACK_SIZE = 20;
class ArrayStack {
	int top; // element num
	int data[MAX_STACK_SIZE]; // element array
public:
	ArrayStack() {top = -1;} // defualt value
	~ArrayStack(){}
	bool isEmpty() { return top == -1; } 
	bool isFull() { return top == MAX_STACK_SIZE - 1; } // - defualt value

	void push(int e) { // element to top
		if (isFull()) error("Stack Full Error");
		data[++top] = e; // top ++ first and push
	}

	int pop() { // delete top and return
		if (isEmpty()) error("Stack Blank Error");
		return data[top--];  // return first and pop
	}	

	int peek() { // just return top
		if (isEmpty()) error("Stack Blank Error");
		return data[top];  // just return
	}

	void display() {
		printf("[스택 항목의 수 = %2d] ==> ", top + 1); 
		for (int i = 0; i <= top; i++)
			printf("<%2d>",data[i]);
		printf("\n");
	}

};
