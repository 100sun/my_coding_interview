#include "sort_class.h"

// data[1:n]이 제대로 정렬되었는지 검사한다.

bool SortClass::HeapTestResult(int n)
{
	int i;

	for (i = 2; i <= n; i++)
		if (data[i - 1] > data[i])
			return false;
	return true;
}