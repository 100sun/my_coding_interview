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

	// ���� �켱 Ž�� 
	void DFS(int v) {
		visited[v] = true;		// ��� �湮 ǥ��
		printf("%c ", getVertex(v));  	// ��� ��� A,B,C,��

										// v�� �����ϰ� �湮���� ��� ��忡 ���ؼ� DFS ��ȯȣ��
		for (Node *p = adj[v]; p != NULL; p = p->getLink())
			if (visited[p->getId()] == false)  // �湮����
				DFS(p->getId());	// ��ȯȣ��
	}

	// �ʺ� �켱 Ž��
	void BFS(int v) {
		visited[v] = true;		// ��� �湮 ǥ��			
		printf("%c ", getVertex(v));	// ��� ���, A,B,C,��.

		CircularQueue que;
		que.enqueue(v);		// ť�� ����			

		while (!que.isEmpty()) {	// ť�� �����Ͱ� �ִ� ���ȿ�
			int v = que.dequeue();	// ť���� ��� v ������
									// ��� v�� ������ ��� ��忡 ���ؼ�	
			for (Node *w = adj[v]; w != NULL; w = w->getLink()) {
				int id = w->getId(); // id = ��� �ε���	
				if (!visited[id]) {	  // �湮 ���Ͽ�����	
					visited[id] = true;		//��� �湮 ǥ��
					printf("%c ", getVertex(id)); 	// ��� ���
					que.enqueue(id);	    	// ť�� ����
				}
			}
		}
	}

	// �ʺ� �켱 Ž��
	int BFS_kin(int v, int child) {
		int cnt[101] = { 0 };
		visited[v] = true;		// ��� �湮 ǥ��			

		CircularQueue que;
		que.enqueue(v);		// ť�� ����			

		while (!que.isEmpty()) {	// ť�� �����Ͱ� �ִ� ���ȿ�
			int v = que.dequeue();	// ť���� ��� v ������
			int count = 0;
			for (Node *w = adj[v]; w != NULL; w = w->getLink()) { // ��� v�� ������ ��� ��忡 ���ؼ�	
				int id = w->getId(); // id = ��� �ε���	
				if (!visited[id]) {	  // �湮 ���Ͽ�����	
					visited[id] = true;		//��� �湮 ǥ��
					que.enqueue(id);	    	// ť�� ����
					cnt[id] = cnt[v] + 1;
				}
			}
		}
		return (cnt[child] ? cnt[child] : -1);
	}
};
