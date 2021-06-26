#include<stdio.h>
int pow(int m, int n)
{
    if(n == 0)
        return 1;
    else
    {
        if(n % 2 == 0)
            return pow(m*m, n/2);
        else
            return m*pow(m*m, (n-1)/2);
    }
}
int main(int argc, char **argv)
{
    int res;
    res = pow(2, 5);
    printf("%d", res);
}
