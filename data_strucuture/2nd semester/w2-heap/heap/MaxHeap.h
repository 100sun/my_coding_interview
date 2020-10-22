#include "HeapNode.h"
#define  MAX_ELEMENT	200

class MaxHeap
{
	HeapNode 	node[MAX_ELEMENT];
	int		 size;
public:
	MaxHeap() : size(0) { }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode&	getParent(int i) { return node[i / 2]; }
	HeapNode&	getLeft(int i) { return node[i * 2]; }
	HeapNode&	getRight(int i) { return node[i * 2 + 1]; }
	
	// 삽입 함수
	void insert(int key) {
		printf("INSERT %d\n", key);
		if (isFull()) return;

		int i = ++size;
		printf("[%d] compare %d & %d /   ", size, key, getParent(i).getKey());

		while (i != 1 && key > getParent(i).getKey()) {
			printf("key %d is larger than its parent %d /   ", key, getParent(i).getKey());
			node[i] = getParent(i);
			printf("change ! /   ");
			printf("One Step UpHeap : update [i] %d --> %d\n", i, i / 2);
			i /= 2;
			printf("[%d] compare %d & %d /   ", i, key, getParent(i).getKey());
		}
		printf("key is smaller than its parent ! /   ");
		printf("The The END of UPHEAP /   ");

		node[i].setKey(key);
		printf("LAST STEP : set key %d into node[%d]\n\n", key, i);
	}

	// 삭제 함수
	HeapNode remove() {
		if (isEmpty()) return NULL;

		HeapNode root = node[1];
		HeapNode last = node[size--];
		printf("\nREMOVE %d %d\n", root.getKey(), last.getKey());

		int parent = 1;
		int child = 2;

		while (child <= size) {
			printf("[parent=%d, child=%d]  /  ", parent, child);
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) {
				child++;
				printf("SELECT RIGHT %d /  ", getRight(parent).getKey());
			}
			else 
				printf("SELECT LEFT %d /  ", getLeft(parent).getKey());

			if (last.getKey() >= node[child].getKey()) {
				printf("last %d is smaller than parent %d /  ", last.getKey(), node[child].getKey());
				break;
			}
			printf("change !  /  ");
			node[parent] = node[child];
			printf("UPDATE parent:%d->%d, child:%d->%d\n", parent, child, child, child * 2);
			parent = child;
			child *= 2;
		}
		printf("Now copy last into the proper position node[%d]\n", parent);
		node[parent] = last;
		return root;
	}

	HeapNode find() { return node[1]; }

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n-------------------------------------------");
	}
};

