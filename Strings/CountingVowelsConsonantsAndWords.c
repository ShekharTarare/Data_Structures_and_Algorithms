#include<stdio.h>
int main()
{
    char name[] = "This is my  world";
    int i, countVowels = 0, countConsonants = 0, countWords = 0;

    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122)
        {
            if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' ||
            name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U')
            {
                countVowels++;
            }
            else
                countConsonants++;
        }
    }
    printf("Vowels = %d & Consonants = %d", countVowels, countConsonants);

    //counting words
    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] == ' ' && name[i - 1] != ' ')
            countWords++;
    }
    printf("\nTotal words = %d", countWords + 1);
    return 0;
}