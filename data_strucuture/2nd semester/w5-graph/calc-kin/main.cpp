#include "SrchALGraph.h"

int main()
{
	SrchALGraph graph_kin;
	int people_num = 0, rs_num = 0, parent, child, x, y;

	scanf("%d %d %d %d", &people_num, &parent, &child, &rs_num);
	for (int i = 0; i < people_num; i++)
		graph_kin.insertVertex(i);
	for (int i = 0; i < rs_num; i++) {
		scanf("%d %d", &x, &y);
		graph_kin.insertEdge(x- 1, y- 1);
	}	
	graph_kin.resetVisited();
	int ans = graph_kin.BFS_kin(parent - 1, child - 1);
	printf("%d\n", ans);
	return 0;
}