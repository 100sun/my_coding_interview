#include "MaxHeap.h"
#include <stdlib.h>
#pragma warning(disable : 4996)
void main()
{
	int n;
	scanf("%d", &n);
	MaxHeap heap;

	while (n--) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			if (heap.isEmpty())
				printf("0\n");
			else {
				printf("%d\n", heap.find());
				heap.remove();
			}
		}
		else {
			heap.insert(tmp);
		}
	}

}

