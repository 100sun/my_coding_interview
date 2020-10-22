#include "SrchALGraph.h"

int main()
{
	int x, y;
	int N = 0, M = 0, V = 0;
	scanf("%d %d %d", &N, &M, &V);

	SrchALGraph g;
	for (int i = 0; i < N; i++)
		g.insertVertex(i);

	for (int i = 0; i < M; i++) {
		x = 0; y = 0;
		scanf("%d %d", &x, &y);
		g.insertEdge(x, y);
	}

	g.display();
	g.resetVisited();
	g.DFS(V);  // vertex A
	printf("\n");

	g.resetVisited();
	g.BFS(V);  // vertex A
	printf("\n");
	return 0;
}
