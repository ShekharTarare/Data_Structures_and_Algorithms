#include<stdio.h> 
int main()
{
    char a[]="findingssysssy";
    long int h1=0;
    long int h2=0;
    long int x=0;
 
    for (int i=0; a[i] != '\0'; i++) {
        x = 1;
        x = x << (a[i]-97);
        if ( (x&h1) > 0 )
            h2 = (x&h1) | h2;
        else
            h1 = x | h1;
    }
 
    x = 1;
    int count = 0;
    while (count >= 0 && count <= 25) {
        if((h2 & x) > 0) {
            printf("%c is duplicate\n", count + 97);
        }
        x = x << 1;
        count++;
    }
    return 0;
}