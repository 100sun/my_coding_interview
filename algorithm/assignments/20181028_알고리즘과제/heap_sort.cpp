#include "sort_class.h"

// 교과서 293 페이지 알고리즘 7.5 힙 정렬
// data[1:n]을 정렬한다.

void SortClass::HeapSort(int n) {
	MakeHeap(n);
	RemoveKeys(n);
}

void SortClass::MakeHeap(int n)
{
	for (int i = n / 2; i >= 1; i--)
		SiftDown(n, i);
}

void SortClass::SiftDown(int n, int i)
{
	int parent, largerchild;
	int siftkey;
	bool spotfound;

	siftkey = data[i];
	parent = i;
	spotfound = false;

	while (2 * parent <= n && !spotfound) {
		if (2 * parent < n && data[2 * parent] < data[2 * parent + 1])
			largerchild = 2 * parent + 1;
		else
			largerchild = 2 * parent;
		if (siftkey < data[largerchild]) {
			data[parent] = data[largerchild];
			parent = largerchild;
		}
		else spotfound = true;
	}
	data[parent] = siftkey;
}

void SortClass::RemoveKeys(int n)
{
	for (int i = n; i >= 1; i--)
		data[i] = Root(n--);
}

int SortClass::Root(int n)
{
	int keyout;
	keyout = data[1];
	data[1] = data[n];
	SiftDown(n - 1, 1);
	return keyout;
}

