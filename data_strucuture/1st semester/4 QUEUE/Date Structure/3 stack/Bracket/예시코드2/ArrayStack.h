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
			error("스택 포화 에러");
			data[++top] = e; 
	}
	char pop(){
		if(isEmpty())
			error("스택 공백 에러");
		return data[top--];
	}
	char peek(){
		if(isEmpty())
			error("스택 공백 에러");
		return data[top];
	}
	void display(){
		printf("[스택 항목의 수 = %2d] ==> ",top+1);
		for (int i=0;i<=top;i++)
			cout << data[i] ;
		printf("\n");
	}
};
