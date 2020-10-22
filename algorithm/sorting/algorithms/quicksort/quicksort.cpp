/* C++ implementation of QuickSort */
#include <stdio.h>
#include <iostream>
using namespace std;

// A utility function to swap two elements 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int partition(int arr[], int pivot, int high) {
	// set first element as pivot
	int pivot_value = arr[pivot];
	int will_be_swaped_index = pivot + 1; // S1 and S2 are initially empty

                // cuz you set the first element as the pivot already
	for (int i = will_be_swaped_index; i <= high; i++) { // explore the unknown region
		if (arr[i] < pivot_value) { // there is sth to be in front of(smaller) the pivot one 
			swap(arr[i], arr[will_be_swaped_index]); will_be_swaped_index++;
		} // notice that we do nothing in case 1: a[k] >= p
        // else : just skip
	}
                    // cuz you did will_be_swaped_index++
	swap(arr[pivot], arr[will_be_swaped_index-1]); 
    printf("%d\t\t\t the swaped SUB array is ==== ", will_be_swaped_index-1); printArray(arr,high-pivot+1);
	return will_be_swaped_index - 1; // return the index of pivot
}

void quickSort(int a[], int low, int high) {
	if (low < high) {
		int m = partition(a, low, high); // O(N)
										 // a[low..high] ~> a[low..m–1], pivot, a[m+1..high]
        printf("%d\tLEFT subarray(arr[%d~%d])\n", m,low, m-1);
		quickSort(a, low, m - 1); // recursively sort left subarray
								  // a[m] = pivot is already sorted after partition
        printf("%d\t\tFULL array by the LEFT subarray sorted is {",m); printArray(a, 6); 

        printf("%d\tRIGHT subarray(arr[%d~%d])\n", m, m+1, high);
		quickSort(a, m + 1, high); // then sort right subarray
        printf("%d\t\tFULL array  by the RIGHT subarray sorted is {",m); printArray(a, 6);     
        printf("==================================one partitions ended.\n"); // recursively
	}
}

// Driver Code 
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
