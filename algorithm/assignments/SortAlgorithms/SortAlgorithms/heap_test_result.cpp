#include "sort_class.h"

// data[1:n]�� ����� ���ĵǾ����� �˻��Ѵ�.

bool SortClass::HeapTestResult(int n)
{
	int i;

	for (i = 2; i <= n; i++)
		if (data[i - 1] > data[i])
			return false;
	return true;
}