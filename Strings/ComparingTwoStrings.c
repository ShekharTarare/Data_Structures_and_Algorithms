#include<stdio.h>
int main()
{
    char A[] = "Pointers";
    char B[] = "Pointing";
    int i, j, flag = 0;

    for(i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if(A[i] != B[j])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("\nStrings are not similar");
    else
        printf("\nStrings are similar");

    return 0;
}