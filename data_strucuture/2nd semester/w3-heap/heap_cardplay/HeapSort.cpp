#include "MaxHeap.h"
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

// Heap Sorting
inline void heapSort(long long a[], int n)
{
	MaxHeap h;
	for (int i = 0; i<n; i++)	      // maxheap 구성
		h.insert(a[i]);		      // n번의 insert 연산 

	for (int i = n - 1; i >= 0; i--)       // 루트 제거하여 배열에 저장
		a[i] = h.remove().getKey();   // 제거한 max 값을 배열의 끝부터 채운다.
}

void main()
{
	// 첫 번째 줄에 카드의 개수를 나타내는 수 n(2 ≤ n ≤ 1,000)과 카드 합체를 몇 번 하는지를 나타내는 수 m(0 ≤ m ≤ 15×n)이 주어진다.
	int n, m; 
	scanf("%d %d", &n, &m);

	// 두 번째 줄에 맨 처음 카드의 상태를 나타내는 n개의 자연수 a1, a2, …, an이 공백으로 구분되어 주어진다. (1 ≤ ai ≤ 1,000,000)
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
