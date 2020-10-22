#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

class Node
{
protected:
	int	id;	// 노드 데이터	
	Node*	link;	// 노드 링크
public:
	Node(int i, Node *l = NULL) : id(i), link(l) { }
	~Node(void) { if (link != NULL) delete link; }

	int      getId() { return id; }		// id를 반환
	Node* getLink() { return link; }		// link를 반환
	void setLink(Node* l) { link = l; }	// link를 l로 설정
};
