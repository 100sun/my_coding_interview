#include "sort_class.h"

// ������ 272 ������ �˰��� 7.1 ���� ����
// data[0:n-1]�� �����Ѵ�.

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