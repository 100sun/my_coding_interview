#include <stdio.h>

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void rotate(int* nums, int numsSize, int k) {
	if (numsSize <= 0 || k <= 0) return;

	for (int i = 0; i<k; i++) {
		int temp = nums[numsSize];
		printf("temp = %d\n", temp);
		for (int j = numsSize - 1; j > 0; j--) {
			nums[j] = nums[j - 1];
			printArray(nums, numsSize);
		}
		nums[0] = temp;
		printArray(nums, numsSize);
	}
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7 };
	rotate(arr, 7,3);
}