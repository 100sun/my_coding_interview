#include "sort_class.h"


// 교과서 62 페이지 알고리즘 2.5 빠른 정렬
// data[0:n-1]을 정렬한다.

void SortClass::Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void SortClass::Partiton(int low, int high, int& pivotpoint)
{
	int i, j;
	int pivotitem;
	pivotitem = data[low]; // pivotitem 을 위한 첫번째 항목을 고른다
	j = low;
	for (i = low + 1; i <= high; i++)
		if (data[i] < pivotitem) {
			j++;
			Swap(&data[i], &data[j]);
		}
	pivotpoint = j;
	Swap(&data[low], &data[pivotpoint]); // pivotitem 값을 pivotpoint 에 넣는다
}

void SortClass::QuickSort(int low, int high) {
	int pivotpoint;
	if (high > low) {
		Partiton(low, high, pivotpoint);
		QuickSort(low, pivotpoint - 1);
		QuickSort(pivotpoint + 1, high);
	}
}
