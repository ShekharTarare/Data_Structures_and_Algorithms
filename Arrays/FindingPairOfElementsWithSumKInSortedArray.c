#include<stdio.h>
int main()
{
    int A[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, i, j, k;
    i = A[0];
    j = A[9];
    k = 10;
    while(i < j)
    {
        if(A[i] + A[j] == k)
        {
             printf("%d + %d = %d\n", A[i], A[j], k);
             i++;
             j--;
        }
        else
        {
            if(A[i] + A[j] < k)
                i++;
            else
                j--;
        }
    }
    return 0;
}