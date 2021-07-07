#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    int diff, i;
    diff = A[0] - 0; //6 - 0 = 6 
    for(i = 0; i < 10; i++) 
    {
        if(A[i] - i != diff)
        {
            printf("\nMissing number is %d", (i + diff));
            break;
        }
    }    
    return 0;
}