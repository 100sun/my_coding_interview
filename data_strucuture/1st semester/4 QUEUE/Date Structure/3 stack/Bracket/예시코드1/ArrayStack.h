#include <cstdio>
#include <cstdlib>

inline void error(char *message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 100; //������ �ִ� ũ�� ����
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
		
		void push (int e) { //��Ҹ� top�� ����  
			if(isFull()) 
				error("���� ���� ����");
				data[++top] = e; 
		}
		
		int pop () { //�����ϰ� ��ȯ 
			if( isEmpty()) 
				error("���� ���� ����");
				return data[top--];
		}
		
		int peek () { //����x ��� ��ȯ 
			if( isEmpty())
				error("���� ���� ����");
				return data[top];
		}
		
		void display() {
			printf("[���� �׸��� �� = %2d] ==> ", top+1);			
			for (int i = 0; i<=top; i++) {
				printf("<%2c>", data[i]);
			}
			printf("\n");
		}
		
 } ;
