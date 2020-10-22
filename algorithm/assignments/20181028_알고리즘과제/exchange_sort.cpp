#include "sort_class.h"

// 교과서 7 페이지 알고리즘 1.3 교환 정렬
// data[0:n-1]을 정렬한다.

void SortClass::ExchangeSort(int n)
{
	int i, j;
	int temp;
	int nm2 = n - 2;

	for (i = 0; i <= nm2; i++) // 교과서에서는 S[1:n]이고, 이곳은 data[0:n-1]
		for (j = i + 1; j < n; j++)
			if (data[j] < data[i]) { // exchange
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
}