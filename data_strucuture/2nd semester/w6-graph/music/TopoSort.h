#include "AdjListGraph.h"
#include "ArrayStack.h"

class TopoSortGraph : public AdjListGraph
{
public:
	TopoSortGraph(void) { }
	~TopoSortGraph(void) { }

	void insertDirEdge(int u, int v) {	      // 방향성 간선 삽입 연산
	//printf("adj[%d]= new Node(%d)\n", u, v);
		adj[u] = new Node(v, adj[u]);  // 한 방향 간선만 삽입: u에서 v로 가는
	}
	// 위상정렬을 수행
	void TopoSort() {
		ArrayStack s;  // 스택 변수 선언
		//printf("size = %d\n\n", size);
		// 모든 정점의 진입 차수 계산
		int *inDeg = new int[size + 1];

		for (int i = 0; i < size; i++)		// 진입 차수 초기화
			inDeg[i] = 0;		// inDeg[] : 진입 차수

		for (int i = 0; i < size; i++) {	// 모든 노드에 대해서
			Node *node = adj[i];	// 정점 i에서 나오는 간선들
			//printf("\n\nadj[%d]) ", i);
			while (node != NULL) {
				//printf("\n%d->\t", node->getId());
				inDeg[node->getId()]++;
				//for (int i = 0; i < size; i++) printf("inDeg[%d]=%d\t", i, inDeg[i]);
				node = node->getLink();

			}
		}
		//printf("done\n");
		// 진입 차수가 0인 정점을 스택에 삽입
		for (int i = 0; i < size; i++)
			if (inDeg[i] == 0) s.push(i);
		//s.display();
		// 위상 순서 생성 
		while (s.isEmpty() == false) {
			int w = s.pop();		  //스택에서 하나씩 꺼내서
			printf("%d\n", getVertex(w)); //진입차수 0인 정점 출력
			Node *node = adj[w];	  //인접 정점의 진입차수 1씩 감소
			while (node != NULL) {
				int u = node->getId();
				inDeg[u]--;	 //진입 차수를 감소
				if (inDeg[u] == 0)  //진입 차수 0되면 스택에 삽입
					s.push(u);
				node = node->getLink();	// 다음 정점
			}
		}
		//printf("\n");
		delete[] inDeg;
	}
};
