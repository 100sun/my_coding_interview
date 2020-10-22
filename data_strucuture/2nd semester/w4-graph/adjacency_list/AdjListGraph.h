#include "graphList.h"

// 연결 리스트를 위한 노드 그래프 클래스 포함
class AdjListGraph {
protected:
	int size;                // 정점의 개수
	int vertices[MAX_VTXS]; // 정점 정보 (응용에 따라 확장 필요)
	Node* adj[MAX_VTXS];     // 각 정점의 인접 리스트
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
	void insertVertex(int val) {      // 정점 삽입 연산
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else printf("Error: 그래프 정점 개수 초과\n");
	}
	void insertEdge(int u, int v) {    // 간선 삽입 연산
		printf("\n%d%d: %d\n", getVertex(u), getVertex(v), size);
		adj[u] = new Node(v, adj[u]); // 인접 리스트에 추가
		adj[v] = new Node(u, adj[v]); // 방향 그래프 ==> 주석 처리함
		display();
	}
	void display() {
		for (int i = 0; i < size; i++) {      // 각 행의 정보 출력
			printf("%d ", getVertex(i));         // 정점의 이름 출력
			for (Node *v = adj[i]; v != NULL; v = v->getLink())
				printf(" %d", getVertex(v->getId()));
			printf("\n");
		}
	}
	Node* adjacent(int v) { return adj[v]; }
};