// 인접 리스트를 이용한 그래프 테스트 프로그램
#include "AdjListGraph.h"  	// 그래프 클래스 포함

int main()
{
	AdjListGraph g;            	// 새로운 그래프 객체 생성

	for (int i = 0; i<10; i++)   // 정점 삽입
		g.insertVertex(i);	// size=10

	g.insertEdge(0, 1);      	// 간선 삽입
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);
	g.insertEdge(3, 4);
	g.insertEdge(3, 5);
	g.insertEdge(5, 6);
	g.insertEdge(5, 7);
	g.insertEdge(7, 8);
	g.insertEdge(7, 9);

	system("pause");
	return 0;
}
