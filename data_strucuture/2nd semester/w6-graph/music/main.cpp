#include "TopoSort.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k, temp[1004], in[1004];
vector<int> adj[1004];
queue<int> q;
vector<int> ret;

int main() {
	TopoSortGraph g;
 
	scanf("%d %d", &n, &m); // num of singers and assistant pd
	for (int i = 0; i < n; i++)
		g.insertVertex(i+1);
	//g.printVertex();
	for (int i = 0; i < m; i++) {
		scanf("%d", &k); // num of singers 
		for (int i = 0; i < k; i++) {
			scanf("%d", &temp[i]); // order of singers
			if (i > 0) {
				g.insertDirEdge(temp[i - 1]-1, temp[i]-1);
			}
		}
	}
	printf("Topology Sort:\n");
	g.TopoSort();
	return 0;
}