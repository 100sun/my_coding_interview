#pragma once
#include "AdjListGraph.h"
#include "circularQ.h"

class SrchALGraph : public AdjListGraph
{
	bool	visited[MAX_VTXS];  
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}

	bool isLinked(int u, int v) {
		for (Node *p = adj[u]; p != NULL; p = p->getLink())
			if (p->getId() == v) return true;
		return false;
	}

	// 깊이 우선 탐색 
	void DFS(int v) {
		visited[v] = true;		// 노드 방문 표시
		printf("%c ", getVertex(v));  	// 노드 출력 A,B,C,…

										// v에 인접하고 방문안한 모든 노드에 대해서 DFS 순환호출
		for (Node *p = adj[v]; p != NULL; p = p->getLink())
			if (visited[p->getId()] == false)  // 방문안한
				DFS(p->getId());	// 순환호출
	}

	// 너비 우선 탐색
	void BFS(int v) {
		visited[v] = true;		// 노드 방문 표시			
		printf("%c ", getVertex(v));	// 노드 출력, A,B,C,….

		CircularQueue que;
		que.enqueue(v);		// 큐에 삽입			

		while (!que.isEmpty()) {	// 큐에 데이터가 있는 동안에
			int v = que.dequeue();	// 큐에서 노드 v 꺼내서
									// 노드 v에 인접한 모든 노드에 대해서	
			for (Node *w = adj[v]; w != NULL; w = w->getLink()) {
				int id = w->getId(); // id = 노드 인덱스	
				if (!visited[id]) {	  // 방문 안하였으면	
					visited[id] = true;		//노드 방문 표시
					printf("%c ", getVertex(id)); 	// 노드 출력
					que.enqueue(id);	    	// 큐에 삽입
				}
			}
		}
	}

	// 너비 우선 탐색
	int BFS_kin(int v, int child) {
		int cnt[101] = { 0 };
		visited[v] = true;		// 노드 방문 표시			

		CircularQueue que;
		que.enqueue(v);		// 큐에 삽입			

		while (!que.isEmpty()) {	// 큐에 데이터가 있는 동안에
			int v = que.dequeue();	// 큐에서 노드 v 꺼내서
			int count = 0;
			for (Node *w = adj[v]; w != NULL; w = w->getLink()) { // 노드 v에 인접한 모든 노드에 대해서	
				int id = w->getId(); // id = 노드 인덱스	
				if (!visited[id]) {	  // 방문 안하였으면	
					visited[id] = true;		//노드 방문 표시
					que.enqueue(id);	    	// 큐에 삽입
					cnt[id] = cnt[v] + 1;
				}
			}
		}
		return (cnt[child] ? cnt[child] : -1);
	}
};
