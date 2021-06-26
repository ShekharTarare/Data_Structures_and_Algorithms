#include<stdio.h>
int main()
{
    int res = 1, m = 2, n = 5;
    for(int i=0;i<n;i++)
    {
        res = res * m;
    }
    printf("%d", res);
    return 0;
}
