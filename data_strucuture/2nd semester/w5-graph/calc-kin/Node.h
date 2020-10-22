#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

class Node
{
protected:
	int	id;	// ��� ������	
	Node*	link;	// ��� ��ũ
public:
	Node(int i, Node *l = NULL) : id(i), link(l) { }
	~Node(void) { if (link != NULL) delete link; }

	int      getId() { return id; }		// id�� ��ȯ
	Node* getLink() { return link; }		// link�� ��ȯ
	void setLink(Node* l) { link = l; }	// link�� l�� ����
};
