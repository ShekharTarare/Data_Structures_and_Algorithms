#include<Stdio.h>
int main()
{
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, i, k = 10;
    int B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(i = 0; i < 10; i++)
    {
        if(B[k - A[i]] != 0 && k - A[i] >= 0)
        {
            printf("%d + %d = %d\n", A[i], k - A[i], k);
        }
        B[A[i]]++;
    }
    return 0;
}