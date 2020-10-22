#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VTXS 100

class Node {
protected:
	int id; 	// ������ id
	Node* link; 	// ���� ����� ������
public:
	Node(int i, Node* l = NULL) : id(i), link(l) { }
	~Node() {
		if (link != NULL) delete link;
	}
	int   getId() { return id; }
	Node* getLink() { return link; }
	void  setLink(Node* l) { link = l; }
};

// ���� ����Ʈ�� ���� ��� �׷��� Ŭ���� ����
class AdjListGraph {
protected:
	int size;                // ������ ����
	int vertices[MAX_VTXS]; // ���� ���� (���뿡 ���� Ȯ�� �ʿ�)
	Node* adj[MAX_VTXS];     // �� ������ ���� ����Ʈ
public:
	AdjListGraph() : size(0) { }
	~AdjListGraph() { reset(); }
	bool isFull() {
		return (size >= MAX_VTXS);
	}
	int getVertex(int i) { return vertices[i]; }
	
	void printVertex() { for (int i = 0; i < 6; i++)printf("vertices[%d]=%d\n", i, vertices[i]); }

	void reset(void) {
		for (int i = 0; i < size; i++)
			if (adj[i] != NULL) delete adj[i];
	}

	void insertVertex(int val) {      // ���� ���� ����
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else printf("Error: �׷��� ���� ���� �ʰ�\n");
	}

	void insertEdge(int u, int v) {    // ���� ���� ����
		adj[u] = new Node(v, adj[u]); // ���� ����Ʈ�� �߰�
		adj[v] = new Node(u, adj[v]); // ���� �׷��� ==> �ּ� ó����
		printf("%d %d : ", getVertex(u), getVertex(v));
	}

	void display() {
		printf("%d\n", size);                // ������ ���� ���
		for (int i = 0; i < size; i++) {      // �� ���� ���� ���
			printf("%d | ", getVertex(i));         // ������ �̸� ���
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				printf(" %d", getVertex(v->getId()));
			printf("\n");
		}
	}

	Node* adjacent(int v) { return adj[v]; }

	void load(const char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				int str[80];
				int val;
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					fscanf(fp, "%d", &val);
					if (i > j)
						if (val != 0) insertEdge(i, j);
				}
			}
			fclose(fp);
		}
	}
};


