#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *A, *B, *C, i = 0, j = 0, k = 0, l;
    A = (int *)malloc(5*sizeof(int));
    B = (int *)malloc(5*sizeof(int));
    C = (int *)malloc(10*sizeof(int));

    A[0] = 3; A[1] = 8; A[2] = 16; A[3] = 20; A[4] = 25;
    B[0] = 4; B[1] = 10; B[2] = 12; B[3] = 22; B[4] = 23;

    for(l = 0; l < 10; l++)
    {
        if(A[i] > B[j] && j!= 5)
        {
            C[k++] = B[j++];
        }
        else
        {
            C[k++] = A[i++];
        } 
    }

    for(l = 0; l < 10; l++)
    {
        printf("%d\n", C[l]);
    }

    return 0;
}