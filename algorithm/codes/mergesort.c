#include <stdlib.h>
#include <stdio.h>

void printArray(int size, const int A[])
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge(int h, int m, const int U[], const int V[], int S[])
{
    printArray(h, U);
    printArray(m, V);
    printArray(h + m, S);

    int i = 1; // right
    int j = 1; // left
    int k = 1; // complete

    // comparison and copy
    while (i <= h && j <= m)
    {
        if (U[i] < V[j]) // left one is bigger
        {
            S[k] = U[i];
            i++;
        }
        else // right one is bigger
        {
            S[k] = V[j];
            j++;
        }
        k++;

        printf("U[i=%d]=%d U : ", i, U[i]);
        printArray(h, U);
        printf("j = %d V : ", j);
        printArray(m, V);

        printf("k = %d S : ", k);
        printArray(h + m, S);
        printf("\n");
    }

    // remains copy
    if (i > h)
        while (k < (h + m) && j < m)
        {
            printf("first : i=%d h=%d j=%d m=%d\n", i, h, j, m);
            S[k] = V[j];
            j++;
            k++;
        }
    else
        while (i < h && k < (h + m))
        {
            printf("second : i=%d h=%d j=%d m=%d\n", i, h, j, m);
            S[k] = U[i];
            i++;
            k++;
        }
}

void mergesort(int n, int S[])
{
    const int h = n / 2;
    const int m = n - h;
    int *U = (int *)malloc(h * sizeof(int));
    int *V = (int *)malloc(h * sizeof(int));

    // divide
    int i = 0;
    int right_index = 0;
    if (n > 1)
    {
        while (i < h)
        {
            U[i] = S[i];
            i++;
        }
        while (i < n && right_index < m)
        {
            V[right_index] = S[i];
            right_index++;
            i++;*
        }
        // conquer
        mergesort(h, U);
        mergesort(m, V);
        // combine
        if (h == 4)
            merge(h, m, U, V, S);
    }
}

int main()
{
    int arr[] = {27, 12, 10, 20, 13, 22, 15, 25};

    printf("Given array is \n");
    printArray(8, arr);

    mergesort(8, arr);

    printf("\nSorted array is \n");
    printArray(8, arr);
    return 0;
}
