#include<stdio.h>
int main(int argc, char **argv)
{
    double x = 4, n = 10;
    double s = 1;
    for(;n>0;n--)
    {
        s=1+x/n*s;
    }
    printf("%lf", s);
    return 0;
}