#include<stdio.h>
int fib(int n)
{
    if(n <= 1)
        return n;
    else
    {
        return fib(n-2) + fib(n-1);
    }
}
int main(int argc, char **argv)
{
    printf("%d", fib(6));
}