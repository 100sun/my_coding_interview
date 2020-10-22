#include <string>
#pragma once
#include "Node.h"

class LinkedList {
	Node org;
public:
	LinkedList() :org(0) {}
	~LinkedList() {
		while (!isEmpty()) delete remove(0);
	}
	bool isEmpty() {
		return getHead() == NULL;
	}
	Node* getHead() {
		return org.getLink();
	}
	void insert(int pos, Node* p) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) prev->insertNext(p);
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) return prev->removeNext();
		else {
			printf("is Empty");
			return NULL;
		}
	}
	void replace(int pos, Node* p) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(p);
		}
	}
	Node* getEntry(int pos) {
		Node* p = &org;
		for (int i = -1; i < pos; i++) {
			p = p->getLink();
			if (p == NULL) break;
		}
		return p;
	}
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}
	void display() {
		printf("< Linked-List (simply) > \n\t[size] = %d\n\t[content] : ", size());
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
	// (1) ����Ʈ�� ��� ������ ���� ���� ���� ����ϴ� �Լ� sum()�� �ۼ��ϼ���.
	int sum() {
		int sum = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			sum += p->getData();
		return sum;
	}
	// (2) ����Ʈ���� Ư���� ���� ���� ����� ������ ����ϴ� �Լ� count(int number)�� �ۼ��ϼ���.
	int count(int val) {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) count++;
		return count;
	}
	// (3) ����Ʈ�� ��� ����� ������ �ݴ�� �ٲٴ� ������ �����ϴ� �Լ� reverse()�� �ۼ��ϼ���.
	void reverse() {
		int pos = 0;
		for (int i = 0; i < size(); i++) {
			//			Node *p = remove(size() - 1); // ������ ������ ��带 pos��°�� push 
			insert(pos++, remove(size() - 1)); // positon ����
		}
		printf("\nResult of Reverse\n");
		display();
		printf("\t[sum] = %d\n", sum());
		printf("\t[count of %d] = %d\n", 100, count(100));
	}
	// (4) �ٸ� ����Ʈ ��ä that�� ��� ������ ���� ����Ʈ�� �����ϴ� ���� ������ �Լ��� �ۼ��ϼ���.
	void merge(LinkedList *that) {
		while (!that->isEmpty())
			insert(size(), (that->remove(0)));
		printf("\nResult of Merge\n");
		display();
		printf("\t[sum] = %d\n", sum());
		printf("\t[count of %d] = %d\n", 100, count(100));
	}
};

void increment(int& n) {
	n++;
}