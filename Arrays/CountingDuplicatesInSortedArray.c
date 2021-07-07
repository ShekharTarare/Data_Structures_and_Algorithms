#include<stdio.h>
int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int i, j = 0;
    for(i = 0; i < 8; i++)
    {
        if(A[i] == A[i + 1])
        {
            j = i + 1;
            while(A[j] == A[i])
            {
                j++;
            }
            printf("%d is present for %d times\n", A[i], j - i);
            i = j - 1;
        }
    }
    return 0;
}