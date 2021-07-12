#include<stdio.h>
int main()
{
    char *name = "Shekhar";
    int i;
    for(i = 0; name[i] != '\0'; i++);
    printf("Length is %d", i);
    return 0;
}