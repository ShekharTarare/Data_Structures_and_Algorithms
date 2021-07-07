#include<stdio.h>
int main()
{
    int A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7}, i;
    int B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(i = 0; i < 10; i++)
    {
        B[A[i]]++;
    }
    for(i = 1; i < 9; i++)
    {
        if(B[i] > 1)
        {
            printf("%d for %d times\n", i, B[i]);
        }
    }
    return 0;
}