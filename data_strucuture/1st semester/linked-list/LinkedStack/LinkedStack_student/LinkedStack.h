#pragma once
#include "Node.h"

class LinkedStack {
	Node* top;
public:
	LinkedStack() { top = NULL; }
	~LinkedStack() { while (!isEmpty()) delete pop(); }

	bool isEmpty() {
		return top == NULL;
	}

	void push(Node* p) {
		if (isEmpty()) top = p; // 비어서 처음 들어온게 첫번째 노드 ( 헤드포인터가 가리키는 노드)
		else {
			p->setLink(top); // p-> link = top; ( link = p; ) 첫번째 노드의 주소를, p의 링크필드에 넣기
			top = p; // p를 첫번째 노드로! 
		}
	}
	Node* pop() {
		if (isEmpty()) return NULL; // 비어서 pop할 수 없음
		Node* p = top;
		top = top->getLink();
		return p;
	}

	Node* peek() {
		return top;
	}
	void display() {
		printf("[ Linked-Stack (student_list) ]\n");
		for (Node* p = top; p != NULL; p = p->getLink()) // 헤드포인터 ~ 마지막 노드까지
			p->display();
		printf("\n");
	}
}; 