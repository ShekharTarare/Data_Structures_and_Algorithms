#include<Stdio.h>
int main()
{
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, i, j, k = 10;
    for(i = 0; i < 8; i++)
    {
        for(j = i + 1; j < 9; j++)
        {
            if(A[i] + A[j] == k)
            {
                printf("%d + %d = %d\n", A[i], A[j], k);
            }
        }
    }
    return 0;
}