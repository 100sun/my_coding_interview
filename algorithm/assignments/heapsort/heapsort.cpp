#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
// 교과서 293 페이지 알고리즘 7.5 힙 정렬
// data[1:n]을 정렬한다.
int data[7];

void printArray(string s, int n)
{
    cout << s;

    for (int i = 1; i <= n; i++)
        cout << data[i] << " ";
    cout << endl
         << endl;
}

void SiftDown(int n, int i)
{
    int parent, largerchild;
    int siftkey;
    bool spotfound;

    siftkey = data[i];
    parent = i;
    spotfound = false;

    while (2 * parent <= n && !spotfound)
    {
        //   printf("loop : 2 * parent(%d) <= 7 && spotfound = %d\n", parent, spotfound);
        if (2 * parent < n && data[2 * parent] < data[2 * parent + 1])
            largerchild = 2 * parent + 1;
        else
            largerchild = 2 * parent;
        //printf("after shiftdown: data[%d]=%d <-> data[%d]=%d\n", parent, data[parent], largerchild, data[largerchild]);

        if (siftkey < data[largerchild])
        {
            data[parent] = data[largerchild];
            parent = largerchild;
            //    printf("parent = %d\n", parent);
        }
        else
        {
            spotfound = true;
            //   printf("spotfound = %d\n", parent, spotfound);
        }
    }
    data[parent] = siftkey;
    // printf("end===\n");
}

int Root(int n)
{
    int keyout;
    keyout = data[1];
    data[1] = data[n];
    SiftDown(n - 1, 1);
    printf("delete %d ", keyout);
    printArray("so => ", n - 1);
    return keyout;
}

void RemoveKeys(int n)
{
    for (int i = n; i >= 1; i--)
    {
        printf("%d) ", i);
        data[i] = Root(n--);
    }
}

void MakeHeap(int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        //   printf("\nmakeheap : siftdown(%d)=%d\n", i, data[i]);
        SiftDown(n, i);
    }
}

void HeapSort(int n)
{
    MakeHeap(n);
    printArray("after make heap:", 7);
    RemoveKeys(n);
    printArray("after remove keys:", 7);
}

bool HeapTestResult(int n)
{
    int i;

    for (i = 2; i <= n; i++)
        if (data[i - 1] > data[i])
            return false;
    return true;
}

int main()
{
    int n = 7;
    int org_data[7] = {20, 10, 30, 50, 40, 70, 60};
    for (int i = 0; i < n; i++)
        data[i + 1] = org_data[i];
    printArray("after aligning:", 7);

    HeapSort(n); // parameter 수정

    printArray("before test:", 7);
    if (HeapTestResult(n))
        cout << "Good in Heap Sort. " << endl;
    else
        cout << "Error in Heap Sort." << endl;
    return 0;
}
