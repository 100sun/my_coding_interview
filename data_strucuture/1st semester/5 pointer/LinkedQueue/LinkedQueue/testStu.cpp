#include "LinkedQueue.h"
#include <stdio.h>

int main() {
	LinkedQueue q;
	q.enqueue(new Node(2017, "���ǿ�", "�濵�а�"));
	q.enqueue(new Node(2018, "�鼱��", "��ǻ�Ͱ��а�"));
	q.enqueue(new Node(2019, "������", "ȣ�ڰ濵�а�"));
	q.enqueue(new Node(2020, "�鼱��", "�ɸ��а�"));
	q.display();

	delete q.dequeue();
	q.display();
	return 0;
}