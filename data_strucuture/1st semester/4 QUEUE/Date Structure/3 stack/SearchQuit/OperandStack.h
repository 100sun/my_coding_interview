#include <iostream>
#include <cstdlib>

const int MAX_STACK_SIZE = 20;
//���� ó�� �Լ�
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
		if (isFull()) error("������ȭ����\n");
		data[top++] = e;
	}
	double pop() {
		if (isEmpty()) printf("���� ���� ����");
		return data[top--];
	}
};
