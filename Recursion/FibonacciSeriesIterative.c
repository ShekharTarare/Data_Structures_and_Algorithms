#include<stdio.h>
int fib(int n)
{
    int res = 0;
    int t0 = 0, t1 = 1;
    if(n <= 1)
        return n;
    else
    {
        for(int i = 2; i <= n; i++)
        {
            res = t0 + t1;
            t0 = t1;
            t1 = res;
        }
        return res;
    }
}
int main(int argc, char **argv)
{
    printf("%d", fib(6));
    return 0;
}