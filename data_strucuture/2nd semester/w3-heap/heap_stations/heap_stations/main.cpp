#include "MaxHeap.h"
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

inline void heapSort(int a[], int n)
{
	MaxHeap h;
	for (int i = 0; i<n; i++)	      
		h.insert(a[i]);		   

	for (int i = n - 1; i >= 0; i--)  
		a[i] = h.remove().getKey();  
}

int stations[101];

int main(void) {

	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> stations[i];
	}
	stations[n + 1] = l;
	heapSort(stations, n + 2);
	int left = 1;
	int right = l - 1;
	while (left <= right) {
		int mcnt = 0;
		int mid = left + (right - left) / 2;
		for (int i = 1; i <= n + 1; ++i) {
			if (stations[i] - stations[i - 1] > mid) {
				mcnt += ((stations[i] - stations[i - 1] - 1)) / mid;
			}
		}
		if (mcnt > m) left = mid + 1;
		else right = mid - 1;
	}

	cout << left << endl;
	return 0;
}