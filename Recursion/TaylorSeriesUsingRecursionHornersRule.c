#include<stdio.h>
double taylor(int x, int n)
{
    static double s;
    if(n == 0)
        return s;
    else
    {
        s = 1 + x * s/n;
        return taylor(x, n-1);
    }
}
int main(int argc, char **argv)
{
    printf("%lf", taylor(4,10));
    return 0;
}