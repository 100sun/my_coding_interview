#include <iostream>
#include <cstdlib>

const int MAX_STACK_SIZE = 20;
//오류 처리 함수
inline void error(char *msg) {
	printf("%s\n", msg);
	exit(1);
}

class OperandStack {
	double data[MAX_STACK_SIZE
};
int top;
public:
	OprandStack() { top == -1 };
	~OperandStack() {};
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE; }
	void push(double e) {
		if (isFull()) error("스택포화에러\n");
		data[top++] = e;
	}
	double pop() {
		if (isEmpty()) printf("스택 공백 에러");
		return data[top--];
	}
};
