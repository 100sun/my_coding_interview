// graphList.h : ���� ����Ʈ�� �̿��� �׷����� ���� ��� Ŭ����
#include <stdlib.h>
#include <stdio.h>
#define MAX_VTXS 100

class Node {
protected:
	int id; 	// ������ id
	Node* link; 	// ���� ����� ������
public:
	Node(int i, Node *l = NULL) : id(i), link(l) { }
	~Node() {
		if (link != NULL) delete link;
	}
	int   getId() { return id; }
	Node* getLink() { return link; }
	void  setLink(Node* l) { link = l; }
};
