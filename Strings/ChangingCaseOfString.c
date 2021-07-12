#include<stdio.h>
#include<stdlib.h>
void ToUppercase(char name[])
{
    int i;
    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] >= 97 && name[i] <= 122)
        {
            name[i] -= 32;
        }
    }
    printf("%s\n", name);
}
void ToLowercase(char name[])
{
    int i;
    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] >= 65 && name[i] <= 90)
        {
            name[i] += 32;
        }
    }
    printf("%s\n", name);
}
int main()
{
    int choice;
    char name[10];

    printf("\nEnter any string: ");
    scanf("%s", &name);

    while(choice != 3)
    {
        printf("Choose from below: ");
        printf("\n1. Uppercase \n2. Lowercase \n3.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: ToUppercase(name);
                    break;
            
            case 2: ToLowercase(name);
                    break;

            case 3: exit(1);
                    break;

            default: printf("\nInvalid option!");
        }
    }
    return 0;
}