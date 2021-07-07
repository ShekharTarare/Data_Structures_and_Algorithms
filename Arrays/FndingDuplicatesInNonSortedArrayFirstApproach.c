#include<stdio.h>
int main()
{
    int i, j, count, A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    for(i = 0; i < 9; i++)
    {
        count = 1;
        if(A[i] != -1)
        {
            for(j = i + 1; j < 10; j++)
            {
                if(A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
        }
        if(count > 1)
        {
            printf("%d for %d times\n", A[i], count);
        }
    }
    return 0;
}