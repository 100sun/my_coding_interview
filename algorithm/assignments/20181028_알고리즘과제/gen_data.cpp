#include "sort_class.h"

// org_data[0:n-1]의 값을 random number로 생성한다.
// rand() generates pseudo-random number between 0 and RAND_MAX,
// where RAND_MAX = 32,767, 2^15 - 1

double SortClass::RandomNumber1(int & idum)
{
	return 0.0;
}

void SortClass::GenerateData(int n)
{
	int i;
	time_t t1 = time(0); // current time
	srand(t1);
	for (i = 0; i < n; i++)
		org_data[i] = ((1 + rand()) * (1 + rand())) % (10 * n + 1);
}