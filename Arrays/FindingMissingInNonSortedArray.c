#include<stdio.h>
int main()
{
    int A[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int B[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //max is 12 in A that's why declared array of size=13 (0-12)
    int i;

    for(i = 0; i < 10; i++)
    {
        B[A[i]]++;
    }
    for(i = 1; i <= 12; i++)
    {
        if(B[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}