#include "MaxHeap.h"
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

// Heap Sorting
inline void heapSort(long long a[], int n)
{
	MaxHeap h;
	for (int i = 0; i<n; i++)	      // maxheap ����
		h.insert(a[i]);		      // n���� insert ���� 

	for (int i = n - 1; i >= 0; i--)       // ��Ʈ �����Ͽ� �迭�� ����
		a[i] = h.remove().getKey();   // ������ max ���� �迭�� ������ ä���.
}

void main()
{
	// ù ��° �ٿ� ī���� ������ ��Ÿ���� �� n(2 �� n �� 1,000)�� ī�� ��ü�� �� �� �ϴ����� ��Ÿ���� �� m(0 �� m �� 15��n)�� �־�����.
	int n, m; 
	scanf("%d %d", &n, &m);

	// �� ��° �ٿ� �� ó�� ī���� ���¸� ��Ÿ���� n���� �ڿ��� a1, a2, ��, an�� �������� ���еǾ� �־�����. (1 �� ai �� 1,000,000)
	long long arr[1001];
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	for (int j = 0; j < m; j++) {
		heapSort(arr, n);
	long long tmp = arr[0] + arr[1];
		arr[0] = tmp;
		arr[1] = tmp;
	}
	for (int i = 0; i < n; i++) {
		ret += arr[i];
	}
	printf("%lld\n", ret);
	
	system("pause");
}
