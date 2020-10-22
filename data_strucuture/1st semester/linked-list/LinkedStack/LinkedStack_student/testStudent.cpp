#include "LinkedStack.h"
#include <stdio.h>

int main() {
	LinkedStack s;
	s.push(new Node(2017, "���ǿ�", "�濵�а�"));
	s.push(new Node(2018, "�鼱��", "��ǻ�Ͱ��а�"));
	s.push(new Node(2019, "������", "ȣ�ڰ濵�а�"));
	s.push(new Node(2020, "�鼱��", "�ɸ��а�"));
	s.display();

	Node* n = s.pop();
	printf("[pop]\n");
	n->display();
	printf("\n");

	delete n;
	s.display();
	return 0;
}