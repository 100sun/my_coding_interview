#include "sort_class.h"

// ������ 7 ������ �˰��� 1.3 ��ȯ ����
// data[0:n-1]�� �����Ѵ�.

void SortClass::ExchangeSort(int n)
{
	int i, j;
	int temp;
	int nm2 = n - 2;

	for (i = 0; i <= nm2; i++) // ������������ S[1:n]�̰�, �̰��� data[0:n-1]
		for (j = i + 1; j < n; j++)
			if (data[j] < data[i]) { // exchange
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
}