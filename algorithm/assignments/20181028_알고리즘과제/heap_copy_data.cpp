#include "sort_class.h"

// org_data[0:n-1]의 데이터를 data[1:n]으로 복사
void SortClass::HeapCopyData(int n)
{
	int i;

	for (i = 0; i < n; i++)
		data[i + 1] = org_data[i];
}