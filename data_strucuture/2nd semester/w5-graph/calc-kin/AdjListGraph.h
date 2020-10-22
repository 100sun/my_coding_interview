#pragma once
#include "Node.h"
#define MAX_VTXS	256

class AdjListGraph  // ���� ����Ʈ Ŭ����
{
protected:
	int	size;	// ��� ����			
	int	vertices[MAX_VTXS];	// ��� ������ A,B,C,D	
	Node*	adj[MAX_VTXS];		// ���Ḯ��Ʈ ��� ����

public:
	AdjListGraph(void) : size(0) { }
	~AdjListGraph(void) { reset(); }

	void reset(void) { 	// adj ���Ḯ��Ʈ ����
		for (int i = 0; i < size; i++)
			if (adj != NULL) delete adj[i];
		size = 0;
	}
	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size >= MAX_VTXS); }
	int getVertex(int i) { return vertices[i]; }  // ith ��� ��ȯ,A,B.C��

	void insertVertex(char val) {	// ��� 1�� �߰� : char val
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;  // �ش� adj[] �ʱ�ȭ
		}
		else printf("Error: �׷��� ���� ���� �ʰ�\n");
	}

	void insertEdge(int u, int v) {
		if (adj[u] == NULL) adj[u] = new Node(v, NULL);  // insert (u,v)
		else {
			Node* p = adj[u];
			while (p->getLink() != NULL) p = p->getLink();
			p->setLink(new Node(v, NULL));
		}
		// insert (v,u)
		if (adj[v] == NULL) adj[v] = new Node(u, NULL); // ���Ḯ��Ʈ�� ��尡 ���� ���� ���
		else {  // ���Ḯ��Ʈ ��ũ�� ���󰡼� �� �������� ��� u ����
			Node* p = adj[v];
			while (p->getLink() != NULL) p = p->getLink();
			p->setLink(new Node(u, NULL));
		}
	}


	void display() {  // �׷��� ���� ���� ���÷���
		printf("%d\n", size);
		for (int i = 0; i < size; i++) { // ��� ������ŭ	
			printf("%d  ", getVertex(i));	 // �� ��忡 ����
											 // ���Ḯ��Ʈ ���󰡸鼭 ������ ���� ��� 
			for (Node *v = adj[i]; v != NULL; v = v->getLink())
				printf("   %d", getVertex(v->getId()));
			printf("\n");
		}
	}

	Node* adjacent(int v) { return adj[v]; }
};
