#include "sort_class.h"


// ������ 62 ������ �˰��� 2.5 ���� ����
// data[0:n-1]�� �����Ѵ�.

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
	pivotitem = data[low]; // pivotitem �� ���� ù��° �׸��� ����
	j = low;
	for (i = low + 1; i <= high; i++)
		if (data[i] < pivotitem) {
			j++;
			Swap(&data[i], &data[j]);
		}
	pivotpoint = j;
	Swap(&data[low], &data[pivotpoint]); // pivotitem ���� pivotpoint �� �ִ´�
}

void SortClass::QuickSort(int low, int high) {
	int pivotpoint;
	if (high > low) {
		Partiton(low, high, pivotpoint);
		QuickSort(low, pivotpoint - 1);
		QuickSort(pivotpoint + 1, high);
	}
}
