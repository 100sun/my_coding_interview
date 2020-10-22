#include <stdlib.h>
#include <stdio.h>
#include "AdjMatGraph.h"		// 그래프 클래스 포함
#include "AdjListGraph.h"

int 
main()
{
	//---------------------------------------------
	// Adjacent Matrix Graph
	//---------------------------------------------

	AdjMatGraph g;

	for (int i = 0; i < 10; i++) {
		g.insertVertex('0'+i);
	}

	g.insertEdge(0, 1);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 4);
	g.insertEdge(3, 4);
	g.insertEdge(3, 5);
	g.insertEdge(5, 6);
	g.insertEdge(5, 7);
	g.insertEdge(6, 7);
	g.insertEdge(7, 8);
	g.insertEdge(7, 9);

	printf("\nAdjacent Matrix Graph\n");
	g.display();

	//---------------------------------------------
	// Adjacent List Graph
	//---------------------------------------------

	AdjListGraph graph;

	for (int i = 0; i < 10; i++)
		graph.insertVertex('0' + i);

	printf("\n\n-------------------------------------------------\n");
	printf("Adjacent List Graph\n");
	graph.insertEdge(0, 1);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(1, 2);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(1, 3);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(2, 4);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(3, 4);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(3, 5);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(5, 6);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(5, 7);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(6, 7);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(7, 8);
	graph.display(); printf("\n--------------\n");

	graph.insertEdge(7, 9);
	graph.display(); printf("\n--------------\n");

	return 0;
}
