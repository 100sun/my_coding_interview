#include "sort_class.h"

// 교과서 61 페이지 알고리즘 2.5 합병 정렬
// data[0:n-1]을 정렬한다.

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