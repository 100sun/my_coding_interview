#include "MinHeap.h"
#include <stdlib.h>

void main()
{
    MinHeap heap;
    int number;
    int a;
    HeapNode node;
    int result[100000];
    int size = 0;

    printf("\n���� �Է�\n");
    scanf("%d", &number); 
    for (int i=0; i<number; i++)
    {
        scanf("%d", &a); 
        if (a == 0) {
                if (heap.isEmpty()) result[size++] = 0;
                else {
                    node = heap.remove();
                    result[size++] = node.getKey();
                }
        }
        else heap.insert(a);
    }

    // ��� ���
    printf("\n���� ���\n");
    for (int i = 0; i < size; i++)
        printf("%d\n", result[i]);

    system("pause"); // heap display
}
