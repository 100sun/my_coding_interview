#include "sort_class.h"

// 교과서 275 페이지 알고리즘 7.2 선택 정렬
// data[0:n-1]을 정렬한다.

void SortClass::SelectionSort(int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subdataay 
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted dataay 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (data[j] < data[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		Swap(&data[min_idx], &data[i]);
	}
}