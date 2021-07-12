#include<stdio.h>
int main()
{
    int i, length, temp;
    char inp[] = "Shekhar";

    //Find the length
    for(length = 0; inp[length] != '\0'; length++){}

    for(i = 0; i < length / 2; i++)
    {
        temp = inp[i];
        inp[i] = inp[length - 1 - i];
        inp[length - 1 - i] = temp;
    }

    printf("%s", inp);
    return 0;
}