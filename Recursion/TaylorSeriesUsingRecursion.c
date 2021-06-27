#include<stdio.h>
double taylor(int x, int n)
{
    static double p = 1, f = 1;
    double res;
    if(n == 0)
        return 1;
    else
    {
        res = taylor(x, n-1);
        p = p * x;
        f = f * n;
        return res + p/f;
    }
}
int main(int argc, char **argv)
{
    double result;
    result = taylor(3, 10);
    printf("%lf", result);
    return 0;
}