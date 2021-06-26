#include<stdio.h>
int pow(int m, int n){
    if(n == 0)
        return 1;
    else return pow(m, n-1)*m;
}
int main(int argc, char **argv)
{
    int res;
    res = pow(2, 5);
    printf("%d", res);
    return 0;
}
