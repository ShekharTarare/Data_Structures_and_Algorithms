#include<stdio.h>
int main()
{
    int a[3] = {6,12,20};
    int j = 0;
    
    for (int i = a[0]; i < a[2]; i++)
    {
        if (i == a[j])
        {
            j++;
        }
        else
        {
            printf("%d\n", i);
        }
    }
    return 0;
}