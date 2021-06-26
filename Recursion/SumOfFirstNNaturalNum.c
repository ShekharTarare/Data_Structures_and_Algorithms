#include<stdio.h>
int sum(int n)
{
    return n*(n+1)/2;
}
int main(int argc, char **argv)
{
    int c;
    c = sum(5);
    printf("%d", c);
    return 0;
}
