#include "LinkedStack.h"
#include <stdio.h>

int main() {
	LinkedStack s;
	s.push(new Node(2017, "정건우", "경영학과"));
	s.push(new Node(2018, "백선혜", "컴퓨터공학과"));
	s.push(new Node(2019, "정순영", "호텔경영학과"));
	s.push(new Node(2020, "백선영", "심리학과"));
	s.display();

	Node* n = s.pop();
	printf("[pop]\n");
	n->display();
	printf("\n");

	delete n;
	s.display();
	return 0;
}