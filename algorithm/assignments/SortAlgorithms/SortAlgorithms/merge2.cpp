#include "sort_class.h"

// ������ 60 ������ �˰��� 2.5 �պ� ����
// data[0:n-1]�� �����Ѵ�.

void SortClass::Merge2(int low, int mid, int high)
{
	int i, j, k;
	int *U; // 1 ���� �迭�� ���� ���� ������
	U = new int[high - low + 1]; // U[0:count 1] where count = high low + 1
	i = low; j = mid + 1; k = 0;
	while ((i <= mid) && (j <= high)) {
		if (data[i] < data[j]) {
			U[k] = data[i]; i++;
		}
		else {
			U[k] = data[j]; j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++)// copydata[j] through S[high] to U[k] through U[
			U[k++] = data[j];
	}
	else {
		for (; i <= mid; i++)// copy i ] through S[mid] to U[k] through U[
			U[k++] = data[i];
	}
	for (i = low; i <= high; i++) // copy U[low] through U[high] to S[low] through S[
		data[i] = U[i - low]; // U[0:count 1] where count = (high low + 1)
	delete[] U;
}