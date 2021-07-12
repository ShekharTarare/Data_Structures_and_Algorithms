#include<stdio.h>
int ValidString(char *inp)
{
    int i;
    for(i = 0; inp[i] != '\0'; i++)
    {
        if(!(inp[i] >= 65 && inp[i] <= 90) &&
           !(inp[i] >= 97 && inp[i] <= 122) &&
           !(inp[i] >= 48 && inp[i] <= 57))
           {
               return 0;
           }
    }
    return 1;
}
int main()
{
    char *inp = "Shekhar?123";
    
    if(ValidString(inp))
        printf("\nValid String!");
    else    
        printf("\nInvalid String!");
    return 0;
}