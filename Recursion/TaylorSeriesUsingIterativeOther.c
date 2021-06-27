#include<stdio.h>
double taylor(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for(i = 1; i<=n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}
int main(int argc, char **argv)
{
    printf("%lf", taylor(4, 10));
    return 0;
}