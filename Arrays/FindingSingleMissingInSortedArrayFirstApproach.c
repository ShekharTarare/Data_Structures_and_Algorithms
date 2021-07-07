#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    int sum = 0, i, sumOfNum;
    sumOfNum = (12*(12+1))/2; //12 because we know total numbers are 12 includeing the missing number
                              //Sum of n natural numbers = (n*(n+1))/2
    for(i = 0; i < 11; i++) 
    {
        sum += A[i];
    }
    printf("\nMissing number is %d", (sumOfNum - sum));
    return 0;
}