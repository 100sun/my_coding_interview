// ���� ����Ʈ�� �̿��� �׷��� �׽�Ʈ ���α׷�
#include "AdjListGraph.h"  	// �׷��� Ŭ���� ����

int main()
{
	AdjListGraph g;            	// ���ο� �׷��� ��ü ����

	for (int i = 0; i<10; i++)   // ���� ����
		g.insertVertex(i);	// size=10

	g.insertEdge(0, 1);      	// ���� ����
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
