#include "sort_class.h"

// ������ 61 ������ �˰��� 2.5 �պ� ����
// data[0:n-1]�� �����Ѵ�.

void SortClass::MergeSort2(int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergeSort2(low, mid);
		MergeSort2(mid + 1, high);
		Merge2(low, mid, high);
	}
}