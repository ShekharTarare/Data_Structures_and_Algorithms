#include<stdio.h>
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
        return fact(n-1) * n;
}
int main(int argc, char **argv)
{
    int res;
    res = fact(5);
    printf("%d", res);
    return 0;
}
