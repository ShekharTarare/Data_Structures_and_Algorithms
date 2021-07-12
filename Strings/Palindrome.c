#include<stdio.h>
int main()
{
    char inp[] = "LEVEL";
    int i, j, flag = 0;
    for(j = 0; inp[j] != '\0'; j++);
    j -= 1;

    for(i = 0, j; i <= j; i++, j--)
    {
        if(inp[i] != inp[j])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("\nString is not Palindrome!");
    else
        printf("\nString is Palindrome!");

    return 0;
}