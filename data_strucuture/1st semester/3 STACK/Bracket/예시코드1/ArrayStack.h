#include <cstdio>
#include <cstdlib>

inline void error(char *message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 100; //스택의 최대 크기 설정
class ArrayStack
{
	int top;
	int data[MAX_STACK_SIZE];
	
	public:
		ArrayStack() {top = -1;}
		~ArrayStack(){}
		
		bool isEmpty() { 
			return top == -1;
		}
		bool isFull() {
			return top == MAX_STACK_SIZE-1;
		}
		
		void push (int e) { //요소를 top에 삽입  
			if(isFull()) 
				error("스택 공백 에러");
				data[++top] = e; 
		}
		
		int pop () { //삭제하고 반환 
			if( isEmpty()) 
				error("스택 공백 에러");
				return data[top--];
		}
		
		int peek () { //삭제x 요소 반환 
			if( isEmpty())
				error("스택 공백 에러");
				return data[top];
		}
		
		void display() {
			printf("[스택 항목의 수 = %2d] ==> ", top+1);			
			for (int i = 0; i<=top; i++) {
				printf("<%2c>", data[i]);
			}
			printf("\n");
		}
		
 } ;
