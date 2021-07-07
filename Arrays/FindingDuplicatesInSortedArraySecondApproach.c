#include<stdio.h>
int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int i, B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(i = 0; i < 10; i++)
    {
        B[A[i]]++;
    }

    for(i = 1; i < 21; i++)
    {
        if(B[i] > 1)
            printf("%d for %d times\n", i, B[i]);
    }
    return 0;
}