#include "sort_class.h"

// org_data[0:n-1]�� �����͸� data[1:n]���� ����
void SortClass::HeapCopyData(int n)
{
	int i;

	for (i = 0; i < n; i++)
		data[i + 1] = org_data[i];
}