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
		if (isEmpty()) top = p; // �� ó�� ���°� ù��° ��� ( ��������Ͱ� ����Ű�� ���)
		else {
			p->setLink(top); // p-> link = top; ( link = p; ) ù��° ����� �ּҸ�, p�� ��ũ�ʵ忡 �ֱ�
			top = p; // p�� ù��° ����! 
		}
	}
	Node* pop() {
		if (isEmpty()) return NULL; // �� pop�� �� ����
		Node* p = top;
		top = top->getLink();
		return p;
	}

	Node* peek() {
		return top;
	}
	void display() {
		printf("[ Linked-Stack (student_list) ]\n");
		for (Node* p = top; p != NULL; p = p->getLink()) // ��������� ~ ������ ������
			p->display();
		printf("\n");
	}
}; 