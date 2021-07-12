#include<stdio.h>
int main()
{
    char inp[] = "Finding";
    int i, j, length, count = 0;

    for(length = 0; inp[length] != '\0'; length++);

    for(i = 0; i < length - 1; i++)
    {
        count = 0;
        if(inp[i] != -1)
        {
            for(j = i + 1; j < length; j++)
            {
                if(inp[i] == inp[j])
                {
                    inp[j] = -1;
                    count++;
                }
            }
            if(count > 0)
            {
                printf("%c for %d times\n", inp[i], count + 1);
            }
        }
    }
    return 0;
}