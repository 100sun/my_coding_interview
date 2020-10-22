#include "sort_class.h"

// data[0:n-1]이 제대로 정렬되었는지 검사한다.

bool SortClass::TestResult(int n)
{
	int i;
	for (i = 1; i < n; i++) {
		if (data[i - 1] > data[i])
			return false;
	}
	return true;
}