#include "graphList.h"

// ���� ����Ʈ�� ���� ��� �׷��� Ŭ���� ����
class AdjListGraph {
protected:
	int size;                // ������ ����
	int vertices[MAX_VTXS]; // ���� ���� (���뿡 ���� Ȯ�� �ʿ�)
	Node* adj[MAX_VTXS];     // �� ������ ���� ����Ʈ
public:
	AdjListGraph() : size(0) { }
	~AdjListGraph() { reset(); }

	int getVertex(int i) { return vertices[i]; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

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
		printf("\n%d%d: %d\n", getVertex(u), getVertex(v), size);
		adj[u] = new Node(v, adj[u]); // ���� ����Ʈ�� �߰�
		adj[v] = new Node(u, adj[v]); // ���� �׷��� ==> �ּ� ó����
		display();
	}
	void display() {
		for (int i = 0; i < size; i++) {      // �� ���� ���� ���
			printf("%d ", getVertex(i));         // ������ �̸� ���
			for (Node *v = adj[i]; v != NULL; v = v->getLink())
				printf(" %d", getVertex(v->getId()));
			printf("\n");
		}
	}
	Node* adjacent(int v) { return adj[v]; }
};