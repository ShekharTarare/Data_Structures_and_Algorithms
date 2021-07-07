#include<stdio.h>
int main()
{
    int A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int i, lastItem = 0, count = 0;
    
    for (int i = 0; i < 9; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastItem)
        {
            printf("%d\n", A[i]);
            lastItem = A[i];
        }
        else
        {
            count++;
        }
    }
    return 0;
}