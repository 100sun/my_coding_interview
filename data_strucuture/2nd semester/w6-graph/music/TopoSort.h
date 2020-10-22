#include "AdjListGraph.h"
#include "ArrayStack.h"

class TopoSortGraph : public AdjListGraph
{
public:
	TopoSortGraph(void) { }
	~TopoSortGraph(void) { }

	void insertDirEdge(int u, int v) {	      // ���⼺ ���� ���� ����
	//printf("adj[%d]= new Node(%d)\n", u, v);
		adj[u] = new Node(v, adj[u]);  // �� ���� ������ ����: u���� v�� ����
	}
	// ���������� ����
	void TopoSort() {
		ArrayStack s;  // ���� ���� ����
		//printf("size = %d\n\n", size);
		// ��� ������ ���� ���� ���
		int *inDeg = new int[size + 1];

		for (int i = 0; i < size; i++)		// ���� ���� �ʱ�ȭ
			inDeg[i] = 0;		// inDeg[] : ���� ����

		for (int i = 0; i < size; i++) {	// ��� ��忡 ���ؼ�
			Node *node = adj[i];	// ���� i���� ������ ������
			//printf("\n\nadj[%d]) ", i);
			while (node != NULL) {
				//printf("\n%d->\t", node->getId());
				inDeg[node->getId()]++;
				//for (int i = 0; i < size; i++) printf("inDeg[%d]=%d\t", i, inDeg[i]);
				node = node->getLink();

			}
		}
		//printf("done\n");
		// ���� ������ 0�� ������ ���ÿ� ����
		for (int i = 0; i < size; i++)
			if (inDeg[i] == 0) s.push(i);
		//s.display();
		// ���� ���� ���� 
		while (s.isEmpty() == false) {
			int w = s.pop();		  //���ÿ��� �ϳ��� ������
			printf("%d\n", getVertex(w)); //�������� 0�� ���� ���
			Node *node = adj[w];	  //���� ������ �������� 1�� ����
			while (node != NULL) {
				int u = node->getId();
				inDeg[u]--;	 //���� ������ ����
				if (inDeg[u] == 0)  //���� ���� 0�Ǹ� ���ÿ� ����
					s.push(u);
				node = node->getLink();	// ���� ����
			}
		}
		//printf("\n");
		delete[] inDeg;
	}
};
