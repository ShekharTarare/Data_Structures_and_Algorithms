#include<stdio.h>
int main()
{
    int inp = 5, sum=0;
    for(int i=1;i<=inp;i++)
    {
        sum = sum + i;
    }
    printf("%d", sum);
    return 0;
}
