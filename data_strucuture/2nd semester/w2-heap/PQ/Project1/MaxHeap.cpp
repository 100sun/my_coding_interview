#include "MaxHeap.h"
#include <stdlib.h>

void main()
{
     /*---------------------------------------------*/
     /*    Understanding MaxHeap Perfectly well     */
     /*---------------------------------------------*/
    MaxHeap heap;

/*  ���� �����̵� ����
     heap.insert(10);
     heap.insert(5);
     heap.insert(30);
     heap.insert(8);
     heap.insert(9);
     heap.insert(3);
     heap.insert(7);
     heap.display(); // heap display

     heap.remove();
     heap.display();

     heap.remove();
     heap.display();
*/
    // ���� �˻�� ����
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.display(); // heap display

    heap.remove();
    heap.display();

    heap.remove();
    heap.display();

    system("pause"); // heap display
}
