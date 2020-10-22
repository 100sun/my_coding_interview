#include "sort_class.h"

// 교과서 272 페이지 알고리즘 7.1 삽입 정렬
// data[0:n-1]을 정렬한다.

void SortClass::InsertionSort(int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = data[i];
		j = i - 1;

		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
}