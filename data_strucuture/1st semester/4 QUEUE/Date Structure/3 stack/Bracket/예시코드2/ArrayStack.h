#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

inline void error(char *message){
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;

class ArrayStack {
	int top;
	char data[MAX_STACK_SIZE];
	
public:
	ArrayStack(){
		top = -1;
	}
	~ArrayStack(){
	}
	bool isEmpty(){
		return top==-1;
	}
	bool isFull(){
		return top==MAX_STACK_SIZE-1;
	}
	void push(char e){
		if(isFull())
			error("���� ��ȭ ����");
			data[++top] = e; 
	}
	char pop(){
		if(isEmpty())
			error("���� ���� ����");
		return data[top--];
	}
	char peek(){
		if(isEmpty())
			error("���� ���� ����");
		return data[top];
	}
	void display(){
		printf("[���� �׸��� �� = %2d] ==> ",top+1);
		for (int i=0;i<=top;i++)
			cout << data[i] ;
		printf("\n");
	}
};
