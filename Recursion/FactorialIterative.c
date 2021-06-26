#include<stdio.h>
int main(int argc, char **argv)
{
    int res = 1, inp = 5;
    for(int i=1;i<=inp;i++)
    {
        res = res * i;
    }
    printf("%d", res);
    return 0;
}
