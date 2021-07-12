#include<stdio.h>
int main()
{
    char inp1[] = "medical";
    char inp2[] = "decimal";
    int i, hash[26] = {0};

    for(i = 0; inp1[i] != '\0'; i++)
    {
        hash[(inp1[i] - 97)]++;
    }

    for(i = 0; inp2[i] != '\0'; i++)
    {
        hash[(inp2[i] - 97)]--;
        if(hash[inp2[i] - 97] < 0)
        {
            printf("\nNot Anagram!");
            break;
        }
    }

    if(inp2[i] == '\0')
        printf("\nAnagram!");
    return 0;
}