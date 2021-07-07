#include<stdio.h>
int main()
{
    int A[] = {6, 7, 8, 9, 12, 15, 16, 19};
    int i, diff;
    diff = A[0] - 0; //subtracting element with index
    for(i = 0; i < 8; i++)
    {
        if(A[i] - i != diff)
        {
            while(A[i] - i > diff)
            {
                printf("%d\n", i + diff);
                diff++;
            }
        }
    }
    return 0;
}