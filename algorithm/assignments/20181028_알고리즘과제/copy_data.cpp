#include "sort_class.h"

// org_data[0:n-1]�� �����͸� data[0:n-1]�� ����

void SortClass::CopyData(int n)
{
	int i;

	for (i = 0; i < n; i++)
		data[i] = org_data[i];
}