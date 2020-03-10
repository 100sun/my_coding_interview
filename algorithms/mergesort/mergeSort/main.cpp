#pragma warning(disable: E0028)
#include <stdlib.h>
#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
	// subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
	int N = high - low + 1;
	int b[N]; // discuss: why do we need a temporary array b?

	int left = low, right = mid + 1, bIdx = 0;

	// merge adjacent partitions 
	while (left <= mid && right <= high) // leftindex ~ rightindex
		// copy the a array to b array to make the order right
		// temp(bottom) array			// just go down	// order change
		b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];

	while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
	while (right <= high) b[bIdx++] = a[right++]; // leftover, if any

	// copy the temp array[b] to original array[a]
	for (int k = 0; k < N; k++) a[low + k] = b[k]; 
}

void mergeSort(int a[], int low, int high) {
	// the array to be sorted is a[low..high]
	if (low < high) { // base case: low >= high (0 or 1 item)
		int mid = (low + high) / 2;

		mergeSort(a, low, mid); // divide into two halves
		mergeSort(a, mid + 1, high); // then recursively sort them

		merge(a, low, mid, high); // conquer: the merge subroutine
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}