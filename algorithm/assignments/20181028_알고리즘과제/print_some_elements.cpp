// ���� 20�� ���Ҹ� ����Ѵ�.
// ������ ����� �Ǿ��� �� Ȯ���Ѵ�.
// data[1:n]�� ������ �Լ������� PrintSomeElements(1, 20)�� call�ϰ�,
// data[0:n-1]�� ������ �Լ������� PrintSomeElements(0, 19)�� call�Ѵ�.

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