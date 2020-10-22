#pragma once
#include "Node.h"
#define MAX_VTXS	1005

class AdjListGraph  // 인접 리스트 클래스
{
protected:
	int	size;	// 노드 개수			
	int	vertices[MAX_VTXS];	// 노드 데이터 A,B,C,D	
	Node*	adj[MAX_VTXS];		// 연결리스트 헤드 정보
public:
	AdjListGraph(void) : size(0) { }
	~AdjListGraph(void) { reset(); }

	void reset(void) { 	// adj 연결리스트 해제
		for (int i = 0; i < size; i++)
			if (adj != NULL) delete adj[i];
		size = 0;
	}
	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size >= MAX_VTXS); }
	int getVertex(int i) { return vertices[i]; }  // ith 노드 반환,A,B.C…

	void insertVertex(int val) {	// 노드 1개 추가 : int val
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;  // 해당 adj[] 초기화
		}
		else printf("Error: 그래프 정점 개수 초과\n");
	}

	void insertEdge(int u, int v) {
		printf("<%d %d>\n", u, v);
		if (adj[u] == NULL) adj[u] = new Node(v, NULL);  // insert (u,v)
		else {
			display();
			Node* p = adj[u];
			while (p->getLink() != NULL) p = p->getLink();
			p->setLink(new Node(v, NULL));
		}
		printf("%d inserted\n", u);
		if (adj[v] == NULL) adj[v] = new Node(u, NULL); // 연결리스트에 노드가 아직 없는 경우
		else {  // 연결리스트 링크를 따라가서 맨 마지막에 노드 u 삽입
			display();
			printf("HERE\n");

			Node* p = adj[v];
			printf("HERE\n");

			while (p->getLink() != NULL) p = p->getLink();
			printf("HERE\n");
			p->setLink(new Node(u, NULL));
		}
		printf("%d inserted\n", v);
	}

	void display() {  // 그래프 연결 정보 디스플레이
		printf("%d\n", size);
		for (int i = 0; i < size; i++) { // 노드 갯수만큼	
			printf("%d  ", getVertex(i));	 // 각 노드에 대해
											 // 연결리스트 따라가면서 인접한 노드들 출력 
			for (Node *v = adj[i]; v != NULL; v = v->getLink())
				printf("   %d", getVertex(v->getId()));
			printf("\n");
		}
	}

	Node* adjacent(int v) { return adj[v]; }
};
