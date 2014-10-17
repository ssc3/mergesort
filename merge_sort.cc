// Copied from here: http://www.cs.cityu.edu.hk/~lwang/ccs4335/mergesort.c

#include "stdio.h"
#include "stdlib.h"

void merge(int A[], int n1, int B[], int n2, int C[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i<n1) && (j<n2))
    {
        if (A[i] <= B[j])
        {
            /* copy A[i] to C[k] and move the pointer i and k forward */
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            /* copy B[j] to C[k] and move the pointer j and k forward */
            C[k] = B[j];
            j++;
            k++;
        }
    }

    /* move the remaining elements in A into C */
    while (i < n1)
    {
        C[k]= A[i];
        i++;
        k++;
    }
    /* move the remaining elements in B into C */
    while (j < n2)
    {
        C[k]= B[j];
        j++;
        k++;
    }
}  

void mergesort(int src[],int size)
{
    
    int* A1;
    int* A2;
    int n1, n2;

    // the array is already sorted when n=1
    if (size < 2)
        return;

    // divide array src into two subarrays A1 and A2
    n1 = size/2; // num elems in A1
    n2 = size - size/2; // num elems in A2

    A1 = (int*)malloc(sizeof(int) * n1);
    A2 = (int*)malloc(sizeof(int) * n2);

    // move the first n/2 elems in A1
    for (int i=0; i<n1; i++)
        A1[i] = src[i];

    // move the remaining elems in A2
    for (int i=0; i<n2; i++)
        A2[i] = src[i+n1];

    // recursive call
    mergesort(A1, n1);
    mergesort(A2, n2);

    // merge aka conquer
    merge(A1, n1, A2, n2, src);

}

int main()
{
    int src[] = {5,3,1,4,6,9};
    int size = sizeof(src)/sizeof(src[0]);

    printf("%d\n", size);

    mergesort(src, size);

    for (int i=0;i<size; i++)
        printf("%d ", src[i]);

    return 0;
}
