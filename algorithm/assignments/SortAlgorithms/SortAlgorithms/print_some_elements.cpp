// 앞의 20개 원소를 출력한다.
// 정렬이 제대로 되었는 지 확인한다.
// data[1:n]을 정렬한 함수에서는 PrintSomeElements(1, 20)을 call하고,
// data[0:n-1]을 정렬한 함수에서는 PrintSomeElements(0, 19)를 call한다.

#include "sort_class.h"

void SortClass::PrintSomeElements(int low, int high)
{
	int i, j;

	for (i = low, j = 0; i <= high; i++, j++)
		if ((j + 1) % 5 == 0)
			output_file << data[i] << endl;
		else
			output_file << data[i] << " ";

	output_file << endl;
}